#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	sf::Texture texture;
	if (!texture.loadFromFile("Media/Textures/Desert.png")) return -1;
	texture.setRepeated(true);
	sf::Sprite background;
	background.setTexture(texture);
	background.setTextureRect(sf::IntRect(0, 0, 800, 600));

	shape.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				cout << "Window Size Width: " << event.size.width << " Window Size Height: " << event.size.height << endl;
				break;
			case sf::Event::TextEntered:
				//How to get user's input
				if (event.text.unicode < 128) {
					printf("%c", event.text.unicode);
				}
			}
		}

		window.clear();
		window.draw(background);
		window.draw(shape);
		window.display();
	}
	return 0;
}