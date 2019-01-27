#pragma once

#include <SFML\Graphics.hpp>
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
#include "Entity.hpp"

class Player2 : public Entity

{

public:
	enum Type
	{
		Eagle,
		Raptor,
	};


public:
	Player2();

	sf::Sprite& getSprite();

	//The first parameter specifies, where the drawable object is drawn to. Mostly, this will be a sf::RenderWindow. 
	//The second parameter contains additional information for the rendering process, such as blend mode (how pixel of the object are blened, transform (how the object is positioned/rotated/scaled), the used texture (what image is mapped to the object), or shader (what custom effects applied to the object). 
	//SFML's high-level classes Sprite, Text, and Shape are all derived fromTransformable and Drawable.

	virtual	void draw(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	sf::Sprite mSprite;
	sf::Texture texture2;

};

