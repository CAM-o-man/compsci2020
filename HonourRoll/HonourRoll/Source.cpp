#include "Class.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

typedef unsigned int uint;

using namespace std;

/*
Author: Connor McDermid
Lab: Honour Roll
Date: 2019.10.23
Extras: Vectors, References, Operator Overloading, Friend Methods
Known Bugs: None
Requirements: Write a program which will tell a student whether he/she is eligible for the honor roll.  Students are eligible if
they have at least a 90 average, are taking 5 or more courses, and have had no discipline infractions. Student can
take a maximum of 8 courses per semester.
Have your program get input from the student, including the student&#39;s full name, list of courses, and grades.
Please limit course name to 20 characters. Grades are always given as integers and the average must properly
rounded to the nearest integer value. Randomly assign whether they have a discipline issue. Print an appropriate
message if the user enters invalid data and ask that they re-enter the data.  Print out all information for the user
once they have completed entering their name, classes, and grades. Don’t forget to tell them their disciplinary
status and average.
*/
uint findAvg(Student& s) {
	vector<Class> classes = s.getClasses();
	uint sum = 0;

	for (uint i = 0; i < classes.size(); i++) {
		sum += classes[i].getGrade();
	}

	uint avg = sum / classes.size();

	return avg;
}

bool passer(Student& s) {
	if (s.hasInfractions()) {
		return false;
	}
	if (s.getClasses().size() >= 5 && s.getClasses().size() <= 8) {
		if (findAvg(s)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	cout << "Welcome to the Honour Roll Acceptance Test." << endl;
	cout << "Due to technical constraints, at this time admission relies on the honour system." << endl;
	cout << "If you're trying to join an honour society, you should be honourable." << endl;
	cout << "Keeping this in mind, please enter your name." << endl;
	string name;
	cin.ignore(); // clear trailing newlines and whitespace
	getline(cin, name);
	cout << "Now, please enter the number of classes you're taking." << endl;
	retry:
	uint classnum;
	cin >> classnum;
	if (cin.fail()) {
		cin.clear(); cin.ignore(INT_MAX, '\n'); //flush the entire buffer until EOF or newline, whichever comes first.
		cout << "That wasn't a natural number. Please try again." << endl;
		goto retry;
	}
	vector<Class> classes;
	string tmpname;
	uint tmpgrade;
	for (uint i = 0; i < classnum; i++) {
		cout << "Please enter the name of class number " << i + 1 << endl;
		cin.ignore();
		nametoolong:
		getline(cin, tmpname);
		if (tmpname.length() > 20) {
			cout << "Name too long. Please keep it under 20 characters." << endl;
			goto nametoolong;
		}
		cout << "Now please enter the grade you have in this class." << endl;
		cin >> tmpgrade;
		if (cin.fail()) {
			cin.clear(); cin.ignore();
			cout << "That's not a valid grade." << endl;
			i--;
			continue;
		}
		Class tmpclass(tmpgrade, tmpname);
		classes.push_back(tmpclass);//critical question here - tmpclass immediately goes out of scope and its memory will be deallocated. 
									//Does a vector store a copy of or a reference to tmpclass?
	}								//Answer - it does store a copy as opposed to a reference as far as I can tell. Otherwise, memory would leak and the program would break.
	Student stud(name, classes);
	srand((unsigned)time(0));
	stud.setInfractions(true
						? rand() % 2 == 0
						: false);
	if (passer(stud)) {
		cout << "You have passed, and are on the honour roll. Congratulations." << endl;
		cout << "Results:" << endl;
		for (uint i = 0; i < classes.size(); i++) {
			cout << classes[i].getName() << " " << classes[i].getGrade() << endl;
		}
		cout << "Disciplinary Infraction: " << stud.hasInfractions() << endl;

		return 0;
	}
	else {
		cout << "Unfortunately, you have not made the honour roll. Better luck next time!" << endl;
		cout << "Results:" << endl;
		for (uint i = 0; i < classes.size(); i++) {
			cout << classes[i].getName() << " " << classes[i].getGrade() << endl;
		}
		return 0;
	}
}