#include "Include/Game.hpp"

#pragma region Step 2
const float Game::PlayerSpeed = 100.f;
#pragma endregion

Game::Game()
	: mWindow(sf::VideoMode(800, 600), "SFML Application", sf::Style::Close)
	, mTexture()
	, mBackground()
	, mAirplaneTexture()
	, mPlayer()
	, mMusic()
	, mFont()
	, mIcon()
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)

{

	if (!mAirplaneTexture.loadFromFile("Media/Textures/Eagle.png"))
	{
		// Handle loading error
	}

	mPlayer.setTexture(mAirplaneTexture);
	mPlayer.setPosition(100.f, 100.f);


	mIcon.loadFromFile("Media/Textures/icon.png");
	mWindow.setIcon(mIcon.getSize().x, mIcon.getSize().y, mIcon.getPixelsPtr());

	//Load a sprite to display
	if (!mTexture.loadFromFile("Media/Textures/cute_image.jpg"))
		return;
	mBackground.setTexture(mTexture);

	if (!mFont.loadFromFile("Media/Sansation.ttf"))
		return;


	mText.setString("Hello SFML");
	mText.setFont(mFont);
	mText.setPosition(5.f, 5.f);
	mText.setCharacterSize(50);
	mText.setFillColor(sf::Color::Black);

	
	mMusic.openFromFile("Media/Textures/nice_music.ogg");
	//Play the music
	mMusic.play();



}

void Game::run()
{

#pragma region Step 4

	sf::Clock clock;
	while (mWindow.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		processEvents();
		update(deltaTime);
		render();
	}
#pragma endregion
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{

		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;


		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}


#pragma region step 3
void Game::update(sf::Time deltaTime)
	{
		sf::Vector2f movement(0.f, 0.f);
		if (mIsMovingUp)
			movement.y -= PlayerSpeed;
		if (mIsMovingDown)
			movement.y += PlayerSpeed;
		if (mIsMovingLeft)
			movement.x -= PlayerSpeed;
		if (mIsMovingRight)
			movement.x += PlayerSpeed;
		mPlayer.move(movement * deltaTime.asSeconds());
	}

#pragma endregion


void Game::render()
{
	mWindow.clear();
	mWindow.draw(mBackground);
	mWindow.draw(mPlayer);
	mWindow.draw(mText);

	//Update the window
	mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}


