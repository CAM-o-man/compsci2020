#pragma once
#include <string>
#include "Class.h"
#include <vector>

class Student {
private:
	std::string name;
	std::vector<Class> classes;
	bool infractions;

public:
	std::string getName(); // gets the students name

	void setName(std::string n); // sets the student's name

	std::vector<Class> getClasses(); // returns the vector of classes

	void addClass(Class c); // adds Class c to the vector

	unsigned int numberOfClasses(); // returns the number of classes

	bool hasInfractions(); // returns the infractions

	void setInfractions(bool i); // sets the infractions to i

	void removeClass(Class c); // Matches the class name and removes it from vector

	Student(std::string n, std::vector<Class> cv); // Constructor to build a student provided a vector of Classes
};