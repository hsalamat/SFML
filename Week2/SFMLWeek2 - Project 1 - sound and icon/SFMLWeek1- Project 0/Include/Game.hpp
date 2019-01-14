#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	sf::CircleShape			mPlayer;
	sf::Sprite				mBackground;
	sf::Texture				mTexture;

#pragma region Step 1
	//Set the Icon
	sf::Image mIcon;
	sf::Image mImage;
	sf::Image mImage2;
	//Create a graphical text to display
	sf::Font mFont;
	sf::Text mText;

	sf::Music mMusic;
#pragma endregion

};

#endif // BOOK_GAME_HPP
