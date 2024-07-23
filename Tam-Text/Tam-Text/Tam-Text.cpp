#include "TextDocument.h"
#include <SFML/Graphics.hpp>

int main()
{
	TextDocument myTextDoc;
	std::string fileName;
	sf::RenderWindow window;

	std::cout << "Enter File Name: " << "\n";

	std::cin >> fileName;

	if (myTextDoc.init(fileName) == true)
	{
		std::cout << "Success";
		window.create(sf::VideoMode(400, 800), "Tam-Text");
	}
	else
	{
		std::cout << "Failure";
	}


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

	}



}