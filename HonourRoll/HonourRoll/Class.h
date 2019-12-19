#pragma once
#include <string>
class Class {
private:
	unsigned int grade;
	std::string name;

public:
	Class(); //default constructor
	Class(unsigned int g, std::string n); //Constructs a Class with all required attributes.

	void setGrade(unsigned int g);
	unsigned int getGrade();

	std::string getName();

	friend bool operator==(Class& lhs, Class& rhs); // added as friend so that it's included with Class.h in all files it's needed, and I don't have to rewrite it.
};