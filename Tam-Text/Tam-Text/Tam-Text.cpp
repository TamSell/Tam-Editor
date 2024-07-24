#include <SFML/Graphics.hpp>
#include "TextDocument.h"
#include "TextView.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(450, 720), "Tam-Text");
	sf::Color defaultBackgroundColor = sf::Color::Blue;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(defaultBackgroundColor);

		window.display();

	}



}