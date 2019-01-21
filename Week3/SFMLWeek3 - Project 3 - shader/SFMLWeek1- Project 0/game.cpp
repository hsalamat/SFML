#include"Include/Game.hpp"

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
	, airplane()
	, landscape()
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
#pragma region step 2
	, mTexture()
	, mShader()
{
	mTexture.create(winW, winH);
	mSprite.setTexture(mTexture);
	mSprite.setPosition(200, 200);

	mShader.loadFromFile("fire.glsl", sf::Shader::Fragment); // load the shader

	if (!mShader.isAvailable()) {
		std::cout << "The shader is not available\n";
	}

	// Set the resolution parameter (the resoltion is divided to make the fire smaller)
	mShader.setUniform("resolution", sf::Vector2f(winW / 2, winH / 2));
#pragma endregion

	try
	{
		textures.load(Textures::Landscape, "Media/Textures/Desert.png");
		textures.load(Textures::Airplane, "Media/Textures/Eagle.png");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return;
	}

	if (!mFont.loadFromFile("Media/Sansation.ttf")) return;
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
	mStatisticsText.setFillColor(sf::Color::Black);


	mBackgroundTexture = textures.get(Textures::Landscape);
	mBackgroundTexture.setRepeated(true);
	landscape.setTexture(mBackgroundTexture);
	landscape.setTextureRect(sf::IntRect(0, 0, 1200, 800));

	airplane.setTexture(textures.get(Textures::Airplane));
	airplane.setPosition(100.f, 100.f);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
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

void Game::update(sf::Time elapsedTime)
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

	airplane.move(movement * elapsedTime.asSeconds());

#pragma region step3
	// Use a timer to obtain the time elapsed
	sf::Clock clk;
	clk.restart(); // start the timer
	// Set the others parameters who need to be updated every frames
	mShader.setUniform("time", clk.getElapsedTime().asSeconds());

	sf::Vector2i mousePos = sf::Mouse::getPosition(mWindow);
	mShader.setUniform("mouse", sf::Vector2f(mousePos.x, mousePos.y- winH - 200));
#pragma endregion
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(landscape);
	mWindow.draw(airplane);
	mWindow.draw(mStatisticsText);

#pragma region step4
	// Draw the sprite with the shader on it
	mWindow.draw(mSprite, &mShader);
#pragma endregion

	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + to_string(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
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
