#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#pragma comment(lib,"opengl32.lib")

#pragma comment(lib,"glu32.lib")

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

	// Create a clock for measuring time elapsed
	sf::Clock Clock;

	bool rotate;

	float angle;
};

#endif // BOOK_GAME_HPP
