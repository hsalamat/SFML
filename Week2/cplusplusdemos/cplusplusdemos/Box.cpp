#include "Box.hpp"

//member initializer list
Box::Box(int width, int length, int height) : mWidth(width), mLength(length), mHeight(height)
{

}

Box::Box() : mWidth(1), mLength(1), mHeight(1)
{
}


Box::~Box()
{
}
