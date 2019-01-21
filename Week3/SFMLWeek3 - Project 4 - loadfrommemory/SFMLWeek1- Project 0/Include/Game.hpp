#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#pragma region step1
#include <SFML/Network.hpp>
#pragma endregion

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

	 sf::Texture dlpicture(std::string host, std::string uri);

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

		sf::Texture             eagleTexture;


		
};

