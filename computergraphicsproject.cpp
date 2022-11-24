
// 2d rotation of wheel ,
// by group no. 30

#include <windows.h>
#include<iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <cmath>
#include<stdio.h>


const double PI = 3.141592654;
int NoOfFrames = 0;
void MakeRoad() ;
void MakeWheel();
void init() ;
void Display();


void CreateDisk(double radius) { // creates a disk of provided radius
	glBegin(GL_POLYGON);
	for (int i = 0; i < 32; i++) {
		double angle = 2 * PI / 32 * i;
		glVertex2d(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
}


void DoFrame(int v) {
	NoOfFrames++;
	glutPostRedisplay();
	glutTimerFunc(30, DoFrame, 0);
}

int main(int argc, char** argv) {  // main function
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Rotation of Wheel : By Group 30");
	init();
	glutDisplayFunc(Display);
	glutTimerFunc(200, DoFrame, 0);
	glutMainLoop();
	return 0;
}



void MakeRoad(){      // creates background road
    glBegin(GL_QUADS); //  road
    glColor3ub(61, 60, 60);
    glVertex2f(-0.99f, -0.99f);
    glVertex2f(8, -0.99f);
    glVertex2f(8, 1.5);
    glVertex2f(-0.99f, 1.5);

    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(-0.99f, 0.5);
    glVertex2f(1.5, 0.5);
    glVertex2f(1.5, 0.7);
    glVertex2f(-0.99f, 0.7);
    glEnd();

     glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(5, 0.5);
    glVertex2f(2.5, 0.5);
    glVertex2f(2.5, 0.7);
    glVertex2f(5, 0.7);
    glEnd();

    glBegin(GL_QUADS); //  road white line
    glColor3ub(255, 255, 255);
    glVertex2f(8, 0.5);
    glVertex2f(5.5, 0.5);
    glVertex2f(8, 0.7);
    glVertex2f(5.5 , 0.7);
    glEnd();
}


void MakeWheel() {     // makes the wheel figure using above createDisk function
	glColor3f(0, 0, 0);
	CreateDisk(1.5);
	glColor3f(0.75f, 0.75f, 0.75f);
	CreateDisk(0.8);
	glColor3f(0, 0, 0);
	CreateDisk(0.3);
	glRotatef(NoOfFrames * 20, 0, 0, 1);
	glBegin(GL_LINES);
	for (int i = 0; i < 15; i++) {
		glVertex2f(0, 0);
		glVertex2d(cos(i * 2 * PI / 15), sin(i * 2 * PI / 15));
	}
	glEnd();
}


void Display() {     // Displays on screen
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
    MakeRoad();
	glPushMatrix();
	glTranslated(3.5, 2, 0);
	glRotated(-NoOfFrames * 0.65, 0, 0, 1);
	MakeWheel();
	glPopMatrix();
	glutSwapBuffers();
}



void init() {   //init function for initializing
	glClearColor(255, 255, 255, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

