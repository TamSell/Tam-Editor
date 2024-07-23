#include "TextDocument.h"


bool::TextDocument::init(std::string& fileName)
{

	bool outCheck = true;
	myFile.open(fileName);

	if (!myFile.is_open())
	{
		outCheck = false;
	}
	myFile << "Test Test";
	myFile.close();

	return outCheck;
}