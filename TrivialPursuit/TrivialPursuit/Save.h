#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
class Save
{
private:

	bool align();

	inline void checkAlign();
	
public:

	std::fstream& playersave;

	std::vector<char> getAnswers();

	std::string getName();

	void writeAns(char);

	void writeName(std::string);

	Save(std::fstream&);
};

