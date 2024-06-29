//PAINT TOOL
#include<gL/glut.h>
#include<cstdlib>
#define RED 2
#define GREEN 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define YELLOW 7
#define BLACK 8
#define ERASER 9

int ScreenHeight = 600, brushSize = 3;
float red = 1.0, green = 0, blue = 1.0;

void myInit(void) {
	glClearColor(1, 1, 1, 1);
	glColor3f(red, green, blue);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
}

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void myMovedMouse(int mouseX, int mouseY) {
	glColor3f(red, green, blue);
	GLint x = mouseX;
	GLint y = ScreenHeight - mouseY;
	glRecti(x, y, x + brushSize, y + brushSize);
	glFlush();
}
void myKeyboard(unsigned char key, int mouseX, int mouseY) {
	switch (key) {
	case '+':
		brushSize++;
		break;
	case '-':
		if (brushSize > 1.0)
			brushSize--;
		break;
	case 'c':
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		break;
	case 'e':
		exit(-1);
	default:
		break;
	}
}
void processMenuEvents(int option) {
	switch (option) {
	case RED:red = 1.0, green = 0, blue = 0;break;
	case GREEN:red = 0.0, green = 1.0, blue = 0;break;
	case BLUE:red = 0, green = 0, blue = 1.0;break;
	case MAGENTA:red = 1.0, green = 0, blue = 1.0;break;
	case CYAN:red = 0, green = 1.0, blue = 1.0;break;
	case YELLOW:red = 1.0, green = 1.0, blue = 0;break;
	case BLACK:red = 0, green = 0, blue = 0;break;
	case ERASER:red = 1.0, green = 1.0, blue = 1.0;break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(200, 50);
	glutCreateWindow("PAINT TOOL");
	glutDisplayFunc(myDisplay);
	glutMotionFunc(myMovedMouse);
	glutKeyboardFunc(myKeyboard);
	glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("RED", RED);
	glutAddMenuEntry("BLUE", BLUE);
	glutAddMenuEntry("GREEN", GREEN);
	glutAddMenuEntry("YELLOW", YELLOW);
	glutAddMenuEntry("CYAN", CYAN);
	glutAddMenuEntry("MAGENTA", MAGENTA);
	glutAddMenuEntry("YELLOW", YELLOW);
	glutAddMenuEntry("BLACK", BLACK);
	glutAddMenuEntry("ERASER", ERASER);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	myInit();
	glutMainLoop();
}






////DRAW SHAPE ON KEY PRESS
//#include <gl/glut.h>

//#include <vector>
//#include <math.h>
//#include <string>
//
//using namespace std;
//
//class Shape {
//public:
//    virtual void draw() = 0;
//};
//
//class Triangle : public Shape {
//public:
//    void draw() override {
//        glBegin(GL_TRIANGLES);
//        glVertex2f(150, 50);
//        glVertex2f(100, 150);
//        glVertex2f(200, 150);
//        glEnd();
//    }
//};
//
//class Circle : public Shape {
//public:
//    void draw() override {
//        const float PI = 3.14159;
//        int segments = 50;
//        glBegin(GL_TRIANGLE_FAN);
//        glVertex2f(320, 240);
//        for (int i = 0; i <= segments; i++) {
//            float angle = 2.0f * PI * float(i) / float(segments);
//            float x = 50 * cos(angle);
//            float y = 50 * sin(angle);
//            glVertex2f(x + 320, y + 240);
//        }
//        glEnd();
//    }
//};
//
//int screenWidth = 640;
//int screenHeight = 480;
//vector<Shape*> shapes;
//Shape* currentShape = nullptr;
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    for (Shape* shape : shapes) {
//        shape->draw();
//    }
//
//    glFlush();
//}
//
//void myKeys(unsigned char key, int x, int y) {
//    switch (key) {
//    case 't':
//        currentShape = new Triangle();
//        shapes.push_back(currentShape);
//        glutPostRedisplay();
//        break;
//    case 'c':
//        currentShape = new Circle();
//        shapes.push_back(currentShape);
//        glutPostRedisplay();
//        break;
//    }
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(screenWidth, screenHeight);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Simple Drawing Program");
//
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
//    glMatrixMode(GL_MODELVIEW);
//
//    glutDisplayFunc(display);
//    glutKeyboardFunc(myKeys);
//
//    glutMainLoop();
//
//    for (Shape* shape : shapes) {
//        delete shape;
//    }
//
//    return 0;
//}





//// motif: 3.5.5  3.5.6   spiral : 3.5.8  3.5.9
//#include <gl/glut.h>
//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//int screenWidth = 740;
//int screenHeight = 480;
//
//class Canvas {
//public:
//	float x, y;
//	float angle;
//	Canvas() {
//		this->x = 150;
//		this->y = 200;
//	}
//	void turnTo(float angle) {
//		this->angle = angle;
//	}
//	void turn(float angle) {
//		this->angle += angle;
//	}
//	void lineTo(float x, float y) {
//		float t_x = x; float t_y = y;
//		glColor3f(1.0, 0.0, 0.0);
//		glLineWidth(2.0);
//		glBegin(GL_LINES);
//		glVertex2f(this->x, this->y);
//		glVertex2f(x, y);
//		glEnd();
//		glFlush();
//		moveTo(t_x, t_y);
//	}
//	void moveTo(float x, float y) {
//		this->x = x;
//		this->y = y;
//
//	}
//
//	void forward(float dist, int isVisible) {
//		const float RadPerDeg = 0.017453393;
//		float x = this->x + dist * cos(RadPerDeg * this->angle);
//		float y = this->y + dist * sin(RadPerDeg * this->angle);
//		if (isVisible >= 1) {
//			lineTo(x, y);
//
//		}
//		else {
//			moveTo(x, y);
//		}
//	}
//};
//
//float increment = 3;
//Canvas cvs;
//
//// Practice Qustion 3.5.9
//void PolySpiral(float dist) {
//	if (dist > 200) {
//		return;
//	}
//	cvs.forward(dist, 1);
//	cvs.turn(-144);
//	dist += increment;
//	PolySpiral(dist + increment);
//}
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	// 3.5.5 Classes of Meanders 
//	// part a 
//	/* float l = 70.0;
//	for (int i = 0; i < 3; i++) {
//		cvs.forward(l, 1);
//		cvs.turn(90);
//		cvs.forward(l - 20, 1);
//		cvs.turn(90);
//		cvs.forward(l / 2,1);
//		cvs.turn(270);
//		cvs.forward(l/2, 1);
//		cvs.turn(270);
//		cvs.forward(l + 20, 1);
//		cvs.turn(270);
//		cvs.forward(l / 2, 1);
//		cvs.turn(270);
//		cvs.forward(l / 2, 1);
//		cvs.turn(90);
//		cvs.forward(l - 20, 1);
//		cvs.turn(90);
//		cvs.forward(l, 1);
//	}*/
//
//	//// 3.5.5 part b
//	//float L = 70.0;
//	//for (int i = 0; i < 3; i++) {
//	//	cvs.forward(L, 1);
//	//	cvs.turn(90);
//	//	cvs.forward(L - 20, 1);
//	//	cvs.turn(90);
//	//	cvs.forward(L / 2, 1);
//	//	cvs.turn(270);
//	//	cvs.forward(L / 2, 1);
//	//	cvs.turn(270);
//	//	cvs.forward(L - 20, 1);
//	//	cvs.turn(270);
//	//	cvs.forward(15, 1);
//	//	cvs.turn(90);
//	//	cvs.forward(25, 1);
//	//	cvs.turn(90);
//	//	cvs.forward(15, 1);
//	//	cvs.turn(270);
//	//	cvs.forward(L - 20, 1);
//	//	cvs.turn(270);
//	//	cvs.forward(L / 2, 1);
//	//	cvs.turn(270);
//	//	cvs.forward(L / 2, 1);
//	//	cvs.turn(90);
//	//	cvs.forward(L - 20, 1);
//	//	cvs.turn(90);
//	//	cvs.forward(L, 1);
//	//}
//
//	//// 3.5.8 . Is a Polyspiral an IFS ? (example 3.5.3) 
//	/*float L = 80.0;
//	for (int i = 0; i < 50; i++) {
//		cvs.forward(L, 1);
//		cvs.turn(-144);
//		L += increment;
//	}	*/
//
//	//// 3.5.9  Recursive form for Polyspiral()
//	 
//	//PolySpiral(L);
//
//
//	// 3.5.6  Drawing Elaborate Meanders.
//	/*float L = 80.0;
//	bool limitReached = false;
//	for (int i = 0; i < 24; i++) {
//		if (!limitReached && L == 0) {
//			L = 10;
//			cvs.forward(L, 1);
//			cvs.turn(-90);
//			limitReached = true;
//		}
//		if (!limitReached && L >= 10) {
//			cout << i << L << endl;
//			cvs.forward(L, 1);
//			cvs.turn(90);
//			cout << "curr-angle:" << cvs.angle << endl;
//			L -= 10;
//		}
//		if (limitReached && L <= 80 + 10) {
//			cout << i << L << endl;
//			cvs.forward(L, 1);
//			cvs.turn(-90);
//			L += 10;
//		}
//	}*/
//	glFlush();
//
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Week 5 | 3.5.5 - 3.5.9");
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
//	glMatrixMode(GL_MODELVIEW);
//
//	glutDisplayFunc(display);
//
//	glutMainLoop();
//	return 0;
//}






//////3.5.1-3.5.3   shape , move with f,l,r line draw with this
//#include <gl/glut.h>
//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//int screenWidth = 640;
//int screenHeight = 480;
//class GLintPoint {
//public:
//	GLint x, y;
//};
//
//class Point2
//{
//public:
//	float x, y;
//
//	void set(float dx, float dy)
//	{
//		x = dx;
//		y = dy;
//	}
//
//	void set(Point2& p)
//	{
//		x = p.x;
//		y = p.y;
//	}
//
//	Point2(float xx, float yy)
//	{
//		x = xx;
//		y = yy;
//	}
//
//	Point2()
//	{
//		x = y = 0;
//	}
//};
//
//class Turtle {
//private:
//	int CD = 90;
//	Point2 CP;
//public:
//	float x, y;
//	float angle;
//	Turtle() {
//		this->x = 225;
//		this->y = 200;
//	}
//	void turnTo(float angle) {
//		this->angle = angle;
//	}
//	void turn(float angle) {
//		this->angle += angle;
//	}
//	void lineTo(float x, float y) {
//		float t_x = x; float t_y = y;
//		glColor3f(1.0, 0.0, 0.0);
//		glLineWidth(2.0);
//		glBegin(GL_LINES);
//		glVertex2f(this->x, this->y);
//		glVertex2f(x, y);
//		glEnd();
//		glFlush();
//		moveTo(t_x, t_y);
//	}
//	void moveTo(float x, float y) {
//		this->x = x;
//		this->y = y;
//
//	}
//
//	void forward(float dist, int isVisible) {
//		const float RadPerDeg = 0.017453393;
//		float x = this->x + dist * cos(RadPerDeg * this->angle);
//		float y = this->y + dist * sin(RadPerDeg * this->angle);
//		if (isVisible >= 1) {
//			lineTo(x, y);
//
//		}
//		else {
//			moveTo(x, y);
//		}
//	}
//
//};
//
//
//float increment = 3;
//Turtle turtle;
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	// 3.5.1 Drawing Turtles Figure
//	// part (a)
//	/*float L = 200.0;
//	for (int j = 0; j < 4; j++) {
//
//		for (int i = 0; i < 4; i++) {
//			turtle.forward(L, 1);
//			turtle.turn(90);
//			turtle.forward(L, 1);
//			turtle.turn(90);
//			turtle.forward(L, 1);
//			turtle.turn(90);
//		}
//		L -= 40;
//	}*/
//
//	//3.5.1 part (b)
//	/*for (int j = 0; j < 4; j++) {
//
//		turtle.forward(L, 1);
//		turtle.turn(90);
//		turtle.forward(L, 1);
//		turtle.turn(90);
//		L -= 20;
//		turtle.forward(L, 1);
//		turtle.turn(90);
//		turtle.forward(L, 1);
//		turtle.turn(90);
//		L -= 20;
//	}*/
//
//	// 3.5.1 part (c)
//	/*float L = 200.0;
//	turtle.forward(L, 1);
//	turtle.turn(120);
//	turtle.forward(L / 2, 1);
//	turtle.turn(120);
//	turtle.forward(L / 2, 1);
//	turtle.turn(240);
//	turtle.forward(L / 2, 1);
//	turtle.turn(240);
//	turtle.forward(L / 2, 1);
//	turtle.turn(120);
//	turtle.forward(L / 2, 1);
//	turtle.turn(120);
//	turtle.forward(L, 1);*/
//
//
//	// 3.5.2 Drawing a well-known logo
//	/*float L = 100.0;
//	turtle.forward(L, 1);
//	turtle.turn(320);
//	turtle.forward(L, 1);
//	turtle.turn(220);
//	turtle.forward(L, 1);
//	turtle.turn(320);
//	turtle.forward(L, 1);
//
//	turtle.turn(40);
//
//	turtle.forward(L, 1);
//	turtle.turn(40);
//	turtle.forward(L, 1);
//	turtle.turn(140);
//	turtle.forward(L, 1);
//	turtle.turn(40);
//	turtle.forward(L * 2, 1);
//
//	turtle.turn(90);
//	turtle.forward(L, 1);
//	turtle.turn(100);
//	turtle.forward(L, 1);
//	turtle.turn(80);
//	turtle.forward(L, 1);*/
//
//	turtle.forward(100, 0);
//
//	// 3.5.3 Driving the turtle with strings
//	string input = "FLFLFLFRFLFLFLFRFLFLFLFR";
//	for (char key : input) {
//		switch (key) {
//		case 'F':
//			turtle.forward(30, 1);
//			break;
//		case 'L':
//			turtle.turn(60);
//			break;
//		case 'R':
//			turtle.turn(-60);
//			break;
//		}
//	}
//	glFlush();
//}
//
//// 3.5.3 Driving the turtle with strings
//void myKeys(unsigned char key, int x, int y) {
//	int L = 30;
//	switch (key) {
//	case 'f':
//		turtle.forward(L, 1);
//		break;
//	case 'l':
//		turtle.turn(60);
//		break;
//	case 'r':
//		turtle.turn(-60);
//		break;
//	}
//
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(screenWidth, screenHeight);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Practice Exercise 3.5.1-3.5.3");
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);
//	glMatrixMode(GL_MODELVIEW);
//
//	glutDisplayFunc(display);
//	glutKeyboardFunc(myKeys);
//
//	glutMainLoop();
//	return 0;
//}





