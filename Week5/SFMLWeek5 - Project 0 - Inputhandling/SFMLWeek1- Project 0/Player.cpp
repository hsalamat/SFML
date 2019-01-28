#include "Include/Player.hpp"

Player::Player()
{

	if (!texture2.loadFromFile("Media/Textures/Eagle.png"))
	{
		// Handle loading error
	}

	mSprite.setTexture(texture2);
	mSprite.setPosition(200.f, 200.f);
}

sf::Sprite& Player::getSprite()
{
	return mSprite;
}
