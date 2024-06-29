// scenery.cpp : Defines the entry point for the console application.
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

Canvas cvs(640,480,"ramsha");
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


void moon(int n,float x,float y,float radius,float rotationangle)
	{
     if(n<3)
		return;
	double angle=rotationangle*3.14159265/180;
	double angleInc=2*3.14159265/n;
	glBegin(GL_POLYGON);
	for (int i=0;i<n;i++)
	{
		angle+=angleInc;
		glVertex2i(radius*cos(angle)+x,radius*sin(angle)+y);
	}
	glEnd();
	glFlush();
	}
void display(void)
	
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0,640,0,480);

//background color
	glColor3f(228/255.0,223/255.0,27/255.0);
glBegin(GL_POLYGON);
glVertex2i(0,480);
glColor3f(247/255.0,245/255.0,186/255.0);
glVertex2i(0,350);
glVertex2i(640,350);
glColor3f(243/255.0,117/255.0,0/255.0);
glVertex2i(640,480);
glVertex2i(0,480);
glEnd();

//water
glColor3f(9/255.0,181/255.0,247/255.0);
glBegin(GL_POLYGON);
glVertex2i(0,300);
glColor3f(0/255.0,39/255.0,79/255.0);
glVertex2i(0,0);
//glColor3f(0/255.0,39/255.0,79/255.0);
glColor3f(0/255.0,91/255.0,183/255.0);
glVertex2i(640,0);
glColor3f(0/255.0,64/255.0,128/255.0);
glVertex2i(640,350);
glVertex2i(0,350);
glEnd();

//rr
glColor3f(0/255.0,39/255.0,79/255.0);
glBegin(GL_POLYGON);
glVertex2i(400,100);
glVertex2i(350,80);
glVertex2i(600,80);
glVertex2i(550,100);
glVertex2i(400,100);
glEnd();




glColor3f(1,1,0);
	moon(150,30,470,40,90);
//glClear(GL_COLOR_BUFFER_BIT);



//sand
glColor3f(179/255.0,89/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(0,300);
glVertex2i(150,320);
glColor3f(255/255.0,205/255.0,155/255.0);
glVertex2i(200,400);
glColor3f(255/255.0,205/255.0,155/255.0);
glVertex2i(100,380);
glVertex2i(0,350);
glEnd();
glColor3f(179/255.0,89/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(200,400);
glColor3f(255/255.0,205/255.0,155/255.0);
glVertex2i(150,320);
glVertex2i(300,320);
glVertex2i(310,400);
glColor3f(255/255.0,150/255.0,45/255.0);
glVertex2i(680,350);
glColor3f(255/255.0,205/255.0,155/255.0);
glVertex2i(680,240);
glVertex2i(300,320);

glEnd();
//boundary-tree brown
glColor3f(183/255.0,91/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(35,280);
glVertex2i(120,170);
//glColor3f(130/255.0,65/255.0,0/255.0);
glColor3f(255/255.0,217/255.0,179/255.0);
glVertex2i(155,170);
glVertex2i(80,270);
glColor3f(130/255.0,65/255.0,0/255.0);
glVertex2i(35,280);
glEnd();


//grass
glColor3f(0,1,0);
glBegin(GL_POLYGON);
glVertex2i(0,350);
glVertex2i(10,400);
glVertex2i(20,350);
glVertex2i(30,400);
glVertex2i(40,360);
glVertex2i(50,405);
glVertex2i(60,365);
glVertex2i(70,400);
glVertex2i(80,370);
glVertex2i(90,400);
glVertex2i(100,370);
glVertex2i(110,410);
glVertex2i(120,380);
glVertex2i(130,415);
glVertex2i(140,390);
glVertex2i(150,420);
glVertex2i(170,400);
glVertex2i(180,430);
glVertex2i(190,400);
glVertex2i(200,410);

glVertex2i(210,400);
glVertex2i(220,410);
glVertex2i(240,400);
glVertex2i(250,430);
glVertex2i(260,400);
glVertex2i(270,430);
glVertex2i(280,400);
glVertex2i(260,400);
glEnd();

glColor3f(0,1,0);
glBegin(GL_POLYGON);
glVertex2i(260,400);
glVertex2i(290,400);
glVertex2i(300,390);
glVertex2i(310,410);
glVertex2i(320,430);
glVertex2i(330,390);

glVertex2i(350,410);
glVertex2i(370,390);
glVertex2i(390,410);
glVertex2i(400,430);
glVertex2i(420,430);
glVertex2i(430,380);
glVertex2i(440,400);
glEnd();

glColor3f(0,1,0);
glBegin(GL_POLYGON);
glVertex2i(590,360);
glVertex2i(600,400);
glVertex2i(610,360);
glVertex2i(620,400);
glVertex2i(630,355);
glVertex2i(640,400);
glVertex2i(640,410);
glVertex2i(640,350);
glEnd();

//tree
glColor3f(128/255.0,64/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(355,320);
glVertex2i(365,320);
glVertex2i(365,370);
glVertex2i(355,370);
glVertex2i(355,320);
glEnd();
glColor3f(0/255.0,113/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(330,370);
glVertex2i(390,370);
glVertex2i(360,420);
glVertex2i(330,370);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(330,390);
glVertex2i(390,390);
glVertex2i(360,430);
glVertex2i(330,390);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(330,400);
glVertex2i(390,400);
glVertex2i(360,430);
glVertex2i(330,400);
glEnd();
//tree
glColor3f(128/255.0,64/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(50,330);
glVertex2i(60,330);
glVertex2i(60,380);
glVertex2i(50,380);
glVertex2i(50,330);
glEnd();
glColor3f(0/255.0,113/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(30,380);
glVertex2i(80,380);
glVertex2i(55,400);
glVertex2i(30,380);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(30,390);
glVertex2i(80,390);
glVertex2i(55,410);
glVertex2i(30,390);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(30,400);
glVertex2i(80,400);
glVertex2i(55,420);
glVertex2i(30,400);
glEnd();
//tree

glColor3f(128/255.0,64/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(200,330);
glVertex2i(210,330);
glVertex2i(210,380);
glVertex2i(200,380);
glVertex2i(200,330);
glEnd();
glColor3f(0/255.0,113/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(180,380);
glVertex2i(230,380);
glVertex2i(205,400);
glVertex2i(180,380);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(180,390);
glVertex2i(230,390);
glVertex2i(205,410);
glVertex2i(180,390);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(180,400);
glVertex2i(230,400);
glVertex2i(205,420);
glVertex2i(180,400);
glEnd();


//garden polygon
glColor3f(0/255.0,215/255.0,54/255.0);
glBegin(GL_POLYGON);
glVertex2i(0,300);
glVertex2i(35,280);
glColor3f(0/255.0,128/255.0,0/255.0);
glVertex2i(120,170);
//glVertex2i(80,60);
glVertex2i(190,80);
//glColor3f(0/255.0,130/255.0,0/255.0);
glColor3f(220/255.0,255/255.0,180/255.0);
glVertex2i(0,70);
glEnd();


//grey boundary
glColor3f(162/255.0,162/255.0,162/255.0);
glBegin(GL_POLYGON);
glVertex2i(0,0);
glVertex2i(0,70);
glColor3f(128/255.0,128/255.0,64/255.0);
glVertex2i(190,80);
glVertex2i(190,0);
glColor3f(111/255.0,111/255.0,111/255.0);
glVertex2i(0,70);
glEnd();

//hut
glColor3f(128/255.0,128/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(550,300);
glVertex2i(550,370);
glColor3f(191/255.0,191/255.0,0/255.0);
glVertex2i(475,430);
glVertex2i(400,370);
glVertex2i(400,310);
glVertex2i(550,300);
glEnd();
glColor3f(114/255.0,114/255.0,56/255.0);
glBegin(GL_POLYGON);
glVertex2i(475,430);
glVertex2i(550,370);
glColor3f(0/255.0,128/255.0,64/255.0);
glVertex2i(600,400);
glVertex2i(550,420);
glVertex2i(475,430);
glEnd();

glColor3f(86/255.0,86/255.0,44/255.0);
glBegin(GL_POLYGON);
glVertex2i(550,300);
glVertex2i(600,330);
glVertex2i(600,400);
glVertex2i(550,370);
glVertex2i(550,300);

glEnd();
//door
glColor3f(0/255.0,119/255.0,60/255.0);
glBegin(GL_POLYGON);
glVertex2i(425,307);
glVertex2i(525,300);
glColor3f(0/255.0,128/255.0,64/255.0);
glVertex2i(525,360);
glVertex2i(425,360);
glVertex2i(425,307);

glEnd();
//door
glColor3f(0/255.0,119/255.0,60/255.0);
glBegin(GL_POLYGON);
glVertex2i(425,307);
glVertex2i(525,300);
glVertex2i(525,360);
glVertex2i(425,360);
glVertex2i(425,307);
glEnd();

//door
glColor3f(0/255.0,119/255.0,60/255.0);
glBegin(GL_POLYGON);
glVertex2i(425,307);
glVertex2i(525,300);
glVertex2i(525,360);
glVertex2i(425,360);
glVertex2i(425,307);
glEnd();
glColor3f(128/255.0,128/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(465,305);
glVertex2i(475,305);
glVertex2i(475,360);
glVertex2i(465,360);
glVertex2i(465,305);
glEnd();

//ship-back
glColor3f(166/255.0,83/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(350,150);
glVertex2i(475,160);
glVertex2i(600,150);
glVertex2i(550,100);
glVertex2i(400,100);
glVertex2i(350,150);
glEnd();


//houseship
glColor3f(191/255.0,0/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(450,100);
glVertex2i(520,100);
glVertex2i(520,155);
glColor3f(255/255.0,174/255.0,174/255.0);
glVertex2i(485,175);
glVertex2i(450,155);
glVertex2i(450,100);

glEnd();

glColor3f(170/255.0,0/255.0,170/255.0);
glBegin(GL_POLYGON);
glVertex2i(520,155);
glVertex2i(485,175);
glVertex2i(520,180);
glVertex2i(545,160);
glVertex2i(520,155);

glEnd();
glColor3f(128/255.0,0/255.0,255/255.0);
glBegin(GL_POLYGON);
glVertex2i(470,100);
glVertex2i(500,100);
glColor3f(255/255.0,174/255.0,174/255.0);
glVertex2i(500,150);
glVertex2i(470,150);
glVertex2i(470,100);
glEnd();

glColor3f(128/255.0,0/255.0,255/255.0);
glBegin(GL_POLYGON);
glVertex2i(520,155);
glColor3f(255/255.0,174/255.0,174/255.0);
glVertex2i(545,160);
glVertex2i(545,100);
glVertex2i(520,100);
glVertex2i(520,155);
glEnd();

//men
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2i(410,200);
glVertex2i(430,200);
glVertex2i(430,230);
glVertex2i(410,230);
glVertex2i(410,200);
glEnd();

glColor3f(233/255.0,231/255.0,182/255.0);
glBegin(GL_POLYGON);
glVertex2i(410,205);
glVertex2i(410,200);
glVertex2i(430,200);
glVertex2i(435,200);
glVertex2i(410,205);
glEnd();
//t-shirt
glColor3f(233/255.0,124/255.0,241/255.0);
glBegin(GL_POLYGON);
glVertex2i(405,200);
glVertex2i(435,200);
glColor3f(255/255.0,100/255.0,177/255.0);
glVertex2i(435,170);
glVertex2i(405,170);
glVertex2i(405,200);
glEnd();
//pant
glColor3f(0/255.0,0/255.0,160/255.0);
glBegin(GL_POLYGON);
glVertex2i(405,170);
glVertex2i(400,150);
glVertex2i(415,150);
glVertex2i(420,160);
glVertex2i(425,150);
glVertex2i(440,150);
glVertex2i(435,170);
glVertex2i(405,170);
glEnd();
//tng
glColor3f(219/255.0,135/255.0,21/255.0);
glBegin(GL_POLYGON);
glVertex2i(404,150);
glVertex2i(404,100);
glVertex2i(413,100);
glVertex2i(413,150);
glVertex2i(404,150);
glEnd();

glColor3f(234/255.0,117/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(428,150);
glVertex2i(428,100);
glVertex2i(436,100);
glVertex2i(436,150);
glVertex2i(428,150);
glEnd();
//hand
glColor3f(219/255.0,135/255.0,21/255.0);
glBegin(GL_POLYGON);
glVertex2i(405,200);
glVertex2i(405,185);
glVertex2i(390,225);
glVertex2i(395,230);
glVertex2i(405,200);
glEnd();

//wood
glColor3f(128/255.0,128/255.0,64/255.0);
glBegin(GL_POLYGON);
glVertex2i(380,150);
glVertex2i(385,150);
glVertex2i(390,240);
glVertex2i(395,240);
glVertex2i(380,150);
//glVertex2i(405,200);
glEnd();

//ship
glColor3f(111/255.0,55/255.0,0/255.0);
glBegin(GL_POLYGON);
glVertex2i(400,100);
glVertex2i(550,100);
glVertex2i(600,150);
glVertex2i(475,130);
glVertex2i(350,150);
glVertex2i(400,100);
glEnd();

glColor3f(128/255.0,128/255.0,255/255.0);
glBegin(GL_LINE_STRIP);;
glVertex2i(300,90);
glVertex2i(500,90);
glEnd();
glBegin(GL_LINE_STRIP);;
glVertex2i(200,250);
glVertex2i(250,250);
glEnd();
glColor3f(128/255.0,128/255.0,255/255.0);
glBegin(GL_LINE_STRIP);;
glVertex2i(250,200);
glVertex2i(280,200);
glEnd();
glBegin(GL_LINE_STRIP);;
glVertex2i(320,50);
glVertex2i(450,50);
glEnd();
glBegin(GL_LINE_STRIP);;
glVertex2i(380,245);
glVertex2i(480,245);
glEnd();
glBegin(GL_LINE_STRIP);;
glVertex2i(540,30);
glVertex2i(640,30);
glEnd();
glBegin(GL_LINE_STRIP);;
glVertex2i(540,200);
glVertex2i(640,200);
glEnd();


//stones
glColor3f(184/255.0,184/255.0,112/255.0);
moon(20,0,300,10,90);
moon(20,10,300,10,90);
moon(20,30,290,15,90);
moon(20,35,280,10,90);
moon(20,60,270,20,90);
moon(20,90,260,18,90);
moon(20,70,240,12,90);

moon(20,90,250,20,90);
moon(20,100,230,15,90);
moon(20,100,220,20,90);
moon(20,100,200,18,90);
moon(20,105,180,12,90);
moon(20,110,200,25,90);

moon(20,120,150,20,90);
moon(20,140,180,18,90);
moon(20,150,140,20,90);
moon(20,180,110,25,90);
moon(20,190,80,10,90);
moon(20,10,80,15,90);
moon(20,45,80,25,90);
moon(20,80,60,13,90);
moon(50,85,90,20,90);
moon(20,120,80,18,90);
moon(30,100,70,10,90);
moon(20,160,80,20,90);
moon(20,150,78,10,90);
moon(20,0,50,15,90);
moon(20,30,50,15,90);
moon(20,60,50,10,90);
moon(20,30,60,20,90);
moon(20,130,60,15,90);
moon(20,140,90,10,90);
glEnd();



//glColor3f(34/255,64/255,23/255);
//glColor3f(34/255,64/255,30/255);

glEnd();
glFlush();

}

int main(int argc,CHAR**argv)
{
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


