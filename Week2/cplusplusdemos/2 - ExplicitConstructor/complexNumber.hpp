#pragma once
class complexNumber
{
public:
	complexNumber();
	~complexNumber();
	complexNumber(const complexNumber&);
	complexNumber(double, double i = 0.0);

	friend void display(complexNumber);
private:
	double real, img;
};

