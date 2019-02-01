#include "Include/Aircraft.hpp"

Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
	case Aircraft::Eagle:
		return Textures::Eagle;
	case Aircraft::Raptor:
		return Textures::Raptor;
	}
	return Textures::Eagle;
}

Aircraft::Aircraft(Type type, const TextureHolder& textures)
{

	//connecting entities with resources

	mType = type;
	mSprite.setTexture(textures.get(toTextureID(type)));
	sf::FloatRect bounds = mSprite.getLocalBounds();
	//by default, the origin of sprites is located in their upper-left corner
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	//mSprite.setPosition(200, 200);
}

sf::Sprite& Aircraft::getSprite()
{
	return mSprite;
}



void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}