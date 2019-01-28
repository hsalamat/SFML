#include "Entity.h"

const Component * Entity::GetComponent(const std::string & family) const
{
	return nullptr;
}

void Entity::SetComponent(Component * newComp)
{
}

void Entity::RemoveComponent(const std::string & family)
{
}

void Entity::ClearComponents()
{
}

bool Entity::HasProperty(const std::string & propName) const
{
	return false;
}

const unsigned int Entity::GetID() const
{
	return 0;
}

void Entity::Update(float dt)
{
}

void Entity::RemoveProperty(const std::string & propName)
{
}

void Entity::ClearProperties()
{
}

