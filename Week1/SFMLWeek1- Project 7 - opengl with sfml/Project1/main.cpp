////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
//You need to add opengl32.lib to your linker input additional dependencies.
#include <SFML/OpenGL.hpp>

#ifndef GL_SRGB8_ALPHA8
#define GL_SRGB8_ALPHA8 0x8C43
#endif


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
	bool exit = false;
	bool sRgb = false;

	while (!exit)
	{
		// Request a 24-bits depth buffer when creating the window
		sf::ContextSettings contextSettings;
		contextSettings.depthBits = 24;
		contextSettings.sRgbCapable = sRgb;

		// Create the main window
		sf::RenderWindow window(sf::VideoMode(800, 600), "SFML graphics with OpenGL", sf::Style::Default, contextSettings);
		window.setVerticalSyncEnabled(true);

		// Create a sprite for the background
		sf::Texture backgroundTexture;
		//backgroundTexture.setSrgb(sRgb);
		//if (!backgroundTexture.loadFromFile("resources/background.jpg"))
		if (!backgroundTexture.loadFromFile("Media/Textures/eagle.png"))
			return EXIT_FAILURE;
		sf::Sprite background(backgroundTexture);

		// Create some text to draw on top of our OpenGL object
		sf::Font font;
		if (!font.loadFromFile("Media/sansation.ttf"))
			return EXIT_FAILURE;
		sf::Text text("SFML / OpenGL demo", font);


		// Load a texture to apply to our 3D cube
		//sf::Texture texture;
		//if (!texture.loadFromFile("resources/texture.jpg"))
		//      return EXIT_FAILURE;

		// Attempt to generate a mipmap for our cube texture
		// We don't check the return value here since
		// mipmapping is purely optional in this example
		//texture.generateMipmap();

		// Make the window the active window for OpenGL calls
		window.setActive(true);

		// Enable Z-buffer read and write
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_TRUE);
		glClearDepth(1.f);

		// Disable lighting
		glDisable(GL_LIGHTING);

		// Configure the viewport (the same size as the window)
		glViewport(0, 0, window.getSize().x, window.getSize().y);

		// Setup a perspective projection
		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();
		//GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
		//glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

		// Bind the texture
		//glEnable(GL_TEXTURE_2D);
		//sf::Texture::bind(&texture);

		// Define a 3D cube (6 faces made of 2 triangles composed by 3 vertices)
		static const GLfloat triangle[] =
		{
			// positions    // texture coordinates
			-0.5, -0.5, 0.0,
			0.5,  -0.5, 0.0,
			0.0, 0.5,  0.0,
		};

		static const GLfloat mVertexColours[] =
		{
			// color   
			1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,
		};

		// Enable position vertex components
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), triangle);

		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, mVertexColours);

		// Make the window no longer the active window for OpenGL calls
		window.setActive(false);


		// Start game loop
		while (window.isOpen())
		{
			// Process events
			sf::Event event;
			while (window.pollEvent(event))
			{
				// Close window: exit
				if (event.type == sf::Event::Closed)
				{
					exit = true;
					window.close();
				}

				// Escape key: exit
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
				{
					exit = true;
					window.close();
				}

			}

			// Make the window no longer the active window for OpenGL calls
			window.setActive(false);
			// Draw the background
			window.pushGLStates();
			window.draw(background);
			window.popGLStates();

			// Make the window the active window for OpenGL calls
			window.setActive(true);

			// Clear the depth buffer
			glClear(GL_DEPTH_BUFFER_BIT);
			glClear(GL_COLOR_BUFFER_BIT);

			// We get the position of the mouse cursor, so that we can move the box accordingly
			float x = sf::Mouse::getPosition(window).x * 200.f / window.getSize().x - 100.f;
			float y = -sf::Mouse::getPosition(window).y * 200.f / window.getSize().y + 100.f;

			// Apply some transformations
			//glMatrixMode(GL_MODELVIEW);
			//glLoadIdentity();
			//glTranslatef(x, y, -100.f);
			//glRotatef(clock.getElapsedTime().asSeconds() * 50.f, 1.f, 0.f, 0.f);
			//glRotatef(clock.getElapsedTime().asSeconds() * 30.f, 0.f, 1.f, 0.f);
			//glRotatef(clock.getElapsedTime().asSeconds() * 90.f, 0.f, 0.f, 1.f);

			// Draw the cube
			glDrawArrays(GL_TRIANGLES, 0, 3);

			// Make the window no longer the active window for OpenGL calls
			window.setActive(false);

			// Draw some text on top of our OpenGL object
			window.pushGLStates();
			window.draw(background);
			window.draw(text);
			//window.draw(sRgbInstructions);
			//window.draw(mipmapInstructions);
			window.popGLStates();

			// Finally, display the rendered frame on screen
			window.display();
			window.setActive(true);
		}
	}

	return EXIT_SUCCESS;
}
