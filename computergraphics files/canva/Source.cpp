////Comment: ctrl+K +C 
//// Uncomment : ctrl + K + U 
//BOX using Canvas class
#include "canvas.h"
#include <GL/glut.h>
#include <math.h>


Canvas cvs(480, 600, "Test Canvas");

void display(void)
{
    cvs.setBackgroundColor(1.0, 1.0, 1.0); // Background color is white
    cvs.clearScreen(); // Clear screen

    cvs.setColor(1.0, 0.0, 0.0); // Drawing color is red
    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
    cvs.setViewport(10, 460, 10, 460);

    // Draw a box
    cvs.moveTo(-5.0, -5.0); // Move to the starting point of the box
    cvs.lineTo(5.0, -5.0);  // Draw the bottom line
    cvs.lineTo(5.0, 5.0);   // Draw the right line
    cvs.lineTo(-5.0, 5.0);  // Draw the top line
    cvs.lineTo(-5.0, -5.0); // Draw the left line

    glFlush();
}

int main(int argc, char** argv)
{
    // The window is opened in the Canvas constructor
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}







////Draw Line using Canvas class
//#include <iostream>
//#include <GL/glut.h>
//#include "canvas.h"
////#include <fstream>
//#include <math.h>
//
//
//#define M_PI  3.14157
//
//// display
//
//using namespace std;
//
//Canvas cvs(640, 480, "Test Canvas");
//
//RealRect r_rect;
//IntRect i_rect;
//
//
//
//void display(void)
//{
//    cvs.setBackgroundColor(1.0, 1.0, 1.0); //background color is white 
//    cvs.clearScreen(); //clear screen
//
//    cvs.setColor(1.0, 0.0, 0.0); //drawing color is red 
//    cvs.setWindow(-10.0, 10.0, -10.0, 10.0);
//    cvs.setViewport(10, 460, 10, 460);
//
//    i_rect.draw();
//
//    // ******PRACTICING Simple Line DRAWING*****//
//
//       // call moveTo() and lineTo();
//
//     // ******END RELATIVE DRAWING********//
//
//
//
//
//    glFlush();
//}// end display
//
//
//
//
//
//int main(int argc, char** argv)
//{
//    // the window is opened in the Canvas constructor
//    glutDisplayFunc(display);
//    glutMainLoop();
//}//end main






////Rectangle
//#include "canvas.h"
//#include <GL/glut.h>
//
//Canvas cvs(480, 600, "Canvas Example");
//
//void display(void) {
//    // Set the viewport and world window
//    cvs.setViewport(50, 450, 50, 550); // Adjust as needed
//    cvs.setWindow(0.0, 10.0, 0.0, 10.0); // Adjust as needed
//
//    // Clear the screen
//    cvs.setBackgroundColor(1.0, 1.0, 1.0);
//    cvs.clearScreen();
//
//    // Set the drawing color
//    cvs.setColor(0.0, 0.0, 1.0); // Blue color
//
//    // Draw a rectangle within the world window
//    cvs.moveTo(2.0, 2.0); // Bottom-left corner of the rectangle
//    cvs.lineTo(8.0, 2.0); // Bottom-right corner
//    cvs.lineTo(8.0, 8.0); // Top-right corner
//    cvs.lineTo(2.0, 8.0); // Top-left corner
//    cvs.lineTo(2.0, 2.0); // Close the rectangle
//
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
