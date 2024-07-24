#include "TextDocument.h"


bool TextDocument::init(std::string fileName)
{
	std::ifstream inputFile(fileName);
	

	//Error catch if file is incompatible or billions of other issues occur this will get it!
	// I hope
	if (!inputFile.is_open())
	{
		std::cerr << "Error " << fileName << " cannot be opened or does not exist." << std::endl;
		
		return false;
	}
		//Read from file to the stringstream
		std::stringstream inputStringStream;
		inputStringStream << inputFile.rdbuf();

		//Convert inputStringStream to unicode I think... I'll have to check later if this actually worked
		//Fills buffer with converted info and sets the length of buffer to be used later
		this->buffer = this->convertUtf32Sf(inputStringStream.str());
		this->length = this->buffer.getSize();

		inputFile.close();
		this->initLineBuffer();
}

sf::String TextDocument::getLine(int lineNumber)
{
	//Start with current line buffer and find its length by looking at next buffers start
	int currBufferStart = this->lineBuffer[lineNumber];
	int nextBufferStart = this->lineBuffer[lineNumber + 1];


	return this->buffer.substring(nextBufferStart - currBufferStart);
}

bool TextDocument::initLineBuffer()
{
	//Ensures lineBuffer is empty and that it is starting at top of line
	int lineStart = NULL;
	this->lineBuffer.clear();
	this->lineBuffer.push_back(lineStart);

	int bufferSize = this->buffer.getSize();


	//checks for carrige return and newline to make sure line buffer starts at correct bosition
	for (int i = 0; i < bufferSize; ++i)
	{
		if (this->buffer[i] == '\n' || this->buffer[i] == '\r')
		{
			lineStart = i + 1;
			this->lineBuffer.push_back(lineStart);
		}
	}

	//At this point a file should have been read so if this fails something is very wrong :(
	return true;
}

sf::String TextDocument::convertUtf32Sf(const std::string& inString)
{
	//seemed a simple enough way to convert on SFML website... idk if this will work for now
	//TODO: ensure conversion to unicode
	sf::String outString(inString);

	return outString.toUtf32();
}


