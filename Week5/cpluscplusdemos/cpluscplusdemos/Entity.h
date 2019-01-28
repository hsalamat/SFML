#pragma once
#include <string>
#include <iostream>
using namespace std;
class Entity
{
public:
	Entity();
	~Entity();
	virtual void setVelocity(float);
	virtual float getVelocity();
private:
	float mVelocity;
};

