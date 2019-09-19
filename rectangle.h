#pragma once
//program 2.1: definition of C++ class Rectangle

//header, cpp ���Ϸ� separate compilation�� �ǽ�
//visual studio�� project ������ ���Ͽ� �����ϴ� ���� �ʿ���
#include <iostream>
using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	Rectangle();
	Rectangle(int x, int y, int h, int w);
	~Rectangle();
	int GetHeight();
	int GetWidth();
	bool operator == (const Rectangle& s);
	friend ostream& operator << (ostream& os, Rectangle& r);

private:
	int xLow, yLow, height, width;
};

Rectangle::Rectangle() {}
Rectangle::~Rectangle() {}

//Rectangle::Rectangle(int x=0, int y=0, int h=0, int w=0) : xLow(x), yLow(y),height(h),width(w){}

Rectangle::Rectangle(int x, int y, int h, int w)
{
	xLow = x;
	yLow = y;
	height = h;
	width = w;
}
#endif
