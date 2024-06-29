//#include <GL/glut.h>
//#include<stdlib.h>
//
//int x, y;
//float r, g, b;
//void idle() {
//	x = rand() % 320;
//	y = rand() % 240;
//
//	r = (float)((rand() % 9)) / 8;
//	g = (float)((rand() % 9)) / 8;
//	b = (float)((rand() % 9)) / 8;
//
//	glutPostRedisplay();
//
//}
//
////user define function
//void display(void)
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//	glColor3f(r, g, b);
//	glPointSize(3);
//	glBegin(GL_POINTS);
//	glVertex2i(x, y);
//	glEnd();
//	glFlush();
//}
//
////main function
//int main(int argc, char** argv)
//
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(640, 480);
//	glutCreateWindow("Randomly generated points");
//	glClearColor(0, 0, 0, 0);
//	glutDisplayFunc(display);
//	glutIdleFunc(idle);
//	glutMainLoop();
//	return 0;
//}

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>
#include <cstdio>

// Game Speed
int FPS = 20;
// Game Track
int start = 0;
int gv = 0;
int level = 0;
// Track Score
int score = 0;
// Form move track
int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;
// For Car Left / RIGHT
int lrIndex = 0;
// Car Coming
int car1 = 0;
int lrIndex1 = 0;
int car2 = +35;
int lrIndex2 = 0;
int car3 = +70;
int lrIndex3 = 0;

void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void tree(int x, int y) {
    int newx = x;
    int newy = y;
    // Tree Left - Bottom
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(newx + 11, newy + 55);
    glVertex2f(newx + 12, newy + 55 - 10);
    glVertex2f(newx + 10, newy + 55 - 10);
    glEnd();
    // Tree Left - Up
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(newx + 11, newy + 55 + 3);
    glVertex2f(newx + 12 + 3, newy + 55 - 3);
    glVertex2f(newx + 10 - 3, newy + 55 - 3);
    glEnd();
}

void startGame() {
    // Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();
    // Road Left Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(23, 100);
    glVertex2f(23, 0);
    glEnd();
    // Road Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(77, 0);
    glVertex2f(77, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();
    // Road Middle Border - TOP
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivTop + 80);
    glVertex2f(48, roadDivTop + 100);
    glVertex2f(52, roadDivTop + 100);
    glVertex2f(52, roadDivTop + 80);
    glEnd();
    roadDivTop--;
    if (roadDivTop < -100) {
        roadDivTop = 20;
        score++;
    }
    // Middle
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivMdl + 40);
    glVertex2f(48, roadDivMdl + 60);
    glVertex2f(52, roadDivMdl + 60);
    glVertex2f(52, roadDivMdl + 40);
    glEnd();
    roadDivMdl--;
    if (roadDivMdl < -60) {
        roadDivMdl = 60;
        score++;
    }
    // Bottom
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivBtm + 0);
    glVertex2f(48, roadDivBtm + 20);
    glVertex2f(52, roadDivBtm + 20);
    glVertex2f(52, roadDivBtm + 0);
    glEnd();
    roadDivBtm--;
    if (roadDivBtm < -20) {
        roadDivBtm = 100;
        score++;
    }
    // Score Board
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(80, 97);
    glVertex2f(100, 97);
    glVertex2f(100, 98 - 8);
    glVertex2f(80, 98 - 8);
    glEnd();
    // Print Score
    char buffer[50];
    sprintf(buffer, "SCORE: %d", score);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95, GLUT_BITMAP_8_BY_13, buffer);
    // Speed Print
    char buffer1[50];
    sprintf(buffer1, "SPEED:%dKm/h", FPS);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95 - 2, GLUT_BITMAP_8_BY_13, buffer1);
    // Level Print
    if (score % 50 == 0) {
        int last = score / 50;
        if (last != level) {
            level = score / 50;
            FPS = FPS + 2;
        }
    }
    char level_buffer[50];
    sprintf(level_buffer, "LEVEL: %d", level);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95 - 4, GLUT_BITMAP_8_BY_13, level_buffer);
    // Increase Speed With level
    // MAIN car
    // Front Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 5);
    glVertex2f(lrIndex + 26 - 2, 7);
    glVertex2f(lrIndex + 30 + 2, 7);
    glVertex2f(lrIndex + 30 + 2, 5);
    glEnd();
    // Back Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 3);
    glVertex2f(lrIndex + 26 - 2, 5);
    glVertex2f(lrIndex + 30 + 2, 5);
    glVertex2f(lrIndex + 30 + 2, 3);
    glEnd();
    // car Body
    glColor3f(0.000, 0.000, 0.698);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26, 3);
    glVertex2f(lrIndex + 26, 7);
    glVertex2f(lrIndex + 30, 13);
    glVertex2f(lrIndex + 34, 7);
    glVertex2f(lrIndex + 34, 3);
    glEnd();
    lrIndex = lrIndex + car1;
    // Other car
    if (gv == 1) {
        // Car 1
        // Front Tire
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        glVertex2f(lrIndex1 + 6 - 2, car2 + 12);
        glVertex2f(lrIndex1 + 6 - 2, car2 + 14);
        glVertex2f(lrIndex1 + 10 + 2, car2 + 14);
        glVertex2f(lrIndex1 + 10 + 2, car2 + 12);
        glEnd();
        // Back Tire
        glColor3f(0.000, 0.000, 0.000);
        glBegin(GL_POLYGON);
        glVertex2f(lrIndex1 + 6 - 2, car2 + 10);
        glVertex2f(lrIndex1 + 6 - 2, car2 + 12);
        glVertex2f(lrIndex1 + 10 + 2, car2 + 12);
        glVertex2f(lrIndex1 + 10 + 2, car2 + 10);
        glEnd();
        // car Body
        glColor3f(0.545, 0.000, 0.000);
        glBegin(GL_POLYGON);
        glVertex2f(lrIndex1 + 6, car2 + 10);
        glVertex2f(lrIndex1 + 6, car2 + 14);
        glVertex2f(lrIndex1 + 10, car2 + 20);
        glVertex2f(lrIndex1 + 14, car2 + 14);
        glVertex2f(lrIndex1 + 14, car2 + 10);
        glEnd();
        car2 = car2 - 1;
        if (car2 < -15) {
            car2 = 105;
            int random = rand() % 3;
            if (random == 0) {
                lrIndex1 = 0;
            }
            else if (random == 1) {
                lrIndex1 = 25;
            }
            else {
                lrIndex1 = 50;
            }
        }
    }
    // Car 2
    // Front Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26 - 2, car3 + 12);
    glVertex2f(lrIndex2 + 26 - 2, car3 + 14);
    glVertex2f(lrIndex2 + 30 + 2, car3 + 14);
    glVertex2f(lrIndex2 + 30 + 2, car3 + 12);
    glEnd();
    // Back Tire
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26 - 2, car3 + 10);
    glVertex2f(lrIndex2 + 26 - 2, car3 + 12);
    glVertex2f(lrIndex2 + 30 + 2, car3 + 12);
    glVertex2f(lrIndex2 + 30 + 2, car3 + 10);
    glEnd();
    // car Body
    glColor3f(0.545, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26, car3 + 10);
    glVertex2f(lrIndex2 + 26, car3 + 20);
    glVertex2f(lrIndex2 + 30, car3 + 26);
    glVertex2f(lrIndex2 + 34, car3 + 20);
    glVertex2f(lrIndex2 + 34, car3 + 10);
    glEnd();
    car3 = car3 - 1;
    if (car3 < -15) {
        car3 = 105;
        int random = rand() % 3;
        if (random == 0) {
            lrIndex2 = 0;
        }
        else if (random == 1) {
            lrIndex2 = 25;
        }
        else {
            lrIndex2 = 50;
        }
    }
    // Collisions
    if ((car1 + lrIndex > 73) || (car1 + lrIndex < 21 && ((lrIndex + 30 > lrIndex1 && lrIndex + 30 < lrIndex1 + 4) || (lrIndex + 26 < lrIndex1 + 10 && lrIndex + 26 > lrIndex1))) || (car1 + lrIndex < 21)) {
        gv = 1;
    }
}

// For Display TEXT
void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void fristDesign() {
    // Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();
    // Road Left Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(23, 100);
    glVertex2f(23, 0);
    glEnd();
    // Road Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(77, 0);
    glVertex2f(77, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();
    // Road Middle Border - TOP
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivTop + 80);
    glVertex2f(48, roadDivTop + 100);
    glVertex2f(52, roadDivTop + 100);
    glVertex2f(52, roadDivTop + 80);
    glEnd();
    // Middle
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivMdl + 40);
    glVertex2f(48, roadDivMdl + 60);
    glVertex2f(52, roadDivMdl + 60);
    glVertex2f(52, roadDivMdl + 40);
    glEnd();
    // Bottom
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, roadDivBtm + 0);
    glVertex2f(48, roadDivBtm + 20);
    glVertex2f(52, roadDivBtm + 20);
    glVertex2f(52, roadDivBtm + 0);
    glEnd();
    // Score Board
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(80, 97);
    glVertex2f(100, 97);
    glVertex2f(100, 98 - 8);
    glVertex2f(80, 98 - 8);
    glEnd();
    // Print Score
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95, GLUT_BITMAP_8_BY_13, "PRESS ENTER TO START");
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (start == 0) {
        fristDesign();
    }
    else {
        startGame();
    }
    glutPostRedisplay();
    glutSwapBuffers();
}

void pressKey(unsigned char key, int x, int y) {
    if (key == 13) {
        start = 1;
    }
}

void myInit() {
    glClearColor(0.000, 0.000, 0.000, 1.000);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Car Game");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(pressKey);
    myInit();
    glutMainLoop();
}



