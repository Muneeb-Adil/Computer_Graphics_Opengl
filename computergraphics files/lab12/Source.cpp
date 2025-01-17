#include <iostream>
#include <GL/glut.h>
#include <cmath>

void tooth0() {
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.6, 0.8);
    glVertex2f(0.2, 0.8);
    glVertex2f(0, 1);
    glEnd();
}

void tooth1(double r) {
    double rad = 6.0 * 3.142 / 180.0;
    double sin6 = r * sin(rad), cos6 = r * cos(rad);
    glPushMatrix();
    glTranslatef(cos6, -sin6, 0.0);
    glScalef(2.0 * sin6, 2.0 * sin6, 1.0);
    tooth0();
    glPopMatrix();
}

void drawCircle(float radius, int segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        float theta = 2.0f * 3.14159265359f * float(i) / float(segments);
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
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

void drawAxes() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-6.0f, 0.0f);
    glVertex2f(6.0f, 0.0f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 6.0f);
    glVertex2f(0.0f, -6.0f);
    glEnd();
}
void move() {
    float speed = 0.0001;

}
void writeName(){
// Drawing text as my name
const char* text = "Muneeb Adil";
float textX = 1.0; // X-coordinate for the text position
float textY = 4.0; // Y-coordinate for the text position

glColor3f(0.0, 1.0, 0.0); // Set text color to white
glRasterPos2f(textX, textY);

// Loop through each character in the text and display it
for (int i = 0; text[i] != '\0'; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
}

glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glViewport(-1, 1, -1, 1);
    //tooth0();
    //tooth1(3);
    //gear(3);
    /*
    drawCircle(0.5f, 36);
    drawAxes();
    writeName();*/

    glFlush();
}

void init() {
    glEnable(GL_COLOR_MATERIAL);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6,   -6, 6);
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