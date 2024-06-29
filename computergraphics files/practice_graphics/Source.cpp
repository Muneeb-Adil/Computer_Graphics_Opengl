////POINTS ON SCREEN
//#include <gL/glut.h>
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glPointSize(5);
//
//    //blue
//    glColor3f(0, 0, 1);
//    glBegin(GL_POINTS);
//    glVertex2i(0, 0);
//    glVertex2f(-3.9, -3.9);
//    glVertex2f(-3.9, 3.9);
//    glVertex2f(3.9, -3.9);
//    glVertex2f(3.9, 3.9);
//    glEnd();
//
//
//    
//    glColor3f(0, 1, 0); // Green
//    glBegin(GL_POINTS);
//    glVertex2i(-2, -2);  
//    glVertex2i(-2, 2);   
//    glVertex2i(2, 2);    
//    glVertex2i(2, -2);   
//    glEnd();
//
//
//    glColor3f(1, 0, 0); // Red
//    glBegin(GL_POINTS);
//    glVertex2i(-3, -3);  
//    glVertex2i(-3, 3);   
//    glVertex2i(3, 3);    
//    glVertex2i(3, -3);  
//    glEnd();
//
//    //Points inside worldwindow but outside viewport
//    glColor3f(1, 1, 1);
//    glBegin(GL_POINTS);
//    glVertex2i(50, 50);
//    glEnd();
//
//
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(400, 400);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("My Drawing");
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//
//    gluOrtho2D(-4, 4, -4, 4);  // World window
//    glViewport(0, 0, 100,100 ); // Viewport (smaller than window)
//
//    glutDisplayFunc(display);
//    glutMainLoop();
//}



////TRIANGLE ASSIGNMENT QUESTION
#/*include<GL/glut.h>
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(0, 1);
	glVertex2i(3, 1);
	glVertex2i(3, 2);
	glEnd();
	glFlush();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Assignment Question");
	glClearColor(0, 0, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(1.5,4.5,0,3);
	glViewport(100,-300,600,400);
	glutDisplayFunc(display);
	glutMainLoop();
}*/



