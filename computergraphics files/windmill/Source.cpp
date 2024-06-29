//#include <GL/glut.h>
//#include <cstdlib>
//#include<iostream>
//using namespace std;
//
//void display(void); // draw everything
//void drawWind(void);  // draw single blade 
//void drawwindmill(void); // complete this to complete windmill i.e. call drawWind() in it
//void drawplane();  // work in this function
////  for crash landing of plane i.e. animate and collision with land 
//
//void drawlandscape();// do nothing with it 
//void Timer(int value); // update variable for animation here
//
//void keyboard(unsigned char key, int x, int y);
//void init(void);
//void reshape(GLsizei w, GLsizei h);
//
//// Add these variables
//GLfloat planeX = 245.0f;
//GLfloat planeY = 230.0f;
//GLfloat planeVelocityY = -0.7f;
//GLfloat planeVelocityX = -0.3f;
//GLfloat windmillRotation = 0.0f; // Rotation angle for windmill blades
//
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    drawlandscape();
//    drawplane();
//    drawwindmill();
//
//    glutSwapBuffers();
//}
//
//void drawWind() // single Triangle
//{
//    glBegin(GL_TRIANGLES);
//
//    glColor3f(0.8, 0.8, 0.8);
//    glVertex2f(125.0, 90.0);
//    glVertex2f(140.0, 120.0);
//    glVertex2f(160.0, 120.0);
//    glEnd();
//}
//
//void drawwindmill()   // complete windmill in this body
//{
//    glPushMatrix(); // Save the current matrix
//    glTranslatef(130.0f, 100.0f, 0.0f); // Translate to the center of the windmill
//    glRotatef(windmillRotation, 0.0f, 0.0f, 1.0f); // Rotate all blades together
//    glTranslatef(-130.0f, -100.0f, 0.0f); // Translate back to the original position
//
//    for (int i = 0; i < 4; i++) {
//        glPushMatrix();
//        glTranslatef(130.0f, 100.0f, 0.0f); // Translate to the center of the windmill
//        glRotatef(i * 90, 0.0f, 0.0f, 1.0f); // Rotate each blade
//        glTranslatef(-130.0f, -100.0f, 0.0f); // Translate back to the original position
//        drawWind();
//        glPopMatrix();
//    }
//
//    glPopMatrix(); // Restore the saved matrix
//}
//
//void Timer(int value) // work in this function after completing windmill to animate it
//{
//    // Update variables here
//    if (planeX >= 10) {
//        if (planeY > 150) {
//            planeY += planeVelocityY;
//            planeX += planeVelocityX;
//        }
//        if (planeY <= 150) {
//            if (planeY > 50) {
//                planeY -= 25;
//            }
//            if (planeY <= 50) {
//                if (planeX <= 215 && planeX >= 150) {
//                    planeX += -1.5;
//                }
//                if (planeX <= 150 && planeX >= 140) {
//                    planeX += -1;
//                }
//                if (planeX <= 140 && planeX >= 130) {
//                    planeX += -0.8;
//                }
//                if (planeX <= 130 && planeX >= 120) {
//                    planeX += -0.6;
//                }
//                if (planeX <= 120 && planeX >= 110) {
//                    planeX += -0.4;
//                }
//                if (planeX <= 110 && planeX >= 105) {
//                    planeX += -0.2;
//                }
//                if (planeX <= 105 && planeX >= 100) {
//                    planeX += -0.1;
//                }
//                
//            }
//        }
//    }
//    windmillRotation += 2.0f; // Rotate windmill blades
//
//    if (windmillRotation > 360.0f) {
//        windmillRotation -= 360.0f;
//    }
//    display();
//    glutTimerFunc(30, Timer, 1);
//}
//
//void drawplane()// work in this function to animate and crash plane
//{
//    /* Draw a plane */
//
//    glBegin(GL_TRIANGLES);
// 
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2f(planeX, planeY);
//    glVertex2f(planeX, planeY + 10.0f);
//    glVertex2f(planeX - 30.0f, planeY);
//
//    glColor3f(0.2, 0.2, 0.2);
//    glVertex2f(planeX - 1.0f, planeY - 2.0f);
//    glVertex2f(planeX - 1.0f, planeY + 5.0f);
//    glVertex2f(planeX - 17.0f, planeY + 5.0f);
//
//    glEnd();
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowPosition(50, 50);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("WINDMILL");
//    init();
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutKeyboardFunc(keyboard);
//
//    // Start the animation timer
//    glutTimerFunc(0, Timer, 1);
//
//    glutMainLoop();
//    return 0;
//}
//
//void drawlandscape()
//{
//    /* Draw a box of grass */
//    glBegin(GL_QUADS);
//    glColor3f(0.0, 1.0, 0.0);
//    glVertex2f(250.0, 0.0);
//    glColor3f(0.0, 0.9, 0.0);
//    glVertex2f(250.0, 50.0);
//    glColor3f(0.0, 0.8, 0.0);
//    glVertex2f(0.0, 50.0);
//    glColor3f(0.0, 0.7, 0.0);
//    glVertex2f(0.0, 0.0);
//    glEnd();
//
//    /* An attempt at a few snow-covered mountains */
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.0, 0.0, 0.6);
//    glVertex2f(250.0, 50.0);
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2f(200.0, 150.0);
//    glColor3f(0.0, 0.0, 0.5);
//    glVertex2f(150.0, 50.0);
//
//    //glBegin(GL_TRIANGLES);
//    glColor3f(0.0, 0.0, 0.5);
//    glVertex2f(200.0, 50.0);
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2f(150.0, 150.0);
//    glColor3f(0.0, 0.0, 0.5);
//    glVertex2f(100.0, 50.0);
//
//    glColor3f(0.0, 0.0, 0.7);
//    glVertex2f(150.0, 50.0);
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2f(100.0, 150.0);
//    glColor3f(0.0, 0.0, 0.5);
//    glVertex2f(50.0, 50.0);
//
//    glColor3f(0.0, 0.0, 0.5);
//    glVertex2f(100.0, 50.0);
//    glColor3f(1.0, 1.0, 1.0);
//    glVertex2f(50.0, 150.0);
//    glColor3f(0.0, 0.0, 0.5);
//    glVertex2f(0.0, 50.0);
//    glEnd();
//
//    /* Draw the body of a windmill */
//    glBegin(GL_QUADS);
//    glColor3f(0.6, 0.6, 0.0);
//    glVertex2f(145.0, 50.0);
//    glVertex2f(135.0, 100.0);
//    glVertex2f(115.0, 100.0);
//    glVertex2f(105.0, 50.0);
//    glEnd();
//}
//
//void init()
//{
//    glClearColor(0.8f, 0.8f, 1.0f, 1.0f);
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, 250.0, 0.0, 250.0);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//void reshape(GLsizei w, GLsizei h)
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, 250.0, 0.0, 250.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//    switch (key)
//    {
//    case 27:
//        exit(0);
//        break;
//    }
//}





