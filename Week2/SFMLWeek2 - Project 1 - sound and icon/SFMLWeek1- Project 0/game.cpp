#include "Include/Game.hpp"


Game::Game()
#pragma region Step2
	: mWindow(sf::VideoMode(800, 600), "SFML Application", sf::Style::Close)
	, mTexture()
	, mBackground()
	, mPlayer()
	, mMusic()
	, mFont()
	, mIcon()
	,mImage()
	,mImage2()
#pragma endregion

{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);

#pragma region step3


	mIcon.loadFromFile("Media/Textures/icon.png");
	mWindow.setIcon(mIcon.getSize().x, mIcon.getSize().y, mIcon.getPixelsPtr());

	//create my own image - a 100x100 image filled with yellow color
	mImage.create(100, 100, sf::Color::Yellow);

	// Make the top-left pixel transparent
	sf::Color color = mImage.getPixel(0, 0);
	color.a = 0;
	color.r = 0;
	mImage.setPixel(0, 0, color);

	mImage2.loadFromFile("Media/Textures/Mushroom.png");
	// Copy image2 on image1 at position (50, 50)
	mImage.copy(mImage2, 50, 50);



	// Save the image to a file
	if (!mImage.saveToFile("Media/Textures/result.png"))
		cout << "Cannot save my image to Textures folder " << endl;


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

	//mText.setRotation(45);

	
	mMusic.openFromFile("Media/Textures/nice_music.ogg");
	//mMusic.openFromFile("Media/Textures/Tchaikovsky_Nocturne__orch.mp3");  //does not play MP3 - license
	//Play the music
	mMusic.play();
	mMusic.setLoop(true);

#pragma endregion

}

void Game::run()
{

	while (mWindow.isOpen())
	{
		processEvents();
		update();
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
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	mWindow.clear();

#pragma region Step4

	mWindow.draw(mBackground);
	//Draw the string
	mWindow.draw(mText);
#pragma endregion

	//Update the window
	mWindow.display();
}



