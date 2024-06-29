#include<iostream>
#include <gl/glut.h>
#include <GL/RGBpixmap.h>
class Point2 {
	float x, y;
public:
	Point2() { x = y = 0.0f; }
	Point2(float xx, float yy) {
		x = xx;
		y = yy;
	}
	void set(float xx, float yy) {
		x = xx;
		y = yy;
	}
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	void darw(void) {
		glPointSize(2.0);
		glEnable(2.0);
		glBlendFunc();
		glBegin(GL_POINTS);
			glVertex2f(x, y);
		glEnd();
	}
};
class Spider
{
private:
	enum state {DIE} state;
	RGBpixmap pix[2];
	float pos_X, pos_Y;
public:
	bool ismoving;
	float sspeed;
	float theta;
	float rate_change;
	Spider();
	Spider(Point2 pos) {
		ismoving = true;
		sspeed = 400.0f;
		theta = 0.0f;
		rate_change = 1.0;
		pos_X = 0.0;
		pos_Y = 0.0;
		string fname[2] = {"spider.temp",""}
		for (int i = 0; i <= 1;i++) {
			pix[i].readBmpFile;
			pix[i].setChange
			}
	};
	float spider_getX() {
		return pos_X;
	};
	float spider_getY() {
		return pos_X;
	};
	void changePosition(float dx, float dy) {
		pos_X = pos_X + dx;
		pos_Y = pos_Y + dy;
	};
	void render() {
		if (this->is_moving) {
			glRasterPos2i()
				pix[0].mDraw();
		}
		else {
			pix[1].mDraw();
		}
	}


};