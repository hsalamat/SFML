#include "Include/Game.hpp"



Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
	, mPlayer()
	, mPlayer2(sf::Vector2f(100.0f, 100.0f))
	, mTexture()
	, background()
{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
	// set a 10-pixel wide orange outline
	mPlayer.setOutlineThickness(10.f);
	mPlayer.setOutlineColor(sf::Color(250, 150, 100));
	mPlayer.setPointCount(8);

	mPlayer2.setPosition(200.f, 200.f);
	mPlayer2.setFillColor(sf::Color::Yellow);

	if (!mTexture.loadFromFile("Media/Textures/Desert.png")) cout << "cannot find the png file";
	mTexture.setRepeated(true);

	background.setTexture(mTexture);
	background.setTextureRect(sf::IntRect(0, 0, 800, 600));
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
	mWindow.draw(background);
	mWindow.draw(mPlayer);
	mWindow.draw(mPlayer2);
	mWindow.display();
}



