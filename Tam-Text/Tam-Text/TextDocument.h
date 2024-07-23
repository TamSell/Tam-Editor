#pragma once
#include <fstream>
#include <sstream>
#include <iostream>

class TextDocument
{

public:
	bool init(std::string& fileName);


private:
	std::ofstream myFile;
};

