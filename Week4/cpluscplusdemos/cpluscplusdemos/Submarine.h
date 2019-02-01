#pragma once
#include "DivingEntity.h"
#include "ArmedEntity.h"
class Submarine :
	public DivingEntity, public ArmedEntity
{
public:
	Submarine();
	~Submarine();
};

