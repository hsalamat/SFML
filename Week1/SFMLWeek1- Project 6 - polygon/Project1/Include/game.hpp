#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Game : private sf::NonCopyable
{
public:
	Game();
	void					run();


private:
	void					processEvents();
	void					update();
	void					render();


private:

	sf::RenderWindow		mWindow;
	sf::CircleShape				mPlayer;
	sf::RectangleShape				mPlayer2;
	sf::Texture mTexture;
	sf::Sprite background;
};
