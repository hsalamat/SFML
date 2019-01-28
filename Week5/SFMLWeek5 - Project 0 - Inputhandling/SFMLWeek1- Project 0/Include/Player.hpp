#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML\Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Player
{

public:
	enum Type
	{
		Eagle,
		Raptor,
	};


public:
	Player();


	sf::Sprite& getSprite();

private:
	sf::Sprite mSprite;
	sf::Texture texture2;

};

