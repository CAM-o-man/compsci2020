#include "Class.h"
#include <string>

Class::Class() {
	//default constructor
	this->grade = 0;
	this->name = "";
}

Class::Class(unsigned int g, std::string n) {
	this->setGrade(g);
	this->name = n;
}

void Class::setGrade(unsigned int g) {
	this->grade = g;
}

unsigned int Class::getGrade() {
	return this->grade;
}

std::string Class::getName() {
	return this->name;
}

bool operator==(Class& lhs, Class& rhs) { // Only compares names. This is intentional.
	if (lhs.getName() == rhs.getName()) {
		return true;
	}
	else {
		return false;
	}
}