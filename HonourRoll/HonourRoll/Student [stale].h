#pragma once
#include "Class.h"
#include <string>

using namespace std;

class Student 
{
	private:
		unsigned int avg;//average grade
		Class* classes = new Class();
		unsigned int classCount; //number of classes (unnecessary but convenient)
		string name; //Name of student
	public:
		bool addClass(Class c); //Adds a class to *classes

		unsigned int getClassCount(); //returns the number of classes

		Class* getClasses(); //returns this->classes*

		void setAvg(unsigned int average); //Sets the average

		unsigned int getAvg(); //returns the average

		string getName(); //returns the student's name

		void setName(string n); //sets the student's name

		Student(); //default constructor

		Student(string name); //Constructor to initialise with student name

		~Student(); //destructor required because of owned pointers (*classes)

};

