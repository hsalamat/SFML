#pragma once

#pragma region step 10
#include <SFML/Window/Keyboard.hpp>
// Convert enumerators to strings
std::string toString(sf::Keyboard::Key key);
#pragma endregion

namespace sf
{
	class Sprite;
	class Text;
}
void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

