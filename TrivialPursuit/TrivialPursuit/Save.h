#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
class Save
{
private:
	std::fstream playersave;

	bool align();

	inline void checkAlign();
	
public:
	std::vector<char> getAnswers();

	std::string getName();

	void writeAns(char);

	Save(std::string);
};

