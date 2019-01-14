#pragma once
#include <iostream>
using namespace std;
class Box
{
	double width;
	double length;
public:
	Box();
	~Box();
	friend void printWidth(Box box);
	void setWidth(double wid);
};


