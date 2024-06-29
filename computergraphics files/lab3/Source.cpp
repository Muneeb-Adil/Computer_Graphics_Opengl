////ACTIVITY:1
//#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
//#include <math.h>
//
//using namespace std;
//
//
//const int screenWidth = 650;	   // width of screen window in pixels 
//const int screenHeight = 450;	   // height of screen window in pixels
//
//void drawPolyLineFile(string fileName)
//{
//	fstream inStream;
//
//	inStream.open(fileName, ios::in);	// open the file
//
//	if (inStream.fail())
//	{
//		cout << "can't open it!";return;
//	}
//
//	glClear(GL_COLOR_BUFFER_BIT);      // clear the screen
//
//
//	GLfloat numpolys, numPoints, x, y;
//	inStream >> numpolys;		           // read the number of polylines
//
//	for (int j = 0; j < numpolys; j++)  // read each polyline
//	{
//		inStream >> numPoints;       //number of points in first PolyLine  
//		glBegin(GL_LINE_STRIP);	     // draw the next polyline
//		for (int i = 0; i < numPoints; i++)
//		{
//			inStream >> x >> y;        // read the next x, y pair
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//	glFlush();
//	inStream.close();
//}
//
//
//void myInit(void)
//{
//	glClearColor(0.0314, 0.0392, 0.3216, 1.0);       // background color is white
//	glColor3f(0.9294, 0.1294, 0.5333);         // drawing color is black
//	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);//dino window
//	glViewport(0, 0, screenWidth, screenHeight);
//
//}
//
//void myDisplay(void)
//{
//	drawPolyLineFile("dino.dat");
//	glutSwapBuffers();
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
//	glutInitWindowSize(screenWidth, screenHeight); // set window size
//	glutInitWindowPosition(10, 10); // set window position on screen
//	glutCreateWindow("Activity (1): Run the given skeleton code DinoPolyLines which should give following output on display."); // open the screen window
//	glutDisplayFunc(myDisplay);     // register redraw function
//	myInit();
//	glutMainLoop(); 		     // go into a perpetual loop
//	return 1;
//}



////ACTIVITY:2
//#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
//#include <math.h>
//
//using namespace std;
//
//
//const int screenWidth = 820;	   // width of screen window in pixels 
//const int screenHeight = 550;	   // height of screen window in pixels
//
//void drawPolyLineFile(string fileName)
//{
//	fstream inStream;
//
//	inStream.open(fileName, ios::in);	// open the file
//
//	if (inStream.fail())
//	{
//		cout << "can't open it!";return;
//	}
//
//
//
//	GLfloat numpolys, numPoints, x, y;
//	inStream >> numpolys;		           // read the number of polylines
//
//	for (int j = 0; j < numpolys; j++)  // read each polyline
//	{
//		inStream >> numPoints;       //number of points in first PolyLine  
//		glBegin(GL_LINE_STRIP);	     // draw the next polyline
//		for (int i = 0; i < numPoints; i++)
//		{
//			inStream >> x >> y;        // read the next x, y pair
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//	glFlush();
//	inStream.close();
//}
//
//
//
//void window(int xs, int xe, int ys, int ye) {
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluOrtho2D(xs, xe, ys, ye);//dino window
//
//}
//
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	window(0, screenWidth, 0, screenHeight);
//
//	for (int i = 0; i < 13; i++) {
//		for (int j = 0; j < 13; j++) {
//
//			glViewport(i * 64, j * 44, 64, 44);
//			drawPolyLineFile("dino.dat");
//
//		}
//
//	}
//	glutSwapBuffers();
//}
//
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutInitWindowPosition(10, 10);
//	glutCreateWindow("Lab Activity (2): Modify myDisplay() and type and run the given Code1 to get the following output 1( Tiling)"); // open the screen window
//	glutDisplayFunc(myDisplay);
//	glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//	glColor3f(0.9294, 0.1294, 0.5333);
//	glPointSize(2.0);
//	glutMainLoop();
//	return 1;
//}







////ACTIVITY:3
//#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
//#include <math.h>
//
//using namespace std;
//
//
//const int screenWidth = 820;	   // width of screen window in pixels 
//const int screenHeight = 550;	   // height of screen window in pixels
//
//void drawPolyLineFile(string fileName)
//{
//	fstream inStream;
//
//	inStream.open(fileName, ios::in);	// open the file
//
//	if (inStream.fail())
//	{
//		cout << "can't open it!";return;
//	}
//
//
//
//	GLfloat numpolys, numPoints, x, y;
//	inStream >> numpolys;		           // read the number of polylines
//
//	for (int j = 0; j < numpolys; j++)  // read each polyline
//	{
//		inStream >> numPoints;       //number of points in first PolyLine  
//		glBegin(GL_LINE_STRIP);	     // draw the next polyline
//		for (int i = 0; i < numPoints; i++)
//		{
//			inStream >> x >> y;        // read the next x, y pair
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//	glFlush();
//	inStream.close();
//}
//
//
//
//void window(int xs, int xe, int ys, int ye) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(xs, xe, ys, ye);//dino window
//
//}
//
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	// window(0,screenWidth,0,screenHeight);
//
//	for (int i = 0; i < 13; i++) {
//		for (int j = 0; j < 13; j++) {
//
//			if ((i + j) % 2 == 0) {
//				window(0, screenWidth, 0, screenHeight);
//			}
//			else {
//				window(0, screenWidth, screenHeight, 0);
//			}
//
//			glViewport(i * 64, j * 44, 64, 44);
//			drawPolyLineFile("dino.dat");
//
//		}
//
//	}
//	glutSwapBuffers();
//}
//
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutInitWindowPosition(10, 10);
//
//	glutCreateWindow("Lab Activity (3): Type and run the given Code2 to get the following output 2(Flipping the World Window +tilling )"); // open the screen window
//
//
//	glutDisplayFunc(myDisplay);
//
//
//	glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//	glColor3f(0.9294, 0.1294, 0.5333);
//	glPointSize(2.0);
//
//	glutMainLoop();
//
//	return 1;
//}




////ACTIVITY:04
//#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
//#include <math.h>
//
//using namespace std;
//
//float zoomFactor = 1.0; // Initial zoom factor
//
//const int screenWidth = 650;	   // width of screen window in pixels 
//const int screenHeight = 450;	   // height of screen window in pixels
//
//void drawPolyLineFile(string fileName)
//{
//	fstream inStream;
//
//	inStream.open(fileName, ios::in);	// open the file
//
//	if (inStream.fail())
//	{
//		cout << "can't open it!";return;
//	}
//
//	glClear(GL_COLOR_BUFFER_BIT);      // clear the screen
//
//	//GLint numpolys, numPoints, x ,y;
//
//	GLfloat numpolys, numPoints, x, y;
//	inStream >> numpolys;		           // read the number of polylines
//
//	for (int j = 0; j < numpolys; j++)  // read each polyline
//	{
//		inStream >> numPoints;       //number of points in first PolyLine  
//		glBegin(GL_LINE_STRIP);	     // draw the next polyline
//		for (int i = 0; i < numPoints; i++)
//		{
//			inStream >> x >> y;        // read the next x, y pair
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//	glFlush();
//	inStream.close();
//}
//
//void myDisplay(void)
//{
//	glClearColor(0.0314, 0.0392, 0.3216, 1.0);       // background color is white
//	glColor3f(0.9294, 0.1294, 0.5333);         // drawing color is black
//	glPointSize(2.0);		          // a 'dot' is 2 by 2 pixels
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0 * zoomFactor, (GLdouble)screenWidth * zoomFactor, 0.0 * zoomFactor, (GLdouble)screenHeight * zoomFactor);//dino window
//	glViewport(0, 0, screenWidth, screenHeight);
//
//
//
//	drawPolyLineFile("dino.dat");
//
//	glutSwapBuffers();
//
//
//}
//
//void keyboard(unsigned char key, int x, int y) {
//	if (key == '+') {
//		zoomFactor *= 0.9; // Zoom in by 10%
//		glutPostRedisplay(); // Request a redraw to apply the zoom
//		// std::cout<<zoomFactor<<"\n";
//	}
//	else if (key == '-') {
//
//		zoomFactor *= 1.1; // Zoom out by 10%
//		glutPostRedisplay(); // Request a redraw to apply the zoom
//		// std::cout<<zoomFactor<<"\n";
//	}
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
//	glutInitWindowSize(screenWidth, screenHeight); // set window size
//	glutInitWindowPosition(10, 10); // set window position on screen
//	glutCreateWindow("Lab Activity (4): Zooming in and Zooming out on a figure"); // open the screen window
//
//	glutDisplayFunc(myDisplay);     // register redraw function
//	glutKeyboardFunc(keyboard);
//
//
//	glutMainLoop(); 		     // go into a perpetual loop
//	return 1;
//}





////ACTIVITY:05
//#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
//#include <math.h>
//
//using namespace std;
//
//
//float VP_X = 0.0;
//float VP_Y = 0.0;
//float VP_WIDTH = 650.0;
//float VP_HEIGHT = 450.0;
//
//
//
//const int screenWidth = 650;	   // width of screen window in pixels 
//const int screenHeight = 450;	   // height of screen window in pixels
//
//void drawPolyLineFile(string fileName)
//{
//	fstream inStream;
//
//	inStream.open(fileName, ios::in);	// open the file
//
//	if (inStream.fail())
//	{
//		cout << "can't open it!";return;
//	}
//
//	glClear(GL_COLOR_BUFFER_BIT);      // clear the screen
//
//	//GLint numpolys, numPoints, x ,y;
//
//	GLfloat numpolys, numPoints, x, y;
//	inStream >> numpolys;		           // read the number of polylines
//
//	for (int j = 0; j < numpolys; j++)  // read each polyline
//	{
//		inStream >> numPoints;       //number of points in first PolyLine  
//		glBegin(GL_LINE_STRIP);	     // draw the next polyline
//		for (int i = 0; i < numPoints; i++)
//		{
//			inStream >> x >> y;        // read the next x, y pair
//			glVertex2f(x, y);
//		}
//		glEnd();
//	}
//	glFlush();
//	inStream.close();
//}
//
//void window(int xs, int xe, int ys, int ye) {
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(xs, xe, ys, ye);//dino window
//
//}
//
//void myDisplay(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//
//	window(0, screenWidth, 0, screenHeight);
//
//	glViewport(VP_X, VP_Y, VP_WIDTH, VP_HEIGHT);
//	drawPolyLineFile("dino.dat");
//
//	glutSwapBuffers();
//}
//
//
//void keyboard(unsigned char key, int x, int y) {
//	if (key == '1') {
//		VP_WIDTH += 10.0;
//		glutPostRedisplay();
//	}
//	else if (key == '2') {
//
//		VP_WIDTH -= 10.0;
//		glutPostRedisplay();
//	}
//	else if (key == '3') {
//		VP_HEIGHT += 10.0;
//		glutPostRedisplay();
//	}
//	else if (key == '4') {
//
//		VP_HEIGHT -= 10.0;
//		glutPostRedisplay();
//	}
//}
//
//void specialKeys(int key, int x, int y) {
//
//	if (key == GLUT_KEY_RIGHT) {
//		VP_X += 10.0;
//		glutPostRedisplay();
//	}
//	else if (key == GLUT_KEY_LEFT) {
//
//		VP_X -= 10.0;
//		glutPostRedisplay();
//	}
//	else if (key == GLUT_KEY_UP) {
//		VP_Y += 10.0;
//		glutPostRedisplay();
//	}
//	else if (key == GLUT_KEY_DOWN) {
//
//		VP_Y -= 10.0;
//		glutPostRedisplay();
//	}
//}
//
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // set display mode
//	glutInitWindowSize(screenWidth, screenHeight); // set window size
//	glutInitWindowPosition(10, 10); // set window position on screen
//	glutCreateWindow("Lab Activity (5): Make a Viewport Dynamic.( Output is attached) i.e Roaming a.k.a Panning (To move the view in a specific direction"); // open the screen window
//
//	glutDisplayFunc(myDisplay);     // register redraw function
//	glutKeyboardFunc(keyboard);
//	glutSpecialFunc(specialKeys);
//
//	glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//	glColor3f(0.9294, 0.1294, 0.5333);
//	glPointSize(2.0);
//
//	glutMainLoop(); 		     // go into a perpetual loop
//	return 1;
//}







////STEP:07   TEXT on screen
//#include <GL/glut.h>
//#include <string>
//
//void drawText(std::string text, int x, int y) {
//    glRasterPos2f(x, y);
//    int Len = text.length();
//    for (int i = 0; i < Len; i++) {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
//    }
//}
//
//// changing background color
//void changeWindowColor(float r, float g, float b, float a) {
//    glClearColor(r, g, b, a);
//}
//
//void display() {
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//
//    glColor3f(0.9294, 0.1294, 0.5333);
//    drawText("Lab # 3", 250, 400);
//    drawText("Computer Graphics using OpenGL :)", 250, 420);
//
//    glFlush();
//}
//
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0, width, height, 0, -1, 1);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 800);
//    glutCreateWindow("STEP 7: Writing Text to the Screen");
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    changeWindowColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    glutMainLoop();
//    return 0;
//}





//// Parametrized Regular Polygon
//
//#include <gl/glut.h>
//#include <cmath>
//
//const double PI = 3.14159265358979323846;
//
//class Point2 {
//public:
//    float x, y;
//
//    Point2(float x = 0.0, float y = 0.0) : x(x), y(y) {}
//};
//
//void moveTo(const Point2& p) {
//    glVertex2f(p.x, p.y);
//}
//
//void lineTo(const Point2& p) {
//    glVertex2f(p.x, p.y);
//}
//
//void ngon(int n, double cx, double cy, double radius, double rotAngle) {
//    if (n < 3) {
//        return;
//    }
//
//    glBegin(GL_LINE_LOOP);
//
//    double angle = rotAngle * PI / 180;
//    double angleInc = 2 * PI / n;
//
//    Point2 startPoint(cx + radius * cos(angle), cy + radius * sin(angle));
//    moveTo(startPoint);
//
//    for (int i = 0; i < n; ++i) {
//        angle += angleInc;
//        Point2 vertex(cx + radius * cos(angle), cy + radius * sin(angle));
//        lineTo(vertex);
//    }
//
//    glEnd();
//}
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glColor3f(0.0, 0.0, 0.0); // Set color to red
//
//    int sides = 6;          // Number of sides in the polygon
//    double centerX = 0.0;   // X-coordinate of the center
//    double centerY = 0.0;   // Y-coordinate of the center
//    double radius = 0.5;    // Radius of the polygon
//    double rotation = 30.0; // Rotation angle in degrees
//
//    ngon(sides, centerX, centerY, radius, rotation);
//
//    glFlush();
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutInitWindowPosition(30, 30);
//    glutCreateWindow("Lab 3 - Ngon & Polygon");
//    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}



////ACTIVITY:06
//#include <GL/glut.h>
//#include <cmath>
//
//const float PI = 3.14;
//const int numVertices = 100; // Number of vertices to approximate the circle
//
//void drawCircle(float centerX, float centerY, float radius) {
//    glBegin(GL_POLYGON);
//    for (int i = 0; i < numVertices; ++i) {
//        float angle = 2.0 * PI * static_cast<float>(i) / numVertices;
//        float x = centerX + radius * cos(angle);
//        float y = centerY + radius * sin(angle);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//void display() {
//    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glColor3f(0.9294, 0.1294, 0.5333);
//
//    // Draw a circle centered at (0, 0) with radius 5
//    drawCircle(0.0, 0.0, 5.0);
//
//    glFlush();
//}
//
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Lab Activity (6): Circle using Polygon");
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}





////ACTIVITY:07
//#include <GL/glut.h>
//#include <cmath>
//
//const float PI = 3.14;
//const int numVertices = 50; // Number of vertices to approximate the arc
//
//void drawArc(float centerX, float centerY, float radius, float startAngle, float endAngle) {
//    glBegin(GL_LINE_STRIP);
//    for (int i = 0; i <= numVertices; ++i) {
//        float angle = startAngle + (endAngle - startAngle) * static_cast<float>(i) / numVertices;
//        float x = centerX + radius * cos(angle);
//        float y = centerY + radius * sin(angle);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//void display() {
//    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    glColor3f(0.9294, 0.1294, 0.5333);
//    glPointSize(10.0);
//
//    // Draw an arc centered at (0, 0) with a radius of 5, from 45 degrees to 135 degrees
//    drawArc(0.0, 0.0, 5.0, 45.0 * PI / 180.0, 135.0 * PI / 180.0);
//
//    glFlush();
//}
//
//void reshape(int width, int height) {
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("LabActivity(7) - Drawing Simple Arc");
//
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}








////ACTIVITY:09
//#include <iostream>
//#include <cmath>
//#include <GL/glut.h> 
//
//typedef struct { float x, y; } tRealPoint;
//
//class Canvas {
//private:
//    tRealPoint CP;
//public:
//    Canvas() { CP.x = CP.y = 0.0; }
//    void lineTo(float x, float y);
//    void moveTo(float x, float y) { CP.x = x; CP.y = y; }
//};
//
//void Canvas::lineTo(float x, float y) {
//    glBegin(GL_LINES);
//    glVertex2f((GLfloat)CP.x, (GLfloat)CP.y);
//    CP.x = x; CP.y = y;
//    glVertex2f((GLfloat)CP.x, (GLfloat)CP.y);
//    glEnd();
//    glFlush();
//}
//
//int screenWidth = 700, screenHeight = 700;
//Canvas cvs;
//int numSides = 5;
//float angle = 0.0, delAngle = 0;
//
//void Rosette(int N, float radius) {
//    const int MaxNum = 97;
//    tRealPoint pt[MaxNum];
//    float angle = 2 * 3.14159265 / N;
//
//    if (N < 3 || N >= MaxNum) return;
//    for (int j = 0; j < N; j++) {
//        pt[j].x = radius * cos(angle * j);
//        pt[j].y = radius * sin(angle * j);
//    }
//    for (int i = 0; i < N - 1; i++)
//        for (int j = i + 1; j < N; j++) {
//            cvs.moveTo(pt[i].x, pt[i].y);
//            cvs.lineTo(pt[j].x, pt[j].y);
//        }
//}
//
//void display(void) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glRotatef(angle, 0, 0, 1);
//    Rosette(numSides, 8);
//    glutSwapBuffers();
//}
//
//void myKeys(unsigned char key, int x, int y) {
//    if (key == 'n') {
//        numSides++;
//    }
//    else if (key == 'N') {
//
//        numSides--;
//    }
//    else if (key == 'r') {
//
//        delAngle += 1.0;
//    }
//    else if (key == 'R') {
//
//        delAngle -= 1.0;
//    }
//    else if (key == 'q' or key == 'Q') {
//
//        exit(0);
//    }
//    glutPostRedisplay();
//}
//
//
//
//void spinner(void) {
//    angle += delAngle;
//    glutPostRedisplay();
//}
//
//void myInit() {
//    glClearColor(0.0314, 0.0392, 0.3216, 1.0);
//    glColor3f(0.9294, 0.1294, 0.5333);
//    glPointSize(10.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-10, 10, -10, 10);
//    glViewport(0, 0, screenWidth, screenHeight);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(screenWidth, screenHeight);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Lab Activity(9): Implement The rosette, and the Golden 5-rosette");
//    glutKeyboardFunc(myKeys);
//    glutDisplayFunc(display);
//    glutIdleFunc(spinner);
//    myInit();
//    glutMainLoop();
//    return 0;
//}





//// Lab Activity 10
//
//#include <gl/glut.h>
//#include <cmath>
//
//int screenWidth = 640;
//int screenHeight = 480;
//float circleCenterX = 320;
//float circleCenterY = 240;
//float circleRadius = 100;
//
//void drawCircle()
//{
//    glBegin(GL_LINE_LOOP);
//    for (int i = 0; i < 360; i++)
//    {
//        float angle = i * 3.14159 / 180;
//        float x = circleCenterX + circleRadius * cos(angle);
//        float y = circleCenterY + circleRadius * sin(angle);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//
//void myDisplay(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
//
//    drawCircle();
//
//    glFlush();
//}
//
//void myInit()
//{
//    glClearColor(1.0f, 1.0f, 1.0f, 0.0); // Set background color to white
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(screenWidth, screenHeight);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Lab 3 - Circle Drawing");
//    glutDisplayFunc(myDisplay);
//    myInit();
//    glutMainLoop();
//    return 0;
//}



