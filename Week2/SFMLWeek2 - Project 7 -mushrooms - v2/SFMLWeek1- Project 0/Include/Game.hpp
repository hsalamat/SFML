#pragma once
#include "Window.hpp"
#include <iostream>
using namespace std;

class Game {
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void updateStatistics();
	void Render();

	Window* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();
private:
	void MoveMushroom(sf::Time elapsedTime);

	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;
	Window				 mWindow;
	sf::Clock			 mClock;
	sf::Time			 mElapsed;

	sf::Texture			 mushroomTexture;
	sf::Sprite			 mMushroom;
	sf::Vector2i		 mIncrement;

	sf::Font			 mFont;
	sf::Text			 mStatisticsText;
	sf::Time			 mStatisticsUpdateTime;
	std::size_t			 mStatisticsNumFrames;
};

