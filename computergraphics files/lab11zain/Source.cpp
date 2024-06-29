#include "Canvas.h"
#include <gl/glut.h>
#include <iostream>
#include <fstream>
#include <math.h>


#define M_PI  3.14157
using namespace std;

// display

Canvas cvs(800, 600, "Motifs drawing");

void drawPolyLineFile(const char* fileName)
{
    fstream inStream;
    inStream.open(fileName, ios::in);	// open the file

    if (inStream.fail())
    {
        cout << "can't open it!"; return;
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
    inStream.close();
}
void starmotif()
{
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glLineWidth(2.0);
    glVertex2i(3, 3);
    glVertex2i(0, 8);
    glVertex2i(-3, 0);
    glVertex2i(-2, -1);
    glVertex2i(0, 5);
    glVertex2i(2, 3);
    glVertex2i(3, 3);
    glEnd();
    glPopMatrix();
}

void flakeMotif()
{
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(20.0f, 5.0f);
    glVertex2f(30.0f, 25.0f);
    glVertex2f(35.0f, 18.0f);
    glVertex2f(25.0f, 5.0f);
    glVertex2f(30.0f, 5.0f);
    glVertex2f(45.0f, 15.0f);
    glVertex2f(50.0f, 13.0f);
    glVertex2f(35.0f, 5.0f);
    glVertex2f(55.0f, 5.0f);
    glVertex2f(60.0f, 0.0f);
    glEnd();
    glPopMatrix();
}
void drawFlake() {
    for (int i = 0; i < 6; i++) {
        flakeMotif();
        cvs.scale2D(1.0, -1.0);
        flakeMotif();
        cvs.scale2D(1.0, -1.0);
        cvs.rotate2D(60.0);
    }
}

void drawStar()
{
    for (int i = 0; i < 5; i++)
    {
        starmotif();
        cvs.rotate2D(75.0);
    }
}

void drawDinoTable() {
    int numDinosaurs = 12;
    int tableRadius = 150; // Adjust the radius as needed
    int viewportWidth = 128; // Adjust the viewport size as needed

    for (int i = 0; i < numDinosaurs; i++) {
        double angle = 2.0 * M_PI * i / numDinosaurs;
        double x = 300 + tableRadius * cos(angle);
        double y = 300 + tableRadius * sin(angle);

        int viewportLeft = x - viewportWidth / 2;
        int viewportRight = x + viewportWidth / 2;
        int viewportBottom = y - viewportWidth / 2;
        int viewportTop = y + viewportWidth / 2;

        cvs.setViewport(viewportLeft, viewportRight, viewportBottom, viewportTop);
         //cvs.initCT();
         //cvs.rotate2D(i * 360 / numDinosaurs);
         //cvs.translate2D(0.0, 1.0);
        drawPolyLineFile("dino.dat");

    }
}
//>>>>>>>>>USE THIS DISPLAY FOR DINASOR<<<<<<<<<<<<<<
void display(void)
{
    cvs.setBackgroundColor(1.0, 1.0, 1.0); //background color is white 
    cvs.clearScreen(); //clear screen
    cvs.setColor(1.0, 0.0, 0.0); //drawing color is red 
    cvs.setWindow(0, 640, 0, 480);

    drawDinoTable();
    glFlush();
}
//void display(void)
//{
//    cvs.setBackgroundColor(1.0, 1.0, 1.0); //background color is white 
//    cvs.clearScreen(); //clear screen
//    cvs.setColor(1.0, 0.0, 0.0); //drawing color is red 
//    cvs.setWindow(-80.0, 80.0, -80.0, 80.0);
//    cvs.setViewport(20, 580, 20, 580);
//
//    //drawStar();
//    drawFlake();
//    glFlush();
//
//}// end display
int main(int argc, char** argv)
{
    // the window is opened in the Canvas constructor
    glutDisplayFunc(display);
    glutMainLoop();
}//end main