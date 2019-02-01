#include "Include/Entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::update(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Apply transform of current node
	states.transform *= getTransform();

	// Draw node with changed transform
	drawCurrent(target, states);
}


void Entity::drawCurrent(sf::RenderTarget&, sf::RenderStates) const
{
	// Do nothing by default
}
