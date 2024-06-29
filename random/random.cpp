#include <GL/glut.h>
#include<stdlib.h>

int x, y;
float r, g, b;
void idle() {
	x = rand() % 320;
	y = rand() % 240;

	r = (float)((rand() % 9)) / 8;
	g = (float)((rand() % 9)) / 8;
	b = (float)((rand() % 9)) / 8;

	glutPostRedisplay();

}

//user define function
void display(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glColor3f(r, g, b);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

//main function
int main(int argc, char** argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Randomly generated points");
	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

