#pragma once
#include "SceneNode.hpp"


class Entity : public SceneNode

{
public:
	virtual	void		updateCurrent(sf::Time dt);

	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	sf::Vector2f		getVelocity() const;


public:
	sf::Vector2f		mVelocity;
};



