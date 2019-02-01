#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}


void Entity::setVelocity(float velocity) {
	mVelocity = velocity;
}

float Entity::getVelocity() {
	return mVelocity;
}