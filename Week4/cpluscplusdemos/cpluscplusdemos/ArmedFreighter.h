#pragma once
#include "TransportEntity.h"
#include "ArmedEntity.h"
class ArmedFreighter :
	public TransportEntity, public ArmedEntity
{
public:
	ArmedFreighter();
	~ArmedFreighter();
	virtual void setVelocity(float);
};

