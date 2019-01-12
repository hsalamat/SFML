#include "complexNumber.hpp"

complexNumber::complexNumber() :real(0), img(0)
{
}

complexNumber::complexNumber(const complexNumber& c)
{
	real = c.real;
	img = c.img;
}
complexNumber::complexNumber(double r, double i)
{
	real = r;
	img = i;
}


complexNumber::~complexNumber()
{
}



