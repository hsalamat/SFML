#pragma once
#include "SceneNode.hpp"


class Entity : public SceneNode

{
public:
	virtual	void		updateCurrent(sf::Time dt);

	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	sf::Vector2f		getVelocity() const;

#pragma region step 4
	void				accelerate(sf::Vector2f velocity);
	void				accelerate(float vx, float vy);
#pragma endregion

public:
	sf::Vector2f		mVelocity;
};



