#pragma once
#include <string>
class Class { //Simple data structure
	private:
		unsigned int grade; //grade in class
		std::string name; //Name of class
	public:
		Class(unsigned int g, std::string n); //Constructor only needed (maybe) for use with `new` - if unneeded, remove.

		Class(); //default constructor

		const unsigned int getGrade();

		const std::string getName();

		void setGrade(unsigned int g);
};
