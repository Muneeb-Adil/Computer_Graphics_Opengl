#include <GL/glut.h>
#include <math.h>

#define Switch_on 1
#define Switch_off 0


void display(void);

GLfloat carX = -0.2f;
GLfloat carY = -4.0f;
GLfloat posCar = 0.0;
GLfloat wheelx = -0.3;
GLfloat wheely = -2.0;
int swi = 0;

void drawRoad() {
    // Draw the road
    glColor3f(0.0, 0.2, 0.2);  // near blackish color for the road
    glBegin(GL_POLYGON);
    glVertex2f(-5.0, -3.0);
    glVertex2f(5.0, -3.0);
    glVertex2f(5.0, -5.0);
    glVertex2f(-5.0, -5.0);
    glEnd();
}

void drawFootpath() {
    // Draw the footpath on both sides of the road
    glColor3f(1.0, 1.0, 1.0);  // Light gray color for the footpath
    glLineWidth(8.0);
    glBegin(GL_LINES);
    glVertex2f(-5.0, -3.0);
    glVertex2f(5.0, -3.0);

    glVertex2f(5.0, -4.95);
    glVertex2f(-5.0, -4.95);
    glEnd();
}

void drawBuilding(float x, float width, float height) {
    // Draw a building
    glColor3f(0.6, 0.6, 0.6);  // Gray color for the building
    glBegin(GL_POLYGON);
    glVertex2f(x - width / 2, -2.90);
    glVertex2f(x + width / 2, -2.90);
    glVertex2f(x + width / 2, -2.90 + height);
    glVertex2f(x - width / 2, -2.90 + height);
    glEnd();
}

void pushCT() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
}

void popCT() {
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void carbody() {
    glColor3f(1.0, 0.0, 0.0);  // red color for the car roof
    glBegin(GL_POLYGON);
    glVertex2f(carX - 0.4, 0.0); // Left bottom
    glVertex2f(carX - 0.4, 0.2); // Left top
    glVertex2f(0.4, 0.2);  // Right top
    glVertex2f(0.4, 0.0);  // Right bottom
    glEnd();
}

void carroof() {
    glColor3f(0.0, 0.0, 1.0);  // Blue color for the car roof
    glBegin(GL_POLYGON);
    glVertex2f(carX - 0.3, 0.2); // Left top
    glVertex2f(carX - 0.2, 0.4); // Front left
    glVertex2f(0.2, 0.4);  // Front right
    glVertex2f(0.3, 0.2);  // Right top
    glEnd();
}

void carwheel() {
    glColor3f(1.0, 1.0, 1.0);  // white color for the wheels
    float wheelRadius = 0.1;
    int numSpokes = 12;
    for (int i = -1; i <= 1; i += 2) {
        glBegin(GL_POLYGON);
        for (int j = 0; j < numSpokes; j++) {
            float angle = 2.0 * 3.14159265 * j / numSpokes;
            float x = i * wheelx + wheelRadius * cos(angle);
            float y = wheely + wheelRadius * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
}

void drawCar() {
    // Draw car body
    pushCT();
    glTranslated(carX, carY, 0);
    carbody();
    popCT();

    // Draw car roof
    pushCT();
    glTranslated(carX - 0.1, carY, 0);
    carroof();
    popCT();

    // Draw car wheel
    pushCT();
    glTranslated(wheelx, wheely, 0);
    carwheel();
    popCT();

}

void myKB_Handler_callback(int key, int mx, int my) {
    if (swi == 1) {
        switch (key)
        {
        case GLUT_KEY_RIGHT:
            posCar += 1;
            break;

        case GLUT_KEY_LEFT:
            posCar -= 1;
            break;

        default:
            break;
        }
        glutPostRedisplay();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawRoad();
    drawFootpath();

    // Draw buildings
    drawBuilding(-4.0, 1.0, 5.0);
    drawBuilding(-2.0, 1.0, 4.0);
    drawBuilding(0.0, 1.0, 3.0);
    drawBuilding(2.0, 1.0, 6.0);
    drawBuilding(4.0, 1.0, 4.0);

    glPushMatrix();
    glTranslatef(posCar, 0.0, 0.0);  // Translate the car's position
    drawCar();
    glPopMatrix();

    glFlush();
}

void myInit(void)
{
    glClearColor(0.0, 0.50, 0.70, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
}

void processMenuEvents(int option) {

    //mouse choice chooses
    if (option == 0) {
        swi = 0;
    }
    else if (option == 1) {
        swi = 1;
    }

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Hierarchical Modeling");

    glutDisplayFunc(display);
    glutSpecialFunc(myKB_Handler_callback);
    myInit();

    glutCreateMenu(processMenuEvents);

    glutAddMenuEntry("Push start", Switch_on);

    glutAddMenuEntry("Push off", Switch_off);

    glutAddMenuEntry("Exit", 101);


    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
