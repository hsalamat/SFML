#include "Include/Game.hpp"


Game::Game()
#pragma region Step2
	: mWindow(sf::VideoMode(800, 600), "SFML Application", sf::Style::Close)
	, mTexture()
	, mBackground()
	, mPlayer()
	,mTexture2()
	,mPlayer2(sf::Vector2f(200.0f, 200.0f))
#pragma endregion

{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);



#pragma region Step3
	//Comment out the following section
	mPlayer2.setPosition(150.f, 150.f);
	if (!mTexture2.loadFromFile("Media/Textures/Eagle.png"))
		return;
	mPlayer2.setTexture(&mTexture2);


	if (!mTexture.loadFromFile("Media/Textures/Desert.png")) 
		return;
	mTexture.setRepeated(true);
	mBackground.setTexture(mTexture);
	// Define a rectangle, located at (0, 0) with a size of 800X600
	//Comment out the following section to see the difference
	mBackground.setTextureRect(sf::IntRect(0, 0, 800, 600));
#pragma endregion
}

void Game::run()
{

	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	mWindow.clear();

#pragma region Step4
	mWindow.draw(mBackground);
	mWindow.draw(mPlayer2);
#pragma endregion

	mWindow.draw(mPlayer);
	mWindow.display();
}



