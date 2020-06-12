//
//  main.cpp
//  0527
//
//  Created by Asahi Okuyama on 2020/05/27.
//  Copyright © 2020 Asahi okuyama. All rights reserved.
//


#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

int rotation = 0;


void setup(){
    float lightPosition[4] = {5.25,2.0,0.25,1.0};
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    float ambient[4] = {0.3,0.5,0.0,1.0};
    float diffuse[4] = {1.0,1.0,0.3,1.0};
    float specular[4] = {1.0,1.0,1.0,1.0};
    float shiniess[1] = {20.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shiniess);
}

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width/height, 0.1, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 3.0, 13.0
              , 0.0, 0.0, 0.0
              , 0.0, 1.0, 0.0);
}

void idle(void){
    rotation++;
    if(rotation >= 360){
        rotation = 0;
    }
    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        glutIdleFunc(idle);
    }else{
        glutIdleFunc(0);
    }
}

void key(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
            exit(0);
            break;
        case 'c':
            rotation = 0;
            glutPostRedisplay();
        break;
            
        default:
            break;
    }
}

void display(void){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //1st teapot
    glutSolidTeapot(1);
    
    //2nd teapot
    glPushMatrix();
        glRotatef(rotation, 0.3, 1, 1);
        glTranslatef(-2, -7, 0);
        glutSolidTeapot(1);
    glPopMatrix();
    
    //3rd teapot
    glPushMatrix();
        glRotatef(rotation, 2.0, 1.0, 0.5);
        glTranslatef(4, 2.3, 0);
        glutSolidTeapot(1);
    glPopMatrix();
    
    //4th teapot
    glPushMatrix();
        glRotatef(rotation, 1.0, 1.8, 0.3);
        glTranslatef(2, -4.3, 1);
        glutSolidTeapot(1);
    glPopMatrix();
    
    //5th teapot
    glPushMatrix();
        glRotatef(rotation, 0.3, 1.0, 0.5);
        glTranslatef(1, 3.3, 0.4);
        glutSolidTeapot(1);
    glPopMatrix();
    
    //6th teapot
    glPushMatrix();
        glRotatef(rotation, 1.0, 2.0, 0.5);
        glTranslatef(5, -1.3, 0.7);
        glutSolidTeapot(2);
    glPopMatrix();
    
    glPushMatrix();
        glRotatef(rotation, 0.0, rotation, 0.0);
        glutWireTorus(1.0, 3.0, 64, 64);
    glPopMatrix();
    
    glutSwapBuffers();
//    glFlush();
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("animation tranformation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
//    glutIdleFunc(idle);
    glutMouseFunc(mouse);
    
    glutKeyboardFunc(key);
    setup();
    glutMainLoop();
    
    return 0;
}
