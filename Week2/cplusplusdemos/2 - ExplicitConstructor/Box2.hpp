#pragma once

//default constructor
class A
{

};


class Box2
{
public:
	Box2();
	~Box2();
	//implicit constructor
	//such conversions can be useful in some cases.
	//Box2(int);

	//As a general rule, you should use the explicit keyword
	//Explicit constructor
	explicit Box2(int);

	Box2(int, int, int);

	int Volume();

private:
	int mWidth, mLength, mHeight;
};

