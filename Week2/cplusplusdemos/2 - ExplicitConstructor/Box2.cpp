#include "Box2.hpp"


Box2::Box2(int size): mWidth(size), mLength(size), mHeight(size){}

Box2::Box2(int width, int length, int height) : mWidth(width), mHeight(height), mLength(length)
{
}


Box2::Box2(): mWidth(1), mLength(1), mHeight(1)
{
}


Box2::~Box2()
{
}


int Box2::Volume() {
	return mWidth*mHeight*mLength;
}


