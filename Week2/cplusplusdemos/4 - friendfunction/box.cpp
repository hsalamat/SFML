#include "box.hpp"

Box::Box()
{
	length = 0.f;
	width = 0.f;
}


Box::~Box()
{
}

void printWidth(Box box) {
	cout << "Length of the box is: " << box.length << endl;
	cout << "Width of the box is: " << box.width << endl;
}
void Box::setWidth(double wid) {
	width = wid;
}




