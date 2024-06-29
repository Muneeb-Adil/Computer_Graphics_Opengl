// dino_xy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Windows.h>
#include<glut.h>
#include<fstream>
#include<math.h>
#include<iostream>
using namespace std;


void myInit(void)
{
	glClearColor(0,0,1,0);
	glColor3f(0,1,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
 	glViewport(0,640,0,480);
}

void drawPolyLineFile(char * fileName)
{
	fstream inStream;
	inStream.open(fileName,ios::in);
	if(inStream.fail())
		return;
	GLint numpolys,numLines,x,y;
	inStream>>numpolys;
	for(int j=0;j<numpolys;j++)
	{
		inStream>>numLines;
		glBegin(GL_LINE_STRIP);
		for(int i=0;i<numLines;i++)
		{
			inStream >> x >> y;
			glVertex2i(x,y);
		}
		glEnd();
	    glFlush();
	}
	glFlush();
	inStream.close();
}


void Display(void)
{ 
	int c=0;
	for(int i=0;i<100;i=i+5)
	{
	 glViewport(i*25,640-c,70,90);

	drawPolyLineFile("dino.dat");
	c=c+60;
	}
		glFlush();
}
	
int main(int argc,CHAR** argv)

{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutCreateWindow("Ramsha");
glutInitWindowPosition(640,480);
glutDisplayFunc(Display);
myInit();
glutMainLoop();

	return 0;
}



