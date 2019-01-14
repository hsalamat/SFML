#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>


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
	sf::RectangleShape		mPlayer2;
	sf::Texture				mTexture2;
	sf::ConvexShape		    mPolygon;

#pragma region Step 1
	sf::Transform transform;
	sf::RenderStates states;
 	// define a 100x100 square, red, with a 10x10 texture mapped on it
	sf::Vertex vertices[4]; 
	sf::VertexArray quad;
#pragma endregion

};

#endif // BOOK_GAME_HPP
