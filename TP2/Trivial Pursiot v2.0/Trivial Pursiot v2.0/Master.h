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
	std::vector<std::string> questions;
	std::vector<std::string> answers;

public:

	
	Master(std::string);

	void readAll();

	std::vector<std::string> getAllData();

	std::string getQuestion(int);

	std::vector<std::string> getAnswers(int);

	char getCorrect(int);

	std::vector<char> getAllCorrect();


};

