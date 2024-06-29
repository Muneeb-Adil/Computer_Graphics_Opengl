//
//////5.5.1 star
////#include<GL/glut.h>
////#include<cstdlib>
////void starMotif() {
////	glColor3f(1, 0, 1);
////	glBegin(GL_LINE_STRIP);
////	glVertex2i(3,3);
////	glVertex2i(0,8);
////	glVertex2i(-3,0);
////	glVertex2i(-2,-1);
////	glVertex2i(0,5);
////	glVertex2i(2,3);
////	glVertex2i(3,3);
////	glEnd();
////}
////void display() {
////	glClear(GL_COLOR_BUFFER_BIT);
////	for (int count = 0;count < 5;count++) {
////		starMotif();
////		glTranslatef(1, 0, 0);
////		glRotatef(72,0,0,1);
////	}
////
////	glutSwapBuffers();
////
////}
////int main(int argc, char** argv) {
////	glutInit(&argc, argv);
////	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
////	glutInitWindowSize(400, 400);
////	glutInitWindowPosition(100, 100);
////	glutCreateWindow("CASE STUDIES");
////	glClearColor(0, 1, 1, 1);
////	glMatrixMode(GL_PROJECTION);
////	glLoadIdentity();
////	gluOrtho2D(-10, 10, -10, 10);
////	glutDisplayFunc(display);
////	glutMainLoop();
////}
//
//
//
//
//
//////5.5.2 snowflake
////#include<gl/glut.h>
////void flakeMotif() {
////	glColor3f(0, 0, 0);
////	glBegin(GL_LINE_STRIP);
////	glVertex2i(0, 2);
////	glVertex2i(20,2);
////	glVertex2i(30, 15);
////	glVertex2i(35,13);
////	glVertex2i(25, 2);
////	glVertex2i(30, 2);
////	glVertex2i(45, 15);
////	glVertex2i(50, 13);
////	glVertex2i(35, 2);
////	glVertex2i(55, 2);
////	glVertex2i(60, 0);
////	glEnd();
////}
////
////void display() {
////	glClear(GL_COLOR_BUFFER_BIT);
////    for (int count = 0;count < 6;count++) {
////		flakeMotif();
////		glScalef(1, -1, 1);
////		flakeMotif();
////		glScalef(1, -1, 1);
////		glRotatef(60, 0, 0, 1);
////	}
////	glutSwapBuffers();
////}
////int main(int argc, char** argv) {
////		glutInit(&argc, argv);
////		glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
////		glutInitWindowSize(400, 400);
////		glutInitWindowPosition(100, 100);
////		glutCreateWindow("CASE STUDIES");
////		glClearColor(1, 0, 0, 1);
////		glMatrixMode(GL_PROJECTION);
////		glLoadIdentity();
////		gluOrtho2D(-100, 100, -100, 100);
////		glutDisplayFunc(display);
////		glutMainLoop();
////	}
//
//
//
//


#include <gl/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
void drawPolyLineFile(string fileName)
{
	fstream inStream;

	inStream.open(fileName, ios::in);	// open the file

	if (inStream.fail())
	{
		cout << "can't open it!";return;
	}



	GLfloat numpolys, numPoints, x, y;
	inStream >> numpolys;		           // read the number of polylines

	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numPoints;       //number of points in first PolyLine  
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numPoints; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2f(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}


void tooth1(double r) {
	double rad = 6.0 * 3.142 / 180.0;
	double sin6 = r * sin(rad), cos6 = r * cos(rad);
	glPushMatrix();
	glTranslatef(cos6, -sin6, 0.0);
	glScalef(2.0 * sin6, 2.0 * sin6, 1.0);
    drawPolyLineFile("dino.dat");
	glPopMatrix();
}





void gear(double r) {
    glPushMatrix();
    for (int i = 1; i <= 30; i++)
    {
        tooth1(r);
        glRotatef(12.0, 0.0, 0, 1);
    }
    glPopMatrix();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glViewport(-1, 1, -1, 1);
    gear(3);
    glFlush();
}

void init() {
    glEnable(GL_COLOR_MATERIAL);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(200, 100);

    glutCreateWindow("Window Shapes");
    glutDisplayFunc(display);
    init();
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
