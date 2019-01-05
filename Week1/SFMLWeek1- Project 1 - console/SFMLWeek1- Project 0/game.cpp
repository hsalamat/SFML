#include <SFML/Graphics.hpp>
//step1
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//step2
			//if (event.type == sf::Event::Closed)
			//	window.close();

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
		window.draw(shape);
		window.display();
	}
	return 0;
}