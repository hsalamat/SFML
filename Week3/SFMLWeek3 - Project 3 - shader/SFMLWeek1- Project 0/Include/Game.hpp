#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include <iostream>
using namespace std;

namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
	};
}

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
		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		

	private:
		static const float		PlayerSpeed;
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;

		sf::Font				mFont;
		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;

		std::size_t				mStatisticsNumFrames;
		bool					mIsMovingUp;
		bool					mIsMovingDown;
		bool					mIsMovingRight;
		bool					mIsMovingLeft;

		ResourceHolder<sf::Texture, Textures::ID> textures;

		sf::Sprite				airplane;
		sf::Sprite				landscape;
		sf::Texture             mBackgroundTexture;
		sf::Texture             mAirplaneTexture;

#pragma region step 1
		sf::Sprite				mSprite;
		sf::Shader				mShader;
		sf::Texture				mTexture;
public:
	const float winW = 200;
	const float winH = 200;
#pragma endregion
};

