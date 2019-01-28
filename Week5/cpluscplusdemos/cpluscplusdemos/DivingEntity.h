#pragma once
#include "Entity.h"
class DivingEntity :
	public Entity
{
public:
	DivingEntity();
	~DivingEntity();
	virtual void setVelocity(float);
};

