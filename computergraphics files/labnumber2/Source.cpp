//POINTS
#include <GL/glut.h>

// foreGroundColor RGBA(0.9294, 0.1294, 0.5333, 1.0)
// backGroundColor RGBA(0.0314, 0.0392, 0.3216, 1.0)

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

//     Draw

    glPointSize(10.0);
    glColor3f(0.9294, 0.1294, 0.5333);

    glBegin(GL_POINTS);

    glVertex2f(-0.2, 0.1);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.2, 0.4);
    glVertex2f(-0.2, 0.5);


    glVertex2f(-0.1, 0.3);
    glVertex2f(0.0, 0.3);
    glVertex2f(0.1, 0.3);


    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.2, 0.4);
    glVertex2f(0.2, 0.5);


    glEnd();


    glFlush();

}

void changeWindowColor() {
    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
}

void reShape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);


    glutInitWindowPosition(750, 0);
    glutInitWindowSize(500, 500);


    glutCreateWindow("Points");


    glutDisplayFunc(Display);
    glutReshapeFunc(reShape);

    changeWindowColor();

    glutMainLoop();
}





//
////LINE
//#include <GL/glut.h>
//
//// foreGroundColor RGBA(0.9294, 0.1294, 0.5333, 1.0)
//// backGroundColor RGBA(0.0314, 0.0392, 0.3216, 1.0)
//
//void Display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
////     Draw
//
//    glColor3f(0.9294, 0.1294, 0.5333);
//
//    glBegin(GL_LINES);
//
//    glVertex2f(-0.2, 0.0);
//    glVertex2f(-0.2, 0.6);
//
//    glVertex2f(-0.2, 0.3);
//    glVertex2f(0.2, 0.3);
//
//    glVertex2f(0.2, 0.0);
//    glVertex2f(0.2, 0.6);
//
//
//    glEnd();
//
//
//    glFlush();
//
//}
//
//void changeWindowColor() {
//    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//}
//
//void reShape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB);
//
//
//    glutInitWindowPosition(750, 0);
//    glutInitWindowSize(500, 500);
//
//
//    glutCreateWindow("Lines");
//
//
//    glutDisplayFunc(Display);
//    glutReshapeFunc(reShape);
//
//    changeWindowColor();
//
//    glutMainLoop();
//}




////TRIANGLE
//#include <GL/glut.h>
//
//// foreGroundColor RGBA(0.9294, 0.1294, 0.5333, 1.0)
//// backGroundColor RGBA(0.0314, 0.0392, 0.3216, 1.0)
//
//void Display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
//    // Draw
//
//
//    glColor3f(0.9294, 0.1294, 0.5333);
//
//    glBegin(GL_TRIANGLES);
//
//    glVertex2f(0.0, 0.3);
//    glVertex2f(-0.3, -0.3);
//    glVertex2f(0.3, -0.3);
//
//
//    glEnd();
//
//
//    glFlush();
//
//}
//
//void changeWindowColor() {
//    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//}
//
//void reShape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//}
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB);
//
//
//    glutInitWindowPosition(750, 0);
//    glutInitWindowSize(500, 500);
//
//
//    glutCreateWindow("Triangle");
//
//
//    glutDisplayFunc(Display);
//    glutReshapeFunc(reShape);
//
//    changeWindowColor();
//
//    glutMainLoop();
//}





////QUADRILATERAL
//#include <GL/glut.h>
//
// //foreGroundColor RGBA(0.9294, 0.1294, 0.5333, 1.0)
// //backGroundColor RGBA(0.0314, 0.0392, 0.3216, 1.0)
//
//void Display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
//     //Draw
//
//
//    glColor3f(0.9294, 0.1294, 0.5333);
//
//    glBegin(GL_QUADS);
//
//    glVertex2f(-0.3, -0.3); //Bottom Left
//    glVertex2f(0.3, -0.3);  //Bottom Right
//    glVertex2f(0.3, 0.3);   //Top Right
//    glVertex2f(-0.3, 0.3);  //Top Left
//
//
//    glEnd();
//
//
//    glFlush();
//
//}
//
//void changeWindowColor() {
//    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//}
//
//void reShape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//}
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB);
//
//
//    glutInitWindowPosition(750, 0);
//    glutInitWindowSize(500, 500);
//
//
//    glutCreateWindow("Quad");
//
//
//    glutDisplayFunc(Display);
//    glutReshapeFunc(reShape);
//
//    changeWindowColor();
//
//    glutMainLoop();
//}





////POLYGON
//#include <GL/glut.h>
//
// //foreGroundColor RGBA(0.9294, 0.1294, 0.5333, 1.0)
// //backGroundColor RGBA(0.0314, 0.0392, 0.3216, 1.0)
//
//void Display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
//     //Draw
//
//
//    glColor3f(0.9294, 0.1294, 0.5333);
//
//    glBegin(GL_POLYGON);
//
//    glVertex2f(-0.3, 0.3);
//    glVertex2f(0.3, 0.3);
//    glVertex2f(0.5, 0.0);
//    glVertex2f(0.3, -0.3);
//    glVertex2f(-0.3, -0.3);
//    glVertex2f(-0.5, 0.0);
//
//
//    glEnd();
//
//
//    glFlush();
//
//}
//
//void changeWindowColor() {
//    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//}
//
//void reShape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1, 1, -1, 1);
//}
//
//int main(int argc, char** argv) {
//
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB);
//
//
//    glutInitWindowPosition(750, 0);
//    glutInitWindowSize(500, 500);
//
//
//    glutCreateWindow("Polygon");
//
//
//    glutDisplayFunc(Display);
//    glutReshapeFunc(reShape);
//
//    changeWindowColor();
//
//    glutMainLoop();
//}






