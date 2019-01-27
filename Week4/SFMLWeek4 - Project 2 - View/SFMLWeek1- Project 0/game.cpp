#include "Include/Game.hpp"


const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "Views", sf::Style::Close)
	, landscape()
	, airplane()
	, textures()
	, mTexture()
	, mPlayer()
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
#pragma region step4
	// let's define a view
	, mView(mWindow.getDefaultView())
	, mWorldBounds(0.f, 0.f, mView.getSize().x, 4000.f)
	, mSpawnPosition(mView.getSize().x / 2.f, mWorldBounds.height - mView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
	, transform()
	, states()
	, quad(sf::Quads, 4)  	// create a quad using VertexArray
#pragma endregion
{
	// Prepare the view
	mView.setCenter(mSpawnPosition);


	mWindow.setFramerateLimit(20);

	vertices[0] = sf::Vertex(sf::Vector2f(5, 5), sf::Color::Red);
	vertices[1] = sf::Vertex(sf::Vector2f(5, 600), sf::Color::Red);
	vertices[2] = sf::Vertex(sf::Vector2f(600, 600), sf::Color::Red);
	vertices[3] = sf::Vertex(sf::Vector2f(600, 5), sf::Color::Red);
	vertices[4] = sf::Vertex(sf::Vector2f(5, 5), sf::Color::Red);



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

	try
	{
		textures.load(Textures::Landscape, "Media/Textures/Desert.png");
		textures.load(Textures::Airplane, "Media/Textures/Eagle.png");
		mFont.loadFromFile("Media/Sansation.ttf");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


#pragma region step5

	// Prepare the tiled background
	sf::Texture& texture = textures.get(Textures::Landscape);
	texture.setRepeated(true);
	landscape.setTexture(texture);
	landscape.setTextureRect(sf::IntRect(mWorldBounds));

	//let's change the zoom to 0.2 or 2. sf::View::zoom(float factor) function to easily approach or moveaway from the center of the view
	//mView.zoom(0.2);

	//sf::View::rotate(float degree) to add a rotation angle to the current one sf::View::setRotation(float degrees) to set the rotation of the view to an absolute value
	//mView.rotate(45);



#pragma endregion

	airplane.setTexture(textures.get(Textures::Airplane));
	airplane.setPosition(100.f, 100.f);

	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(10.f, 10.f);
	mStatisticsText.setCharacterSize(15);
	mStatisticsText.setFillColor(sf::Color::Green);

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

#pragma region step 5
	// Scroll the world
	mView.move(0.f, mScrollSpeed * elapsedTime.asSeconds());
#pragma endregion

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
}

void Game::render()
{
	mWindow.clear();
#pragma region step 6

	//scrolling all screen
	//mView.setViewport(sf::FloatRect(0, 0, 1, 1));
	mWindow.setView(mView);
	mWindow.draw(landscape);

	//Top Half
	//mView.setViewport(sf::FloatRect(0, 0, 1, 0.5));
	//mWindow.setView(mView);
	//mWindow.draw(landscape);


	//Bottom Half
	//mView.setViewport(sf::FloatRect(0, 0.5, 1, 0.5));
	//mWindow.setView(mView);
	//mWindow.draw(landscape);

	//Left half
	//mView.setViewport(sf::FloatRect(0, 0, 0.5, 1));
	//mWindow.setView(mView);
	//mWindow.draw(landscape);

	//Right half
	//mView.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));
	//mWindow.setView(mView);
	//mWindow.draw(landscape);


	//Left half shows different background
	//sf::View mView2;
	//mView2 = mWindow.getDefaultView();
	//mView2.setViewport(sf::FloatRect(0, 0, 0.5, 1));
	//mWindow.setView(mView2);
	//sf::RectangleShape shape(sf::Vector2f(mView2.getSize().x, 4000.f));
	//shape.setFillColor(sf::Color::Yellow);
	//mWindow.draw(shape);

	// mini-map (upper-right corner)
	/*sf::View minimapView;
	minimapView.setViewport(sf::FloatRect(0.75f, 0.1f, 0.25f, 0.25f));
	mWindow.setView(minimapView);
	mWindow.draw(vertices, 5, sf::LinesStrip);
	mWindow.draw(quad, states);
	mWindow.draw(airplane);
	mWindow.draw(player.getSprite());
	mWindow.draw(player2);
	mWindow.draw(mStatisticsText);*/


	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(airplane);
	mWindow.draw(player.getSprite());
	mWindow.draw(player2);
	mWindow.draw(mStatisticsText);

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

	if (key == sf::Keyboard::Up)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::Down)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::Left)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::Right)
		mIsMovingRight = isPressed;
}






