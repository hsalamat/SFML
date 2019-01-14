#include "Include/Game.hpp"


Game::Game()
#pragma region Step2
	: mWindow(sf::VideoMode(800, 600), "SFML Application", sf::Style::Close)
	, mTexture()
	, mBackground()
	, mPlayer()
	,mTexture2()
	,mPlayer2(sf::Vector2f(200.0f, 200.0f))
	,mPolygon()
#pragma endregion

{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);



#pragma region Step3
	//Comment out the following section
	mPlayer2.setPosition(150.f, 150.f);
	mPlayer2.setSize(sf::Vector2f(100, 100));  //change the size of airplane "Eagle"
	mPlayer2.setOutlineColor(sf::Color::Red);
	mPlayer2.setOutlineThickness(5);

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

	mPolygon.setPointCount(3);
	mPolygon.setPoint(0, sf::Vector2f(0, 0));
	mPolygon.setPoint(1, sf::Vector2f(0, 50));
	mPolygon.setPoint(2, sf::Vector2f(50, 50));
	mPolygon.setFillColor(sf::Color::Magenta);
	mPolygon.setOutlineColor(sf::Color::Red);
	mPolygon.setOutlineThickness(5);
	mPolygon.setPosition(400, 400);

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
	mWindow.draw(mPolygon);
#pragma endregion

	mWindow.draw(mPlayer);
	mWindow.display();
}



