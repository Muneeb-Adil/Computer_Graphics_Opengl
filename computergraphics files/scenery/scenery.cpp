#include <gl/glut.h>
#include <Windows.h>

void myInit(void)
{
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(300, 300);
	glColor3f(34 / 255, 64 / 255, 23 / 255);
	glVertex2i(500, 300);
	glColor3f(34 / 255, 64 / 255, 30 / 255);
	glVertex2i(400, 400);
	glEnd();
	//lower tri
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(300, 300);
	glVertex2i(300, 100);
	glVertex2i(499, 110);
	glColor3f(34 / 255, 64 / 255, 23 / 255);
	glVertex2i(500, 300);
	glVertex2i(300, 300);
	glEnd();
	//door
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(340, 105);
	glColor3f(34 / 255, 64 / 255, 23 / 255);
	glVertex2i(340, 250);
	glVertex2i(460, 250);
	glColor3f(34 / 255, 64 / 255, 23 / 255);
	glVertex2i(460, 110);
	glColor3f(245 / 255, 255 / 255, 255 / 255);
	//glVertex2i(300,300);
	glEnd();
	//upper tri
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(300, 300);
	glVertex2i(100, 300);
	glColor3f(149 / 255, 74 / 255, 0 / 255);
	glVertex2i(200, 400);
	glVertex2i(400, 400);
	glEnd();
	//body house
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(100, 300);
	glColor3f(34 / 255, 64 / 255, 23 / 255);
	glVertex2i(100, 130);
	glVertex2i(300, 100);
	glVertex2i(300, 300);
	glEnd();
	//window 1
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(150, 175);
	glVertex2i(150, 240);
	glVertex2i(200, 240);
	//glColor3f(34/255,64/255,23/255);
	glVertex2i(200, 170);
	glEnd();
	//window 2
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(200, 170);
	glVertex2i(200, 240);
	glVertex2i(250, 240);
	glVertex2i(250, 164);
	glEnd();
	//chimni
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2i(220, 400);
	glColor3f(34 / 255, 64 / 255, 23 / 255);
	glVertex2i(220, 450);
	glVertex2i(250, 450);
	glVertex2i(250, 400);
	glEnd();
	glFlush();
}



int main(int argc, CHAR** argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Muneeb Adil");
	glutInitWindowPosition(100, 150);
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();

	return 0;
}





