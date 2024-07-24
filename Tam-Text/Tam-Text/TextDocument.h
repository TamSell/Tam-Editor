#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <vector>

#include <string>

class TextDocument
{

public:

	bool init(std::string fileName);

	
	sf::String getLine(int lineNumber);
	int getLineCount() const;


private:
	bool initLineBuffer();
	sf::String buffer;
	int length;
	std::vector<int> lineBuffer;
	sf::String convertUtf32Sf(const std::string& inString);
};

