#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "SFML/Graphics.hpp"

class Entity : public sf::Drawable, public sf::Transformable

{
public:
	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	sf::Vector2f		getVelocity() const;

	virtual	void		update(sf::Time dt);
	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	sf::Vector2f		mVelocity;
};


