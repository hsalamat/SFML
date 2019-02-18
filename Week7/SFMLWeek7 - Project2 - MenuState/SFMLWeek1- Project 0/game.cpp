#include "Include/Game.hpp"
#include <SFML/Window/Event.hpp>

#pragma region step 3
#include "Include/MenuState.hpp"
#pragma endregion

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);


Game::Game()
	: mWindow(sf::VideoMode(640, 480), "Title State", sf::Style::Close)
	, mFonts()
	, mPlayer()
	, mTextures()
	, mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer))
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
{
	//If key repeat is enabled, you will receive repeated KeyPressed events while keeping a key pressed. If it is disabled, you will only get a single event when the key is pressed. Key repeat is enabled by default
	mWindow.setKeyRepeatEnabled(false);

	mFonts.load(Fonts::Main, "Media/Sansation.ttf");
	mTextures.load(Textures::TitleScreen, "Media/Textures/TitleScreen.png");

	mStatisticsText.setFont(mFonts.get(Fonts::Main));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10u);

	registerStates();
	mStateStack.pushState(States::Title);
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
#pragma region step 6
			// Check inside this loop, because stack might be empty before update() call
			if (mStateStack.isEmpty())
				mWindow.close();
#pragma endregion

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
		mStateStack.handleEvent(event);
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}
#pragma endregion

void Game::update(sf::Time elapsedTime)
{
	mStateStack.update(elapsedTime);
}

void Game::render()
{
	mWindow.clear();
	mStateStack.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
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
			"Time / Update = " + to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us" + "\n" 
					);

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::registerStates()
{
	mStateStack.registerState<TitleState>(States::Title);
#pragma region step 4
	mStateStack.registerState<MenuState>(States::Menu);
#pragma endregion
}

