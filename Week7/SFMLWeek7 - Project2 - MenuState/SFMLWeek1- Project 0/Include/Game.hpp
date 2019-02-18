#pragma once
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "Player.hpp"
#include "StateStack.hpp"
#include "Utility.hpp"
#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "TitleState.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
using namespace std;


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
	void					registerStates();

private:
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	TextureHolder			mTextures;
	FontHolder				mFonts;
	Player					mPlayer;

	StateStack				mStateStack;
#pragma endregion

	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;
};


