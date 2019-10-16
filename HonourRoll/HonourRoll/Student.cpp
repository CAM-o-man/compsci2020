#include "Student.h"
#include "Class.h"
#include <iostream>
using namespace std;


/*
This adds a function to the `==` operator to allow it to compare my Class structure.
*/
bool operator==(const Class& lhs, const Class& rhs) {
	return (lhs.name == rhs.name && lhs.grade == rhs.grade);
}

bool Student::addClass(Class c) {
	Class defaultclass = {
		0,
		""
	};
	for (int i = 0; i < 8; i++) {
		if (*(this->classes + i) == defaultclass) {
			*(this->classes + i) = c;
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
}

unsigned int Student::getClassCount() {
	Class defaultclass = {
		0,
		""
	};
	for (int i = 0; i < 8; i++) {
		if (*(this->classes + i) == defaultclass) {
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
		sum += (this->classes + i)->grade;
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
		*(this->classes) = *(new Class(0, ""));
	}
}

Student::~Student() {
	delete this->classes;
}
