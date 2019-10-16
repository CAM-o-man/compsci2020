#pragma once
#include "Class.h"
#include <string>

using namespace std;

class Student 
{
	private:
		unsigned int avg;
		Class classes[8];
		unsigned int classCount;
		string name;
	public:
		bool addClass(Class c);

		unsigned int getClassCount();

		Class* getClasses();

		void setAvg(unsigned int average);

		unsigned int getAvg();

		string getName();

		void setName(string n);

		Student(); //default constructor

		Student(string name);

		~Student(); //destructor required because of owned pointers

};

