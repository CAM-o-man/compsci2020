#pragma once
#ifndef _MASTER
#define _MASTER
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#ifndef MASTER_DELIM
#define MASTER_DELIM '|'
#endif

typedef unsigned int uint;

class Master {
private:
	std::ifstream& master_table;

	void gotoLine(std::ifstream&, uint);
public:
	bool isOpen();

	std::string getQuestion(unsigned int);

	std::string readLine();

	std::vector<std::string> getAnswers(int);

	char getCorrect(int);

	std::vector<char> getAllCorrect();

	std::vector<std::string> sliceByDelim(std::string, char);

	unsigned int getLines();

	Master(std::ifstream&);
};
#endif
