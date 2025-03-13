#include "FileUtils.h"
#include <fstream>


void writeUserInputToFile(const std::string &path)
{
	// BEGIN: 1a
	std::filesystem::path fileName{path};
	std::ofstream outputStream{fileName};
	bool exitWordNotSaid = true;
	std:: string newWord;
	while (exitWordNotSaid)
	{
		std::cout << "Write new word or write 'quit' to stop" << endl;
		std::cin >> newWord;
		if (newWord == "quit")
		{
			exitWordNotSaid = false;
		}
		else 
		{
			outputStream << newWord << std::endl;
		}
	}
	// END: 1a
}


void addLineNumbers(const std::string &filename)
{
	// BEGIN: 1b
	std::ifstream inputStream{filename};
	std::string newFileName = filename + ".linum";
	std::ofstream outputStream{newFileName};

	if (!inputStream) 
	{ // Sjekker om strømmen ble åpnet
		std::cout << "Could not open file" << std::endl;
	}
	std:string nextWord;
	int lineNumber = 1;
	while (inputStream >> nextWord)
	{
		outputStream << lineNumber << " " << nextWord << std::endl;
		++lineNumber;
	}
	// END: 1b
}