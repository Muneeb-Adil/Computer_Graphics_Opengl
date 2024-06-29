/*
This is a program which displays several primitives as well as animates objects.
Your task is to make the plane that makes a crash landing, but unlike the movies,
it doesn't burst into flames.The background contains a triangle for windmill.
You need to complete it using transformation then make it animate*/

#include <GL/glut.h>
#include<cstdlib>
#define PI 3.141592
float rotationAngle = 0.0f;

void display(void); // draw everything
void drawWind(void);  // draw single blade 
void drawwindmill(void); //complete this to complete windmill i.e. call drawWind() in it
void drawplane();  // work in this function
//  for crash landing of plane i.e. animate and collision with land 

void drawlandscape();// do nothing with it 
void Timer(int value); // update varible for animation here

void keyboard(unsigned char key, int x, int y);
void init(void);
void reshape(GLsizei w, GLsizei h);




void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawlandscape();
	drawplane();
	drawwindmill();


	glutSwapBuffers();


}


void drawWind() // single Triangle
{

	glBegin(GL_TRIANGLES);

	glColor3f(0.8, 0.8, 0.8);
	glVertex2f(125.0, 90.0);
	glVertex2f(140.0, 120.0);
	glVertex2f(160.0, 120.0);
	glEnd();

}

void drawwindmill()   // complete windmill in this body
{
	glPushMatrix();
	glTranslatef(125.0f, 100.0f, 0.0f);
	glRotatef(rotationAngle, 0, 0, 1.0);
	glTranslatef(-125.0f,-100.0f, 0.0f);
	drawWind();
	for (int i = 0; i < 4; i++) {
		glPushMatrix();
		glTranslatef(125.0f, 100.0f, 0.0f); // Translate to the center of the windmill
		glRotatef(i * 90,0.0f, 0.0f, 1.0f); // Rotate each blade
		glTranslatef(-125.0f, -100.0f, 0.0f); // Translate back to the original position
		drawWind();
		glPopMatrix();
	}



	glPopMatrix();
}



void Timer(int value) // work in this function after completing windmill to animate it
{
	//update variables here
	rotationAngle += 1;
	if (rotationAngle >= 360) {
		rotationAngle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(30, Timer, 1);
}


void drawplane()// work in this function to animate and crash plane
{
	/* Draw a plane */

	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(245.0, 230.0);
	glVertex2f(245.0, 240.0);
	glVertex2f(215.0, 230.0);

	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(244.0, 228.0);
	glVertex2f(244.0, 235.0);
	glVertex2f(228.0, 235.0);

	glEnd();


}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("BSCS 514 Lab #8");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(0, Timer, 1);
	glutMainLoop();
}



void drawlandscape()
{
	/* Draw a box of grass */
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(250.0, 0.0);
	glColor3f(0.0, 0.9, 0.0);
	glVertex2f(250.0, 50.0);
	glColor3f(0.0, 0.8, 0.0);
	glVertex2f(0.0, 50.0);
	glColor3f(0.0, 0.7, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();

	/* An attempt at a few snow covered mountains */

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(250.0, 50.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(200.0, 150.0);
	glColor3f(0.0, 0.0, 0.5);
	glVertex2f(150.0, 50.0);

	//glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.5);
	glVertex2f(200.0, 50.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(150.0, 150.0);
	glColor3f(0.0, 0.0, 0.5);
	glVertex2f(100.0, 50.0);

	glColor3f(0.0, 0.0, 0.7);
	glVertex2f(150.0, 50.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(100.0, 150.0);
	glColor3f(0.0, 0.0, 0.5);
	glVertex2f(50.0, 50.0);

	glColor3f(0.0, 0.0, 0.5);
	glVertex2f(100.0, 50.0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(50.0, 150.0);
	glColor3f(0.0, 0.0, 0.5);
	glVertex2f(0.0, 50.0);

	glEnd();

	/* Draw the body of a windmill */
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.0);
	glVertex2f(145.0, 50.0);
	glVertex2f(135.0, 100.0);
	glVertex2f(115.0, 100.0);
	glVertex2f(105.0, 50.0);
	glEnd();

}

void init()
{
	glClearColor(0.8f, 0.8f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 250.0, 0.0, 250.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}





void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	}
}




//
////ROTATION
//#include <GL/glut.h>
//
//float rotationAngle = 0.0f; // Initial rotation angle
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Push the current transformation matrix onto the stack
//    glPushMatrix();
//
//    // Apply a rotation transformation
//    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f); // Rotate around the z-axis
//
//    // Draw the rotated triangle
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.0, 0.0, 0.0);  // Red color
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5);
//    glVertex2f(0.0, 0.5);
//    glEnd();
//
//    // Pop the previous transformation matrix from the stack
//    glPopMatrix();
//
//    glutSwapBuffers();
//}
//
//void timer(int value)
//{
//    // Update the rotation angle
//    rotationAngle += 1.0f; // Adjust the rotation speed as needed
//
//    // Ensure the angle stays within 360 degrees
//    if (rotationAngle >= 360.0f)
//        rotationAngle -= 360.0f;
//
//    glutPostRedisplay();
//    glutTimerFunc(30, timer, 1);
//}
//
//void init()
//{
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // White background
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);  // Set the coordinate system
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("Rotation Example");
//    init();
//    glutDisplayFunc(display);
//    glutTimerFunc(0, timer, 0);
//    glutMainLoop();
//
//    return 0;
//}




////TRANSLATION
//#include <GL/glut.h>
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Draw the original object
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.0, 0.0, 0.0);  // Red color
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5);
//    glVertex2f(0.0, 0.5);
//    glEnd();
//
//    // Push the current transformation matrix onto the stack
//    glPushMatrix();
//
//    // Apply a translation transformation
//    glTranslatef(1.0, 0.0, 0.0);
//
//    // Draw the translated object
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.0, 0.0, 1.0);  // Blue color
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5);
//    glVertex2f(0.0, 0.5);
//    glEnd();
//
//    // Pop the previous transformation matrix from the stack
//    glPopMatrix();
//
//    glutSwapBuffers();
//}
//
//void init()
//{
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // White background
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);  // Set the coordinate system
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("Push and Pop Matrix Example");
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}


////SCALING
//#include <gL/glut.h>
//#include <cstdlib>
//
//float scaleValue = 1.0f; // Initial scaling factor
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Apply the scaling transformation
//    glScalef(scaleValue, scaleValue, 1.0f);
//
//    // Draw a square
//    glBegin(GL_QUADS);
//    glColor3f(1.0, 0.0, 0.0); // Red color
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5);
//    glVertex2f(0.5, 0.5);
//    glVertex2f(-0.5, 0.5);
//    glEnd();
//
//    glutSwapBuffers();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//    switch (key)
//    {
//    case 's': // Scale up
//        scaleValue *= 1.2; // Increase the scale factor
//        break;
//    case 'S': // Scale down
//        scaleValue /= 1.2; // Decrease the scale factor
//        break;
//    case 27: // Escape key to exit
//        exit(0);
//        break;
//    }
//
//    glutPostRedisplay(); // Trigger a redraw
//}
//
//void init()
//{
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-2.0, 2.0, -2.0, 2.0); // Set the coordinate system
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("Scaling Example");
//    init();
//    glutDisplayFunc(display);
//    glutKeyboardFunc(keyboard);
//    glutMainLoop();
//
//    return 0;
//}

