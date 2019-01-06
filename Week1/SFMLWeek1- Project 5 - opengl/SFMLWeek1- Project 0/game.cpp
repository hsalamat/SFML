#include "Include/Game.hpp"


Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
	, mPlayer()
	, mPlayer2(sf::Vector2f(100.0f, 100.0f))
	, angle(0.0f)
	, rotate(true)

{

	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);

	mPlayer2.setPosition(200.f, 200.f);
	mPlayer2.setFillColor(sf::Color::Yellow);

	//prepare OpenGL surface for HSR

	glClearDepth(1.f);

	glClearColor(0.3f, 0.3f, 0.3f, 0.f);

	glEnable(GL_DEPTH_TEST);

	glDepthMask(GL_TRUE);



	//// Setup a perspective projection & Camera position

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();


	gluPerspective(90.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar

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

		// Escape key : exit

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))

			mWindow.close();



		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A)) {

			rotate = !rotate;
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	//mWindow.clear();
	//mWindow.draw(mPlayer);
	//mWindow.draw(mPlayer2);

	//Prepare for drawing

		// Clear color and depth buffer

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	// Apply some transformations for the cube

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glTranslatef(0.f, 0.f, -200.f);



	if (rotate) {

		angle = Clock.getElapsedTime().asSeconds();

	}

	glRotatef(angle * 50, 1.f, 0.f, 0.f);

	glRotatef(angle * 30, 0.f, 1.f, 0.f);

	glRotatef(angle * 90, 0.f, 0.f, 1.f);







	//Draw a cube

	glBegin(GL_QUADS);//draw some squares

	glColor3i(0, 1, 1);

	glVertex3f(-50.f, -50.f, -50.f);

	glVertex3f(-50.f, 50.f, -50.f);

	glVertex3f(50.f, 50.f, -50.f);

	glVertex3f(50.f, -50.f, -50.f);



	glColor3f(0, 0, 1);

	glVertex3f(-50.f, -50.f, 50.f);

	glVertex3f(-50.f, 50.f, 50.f);

	glVertex3f(50.f, 50.f, 50.f);

	glVertex3f(50.f, -50.f, 50.f);



	glColor3f(1, 0, 1);

	glVertex3f(-50.f, -50.f, -50.f);

	glVertex3f(-50.f, 50.f, -50.f);

	glVertex3f(-50.f, 50.f, 50.f);

	glVertex3f(-50.f, -50.f, 50.f);



	glColor3f(0, 1, 0);

	glVertex3f(50.f, -50.f, -50.f);

	glVertex3f(50.f, 50.f, -50.f);

	glVertex3f(50.f, 50.f, 50.f);

	glVertex3f(50.f, -50.f, 50.f);



	glColor3f(1, 1, 0);

	glVertex3f(-50.f, -50.f, 50.f);

	glVertex3f(-50.f, -50.f, -50.f);

	glVertex3f(50.f, -50.f, -50.f);

	glVertex3f(50.f, -50.f, 50.f);



	glColor3f(1, 0, 0);

	glVertex3f(-50.f, 50.f, 50.f);

	glVertex3f(-50.f, 50.f, -50.f);

	glVertex3f(50.f, 50.f, -50.f);

	glVertex3f(50.f, 50.f, 50.f);



	glEnd();



	// Finally, display rendered frame on screen

	//You can have either your openGL or the following SFML window to be active
	//mWindow.draw(shape);

	mWindow.display();
}



