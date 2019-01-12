#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game : private sf::NonCopyable
{
public:
	Game();
	void					run();


private:
	void					processEvents();
	void					update();
	void					render();
	void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:

	sf::RenderWindow		mWindow;
	sf::Sprite				mPlayer;
	sf::Sprite				mBackground;
	sf::Texture				mTexture;
	sf::Texture				mAirplaneTexture;
	sf::Image				mIcon;

	//Create a graphical text to display
	sf::Font mFont;
	sf::Text mText;

	sf::Music mMusic;

	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingRight;
	bool					mIsMovingLeft;

};

#endif // BOOK_GAME_HPP
