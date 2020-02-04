#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <istream>
#include <ostream>



class Master
{
private:
	std::string file;
	std::vector<std::string> data;

public:

	
	Master(std::string);

	void readAll();

	void write();

	std::vector<std::string> getAllData();

	std::string getQuestion(int);

	std::string getAnswers(int);

	char getCorrect(int);

	std::vector<char> getAllCorrect();


};

