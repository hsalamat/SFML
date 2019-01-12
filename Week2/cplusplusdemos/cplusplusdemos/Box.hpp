#pragma once
class Box
{
public:
	//constructors
	Box();
	~Box();

	Box(int, int, int);

	//class methods
	int Volume() {
		return mWidth*mHeight*mLength;
	}
private:
	int mWidth;
	int mLength;
	int mHeight;
};

