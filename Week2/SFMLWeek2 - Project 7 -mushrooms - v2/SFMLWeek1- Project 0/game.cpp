#include "Include/Game.hpp"
#include <iomanip>
#include <sstream>

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() 
	: mWindow("Bouncing Mushrooms", sf::Vector2u(800, 600)) 
	, mFont()
	, mStatisticsText()
	, mIncrement(sf::Vector2i(400, 400))
{
	RestartClock();
	srand(time(NULL));

	// Setting up class members.
	mushroomTexture.loadFromFile("Media/Textures/Mushroom.png");
	mMushroom.setTexture(mushroomTexture);
	;

	mFont.loadFromFile("Media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}

Game::~Game() { }

sf::Time Game::GetElapsed() { return mElapsed; }
void Game::RestartClock() { mElapsed = mClock.restart(); }
Window* Game::GetWindow() { return &mWindow; }

void Game::HandleInput() {
	// Input handling.
}

void Game::Update() {
	mWindow.Update();
	MoveMushroom(mElapsed);
}

void Game::MoveMushroom(sf::Time elapsedTime) {
	sf::Vector2u l_windSize = mWindow.GetWindowSize();
	sf::Vector2u l_textSize = mushroomTexture.getSize();

	if ((mMushroom.getPosition().x >
		l_windSize.x - l_textSize.x && mIncrement.x > 0) ||
		(mMushroom.getPosition().x < 0 && mIncrement.x < 0)) {
		mIncrement.x = -mIncrement.x;
	}

	if ((mMushroom.getPosition().y >
		l_windSize.y - l_textSize.y && mIncrement.y > 0) ||
		(mMushroom.getPosition().y < 0 && mIncrement.y < 0)) {
		mIncrement.y = -mIncrement.y;
	}

	float fElapsed = elapsedTime.asSeconds();

	mMushroom.setPosition(
		mMushroom.getPosition().x + (mIncrement.x * fElapsed),
		mMushroom.getPosition().y + (mIncrement.y * fElapsed));

}

void Game::updateStatistics()
{
	mStatisticsUpdateTime += mElapsed;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		stringstream stream1, stream2;
		stream1 << mStatisticsNumFrames;
		stream2 << mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames;

		mStatisticsText.setString(
			"Frames / Second = " + stream1.str() + "\n" +
			"Time / Update = " + stream2.str() + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}

void Game::Render() {
	mWindow.BeginDraw(); // Clear.
	mWindow.Draw(mMushroom);
	mWindow.Draw(mStatisticsText);
	mWindow.EndDraw(); // Display.
}