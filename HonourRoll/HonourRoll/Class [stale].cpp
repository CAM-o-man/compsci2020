#include "Class.h"
#include <string>
#include <iostream>

Class::Class(unsigned int g, std::string n) {
	this->grade = g;
	this->name = n;
}

Class::Class() {
	//default constructor
	this->grade = 0;
	this->name = "";
}

void Class::setGrade(unsigned int g) {
	this->grade = g;
}

const unsigned int Class::getGrade() {
	return this->grade;
}

const std::string Class::getName() {
	try {
		return this->name; //FIXME: Exception thrown: Access violation reading location 0xE45F62F2
	}
	catch (std::bad_alloc & ba) {
		std::cerr << "At Class::getName(), on return this->name; line 26, Class.cpp, a std::bad_alloc exception was thrown.\n";
	}
}