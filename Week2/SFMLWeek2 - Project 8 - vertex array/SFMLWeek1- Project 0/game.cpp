#include "Include/Game.hpp"


Game::Game()
	: mWindow(sf::VideoMode(800, 600), "SFML Application", sf::Style::Close)
	, mTexture()
	, mBackground()
	, mPlayer()
	,mTexture2()
	,mPlayer2(sf::Vector2f(200.0f, 200.0f))
	,mPolygon()
#pragma region Step2
	,transform()
	,states()
	, quad(sf::Quads, 4)  	// create a quad using VertexArray
#pragma endregion

{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);

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

#pragma region Step3
	// Limit the framerate to 60 frames per second (this step is optional)
	mWindow.setFramerateLimit(60);
	vertices[0] = sf::Vertex(sf::Vector2f(0, 0), sf::Color::Red);
	vertices[1] = sf::Vertex(sf::Vector2f(0, 100), sf::Color::Red);
	vertices[2] = sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red);
	vertices[3] = sf::Vertex(sf::Vector2f(100, 0), sf::Color::Red);
	


	// define it as a rectangle, located at (10, 10) and with size 100x100
	quad[0].position = sf::Vector2f(10, 10);
	quad[1].position = sf::Vector2f(110, 10);
	quad[2].position = sf::Vector2f(110, 110);
	quad[3].position = sf::Vector2f(10, 110);

	// define its color to be a 25x50 rectangle starting at (0, 0)
	quad[0].color = sf::Color::Blue;
	quad[1].color = sf::Color::Blue;
	quad[2].color = sf::Color::Blue;
	quad[3].color = sf::Color::Blue;

	states.transform = transform.translate(300.0, 300.0);
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


	mWindow.draw(mBackground);
	mWindow.draw(mPlayer2);
	mWindow.draw(mPolygon);

#pragma region Step4
	mWindow.draw(vertices, 4, sf::Quads);
	mWindow.draw(quad, states);
#pragma endregion

	mWindow.draw(mPlayer);
	mWindow.display();
}



