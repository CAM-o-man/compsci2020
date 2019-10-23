#include "Student.h"
#include "Class.h"
#include <iostream>
using namespace std;


/*
This adds a function to the `==` operator to allow it to compare my Class structure.
Copied from: https://stackoverflow.com/a/5740343/7327253, check that for reference
*/
bool operator==(Class& lhs, Class& rhs) {
	return (lhs.getName() == rhs.getName() && lhs.getGrade() == rhs.getGrade());
}

bool Student::addClass(Class c) {
	Class defaultclass = {
		0,
		""
	};
	for (int i = 0; i < 8; i++) {
		if (*(this->getClasses() + i) == defaultclass) { //TODO: Maybe use Student::getClasses to avoid loads of recursive references?
			*(this->getClasses() + i) = c;
			return true;
		}
		else {
			if (i != 7) {
				continue;
			} else {
				return false;
			}
		}
	}
	return true;
}

unsigned int Student::getClassCount() {
	Class defaultclass = {
		0,
		""
	};
	for (int i = 0; i < 8; i++) {
		if (*(this->classes + i) == defaultclass) { //FIXME: Probable location of read access error.
			return i;
		}
		else {
			if (i != 7) {
				continue;
			}
			else {
				return 8;
			}
		}
	}
	return 0;
}

Class* Student::getClasses() {
	return this->classes;
}

void Student::setAvg(unsigned int average) {
	this->avg = average;
}

unsigned int Student::getAvg() {
	unsigned int count = this->getClassCount(); //FIXME: read access violation. **this** was 0x9AC9906C
	unsigned int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += ((*this).getClasses() + i)->getGrade(); //add each grade from each class to the sum
	}
	unsigned int avg = sum / count;
	return avg;
}

void Student::setName(std::string n) {
	this->name = n;
}

std::string Student::getName() {
	return this->name;
}

Student::Student() {
	//default constructor
}

Student::Student(string name) {
	this->name = name;
	for (int i = 0; i < 8; i++) {
		*(this->classes) = *(new Class(0, "")); //TODO: Work out how to make this work. Need to initialise each class in this->*classes as { 0, "" }.
	}
}

Student::~Student() {
	delete this->classes; //Must free the memory from *classes
}
