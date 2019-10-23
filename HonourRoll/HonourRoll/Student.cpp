#include "Student.h"
#include "Class.h"
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string Student::getName() {
	return this->name;
}

void Student::setName(string n) {
	this->name = n;
}

vector<Class> Student::getClasses() {
	return this->classes;
}

void Student::addClass(Class c) { //Is never called at present, but could be useful for later if we ever use this lab again.
	this->classes.push_back(c);
}

unsigned int Student::numberOfClasses() {
	return this->classes.size();
}

bool Student::hasInfractions() {
	return this->infractions;
}

void Student::setInfractions(bool i) {
	this->infractions = i;
}

void Student::removeClass(Class c) {
	for (unsigned int i = 0; i < this->numberOfClasses(); i++) {
		this->classes.erase(remove_if(this->classes.begin(), this->classes.end(), [&c](Class& cls) {return cls == c; }), this->classes.end()); //erase-remove idiom
	}
}

Student::Student(string n, vector <Class> cv) {
	this->setName(n);
	for (unsigned int i = 0; i < cv.size(); i++) {
		this->addClass(cv[i]);
	}
}