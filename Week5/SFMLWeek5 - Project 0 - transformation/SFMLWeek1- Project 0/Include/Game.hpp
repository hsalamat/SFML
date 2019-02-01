#pragma once

#include "ResourceHolder.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


#include "ResourceIdentifiers.hpp"
#include "Aircraft.hpp"



class Game : private sf::NonCopyable
{
public:
	Game();
	void					run();

private:
	void					processEvents();
	void					update(sf::Time elapsedTime);
	void					render();
	void					updateStatistics(sf::Time elapsedTime);

private:
	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;

	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	sf::Sprite				landscape;

	sf::View				mView;
	sf::FloatRect			mWorldBounds;
	sf::Vector2f			mSpawnPosition;
	float					mScrollSpeed;

	TextureHolder mTextures;
	Aircraft*			mPlayer;

	std::size_t				mStatisticsNumFrames;
};


