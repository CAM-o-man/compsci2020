#pragma once
#include <string>
#include <vector>
class Save
{
private:
	std::string filename;
	std::vector<char> answers;

public:
	
	Save(std::string);

	void bufferAnswer(char);

	std::vector<char> getBuf();

	void writeBuf();

	char getSpecific(int);
};

