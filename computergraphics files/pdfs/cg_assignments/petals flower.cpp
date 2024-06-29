// petals flower.cpp : Defines the entry point for the console application.
//


#include"stdafx.h"
#include<windows.h>
#include<glut.h>
#include<math.h>
#include<fstream>
#include<iostream>
using namespace std;
void tree(int x,int y,int width,int height);

//<<Support Classes for Canvas>>>
class Point2   //single point w/ floating point coordinates
{
public:
	Point2() {x = y = 0.0f;} 
	Point2(float xx, float yy) {x=xx; y=yy;} 
	void set(float xx, float yy) {x=xx; y=yy;}
	float getX() {return x;}
	float getY() {return y;}
	void draw(void)
	{
		glBegin(GL_POINTS); //draw this point
			glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();
	}
private:
	float x, y;
};

class IntRect  //aligned rectangle with integer coordinates, used for viewport
{
public:
	IntRect() {l = 0; r=100; b=0; t=100;} 
	IntRect(int left, int right, int bottom, int top)
		{l = left; r=right; b=bottom; t=top;}
	void set(int left, int right, int bottom, int top)
	{
		l=left; r=right; b=bottom; t=top;
	}
	void draw(void); //draw this rectangle using OpenGL
	int getL(void)
	{
		return l;
	}
	int getR(void)
	{
		return r;
	}
	int getT(void)
	{
		return t;
	}
	int getB(void)
	{
		return b;
	}

private:
	int l, r, b, t;
};

class RealRect   //simlar to IntRect but w/ floating points & used for world window
{
public:
	RealRect() {l = 0; r=100; b=0; t=100;} 
	RealRect(float left, float right, float bottom, float top)
		{l = left; r=right; b=bottom; t=top;}
	void set(float left, float right, float bottom, float top)
	{
		l=left; r=right; b=bottom; t=top;
	}
	float getL(void)
	{
		return l;
	}
	float getR(void)
	{
		return r;
	}
	float getT(void)
	{
		return t;
	}
	float getB(void)
	{
		return b;
	}
	void draw(void); //draw this rectangle using OpenGL
private:
	float l, r, b, t;
};
//<<End Support Classes>>>

class Canvas
{
public:
	Canvas(int width, int height, char* windowTitle); //constructor
        void setWindow(float l, float r, float b, float t);
        void setViewport(int l, int r, int b, int t);
        IntRect getViewport(void); //divulge the viewport data
        RealRect getWindow(void); // divulge the window data
        float getWindowAspectRatio(void);
        void clearScreen();
        void setBackgroundColor(float r, float g, float b);
        void setColor(float r, float g, float b);
        void lineTo(float x, float y);
        void lineTo(Point2 p);
        void moveTo(float x, float y);
        void moveTo(Point2 p);
		void moveRel(float dx, float dy);
		void turnTo(float angle);
		void turn(float angle);
		void forward(float dist, int isVisible);
	Point2 Tween(Point2 A, Point2 B, float t);
        void drawTween(Point2 A[], Point2 B[], int N, float t);


private:
     Point2 CP;         //current position in the world
	 float CD;          //current direction in the world
     IntRect viewport;  //the current window
     RealRect window;   //the current viewport

} ;

//<<moveTo>>
//changes current point
void Canvas:: moveTo(float x, float y)
{
	CP.set(x, y);
}

//<<lineTo>>
//draws a line from current point to new point
void Canvas:: lineTo(float x, float y)
{
	glBegin(GL_LINES);
		glVertex2f((GLfloat) CP.getX(), (GLfloat) CP.getY());
		glVertex2f((GLfloat) x, (GLfloat) y); //draw the line
	glEnd();
	CP.set (x, y); //update current point to new point
	glFlush();
}

//<<setWindow>>
void Canvas:: setWindow (float l, float r, float b, float t)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D ((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
	window.set (l, r, b, t);
}

//<<setViewport>>
void Canvas:: setViewport (int l, int r, int b, int t)
{
	glViewport(l, b, r-l, t-b);
	viewport.set (l, r, b, t);
}

IntRect Canvas:: getViewport(void)
{
	return viewport;
}

RealRect Canvas:: getWindow(void)
{
	return window;
}

void Canvas:: clearScreen(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Canvas:: setBackgroundColor(float r, float g, float b)
{
	glClearColor(r, g, b, 0.0);   //4th variable level of transparency, may need to change 
}

void Canvas:: setColor(float r, float g, float b)
{
	glColor3f(r, g, b);
}

void Canvas:: lineTo(Point2 p)
{
	glBegin (GL_LINES);
		glVertex2f((GLfloat) CP.getX(), (GLfloat) CP.getY());
		glVertex2f((GLfloat) p.getX(), (GLfloat) p.getY());
	glEnd();
	CP.set(p.getX(), p.getY());
	glFlush();
}

Canvas:: Canvas(int width, int height, char* windowTitle)
{
	char* argv[1];  //dummy argument list for glutinit()
	char dummyString[8];
	argv[0] = dummyString;  //hook up the pointer
	int argc = 1;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition (20,20);
	glutCreateWindow (windowTitle);
	setWindow(0, (float)width, 0, (float)height); // default world window
	setViewport (0, width, 0, height); //default viewport
	CP.set(0.0f, 0.0f); //initialize the cp to (0,0)
}

void Canvas:: moveTo(Point2 p)  //moves current point CP to point p object 
{
	float x1, y1;
	x1 = p.getX();
	y1 = p.getY();
	CP.set(x1, y1);
}

float Canvas:: getWindowAspectRatio(void)  //calculates aspect ratio of world window
{
	float width, height, aspectRatio;
	width = window.getR() - window.getL();
	height = window.getT() - window.getB();
	aspectRatio = width/height;
	return aspectRatio;
}

void Canvas:: moveRel(float dx, float dy)
{
	CP.set(CP.getX() + dx, CP.getY() + dy);
}

void Canvas:: turnTo(float angle)
{
	CD = angle;
}

void Canvas:: turn(float angle)
{
	CD += angle;
}

void Canvas:: forward(float dist, int isVisible)
{
	const float RadPerDeg = 0.017453393;  //radians per degree
	float x = CP.getX() + dist * cos(RadPerDeg * CD);
	float y = CP.getY() + dist * sin(RadPerDeg * CD);
	if (isVisible)
		lineTo(x, y);
	else
		moveTo(x, y);
}

Point2 Canvas:: Tween(Point2 A, Point2 B, float t)
{
  Point2 P;
  P.set(A.getX() + (B.getX() - A.getX())*t, A.getY() + (B.getY() - A.getY())*t);
  return P;
}
class point{
public:
	int x,y;
};

void Canvas:: drawTween(Point2 A[], Point2 B[], int N, float t)
{
  for(int i = 0; i < N; i++)
    {
      Point2 P;
      P = Tween(A[i], B[i], t);
      if (i == 0) moveTo(P.getX(), P.getY());
      else  lineTo(P.getX(), P.getY());
    
  }}

Canvas cvs(640,480,"flower");
void ngon(int n,float x,float y,float radius,float rotationangle)
{
	if(n<3)
		return;
	double angle=rotationangle*3.14159265/180;
	double angleInc=2*3.14159265/n;
	cvs.moveTo(radius*cos(angle)+x,radius*sin(angle)+y);
	for (int i=0;i<n;i++)
	{
		angle+=angleInc;
		cvs.lineTo(radius*cos(angle)+x,radius*sin(angle)+y);
	}
}

void flr(int n,float x,float y,float radius,float rotationangle)
{
	if(n<3)
		return;
	double angle=rotationangle*3.14159265/180;
	double angleInc=2*3.14159265/n;
	//cvs.moveTo(radius*cos(angle)+x,radius*sin(angle)+y);
	for (int i=0;i<n;i++)
	{
		angle+=angleInc;
		ngon(100,radius*cos(angle)+x,radius*sin(angle)+y,40,90);
	}
}
void display(void)
{

	cvs.clearScreen();
	cvs.setBackgroundColor(1,1,1);
	//cvs.setColor(28/255.0,0/255.0,24/255.0);
	cvs.setColor(0,1,1);
	ngon(100,320,240,40,90);
	flr(6,320,240,80,90);
glFlush();
}
int main(int argc,CHAR**argv)
{
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}





