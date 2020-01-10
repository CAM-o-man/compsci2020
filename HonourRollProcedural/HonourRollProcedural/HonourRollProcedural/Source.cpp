#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "GetData.h"
#include <map>
#include <algorithm>
/*
 * Author: Connor McDermid
 * Lab: Honour Roll Procedural
 * Extra: Maps
 * Known Bugs: None
 * Requirements: Write a program which will tell a student whether he/she is eligible for the honor roll.  Students are eligible if
they have at least a 90 average, are taking 5 or more courses, and have had no discipline infractions. Student can
take a maximum of 8 courses per semester.
Have your program get input from the student, including the student&#39;s full name, list of courses, and grades.
Please limit course name to 20 characters. Grades are always given as integers and the average must properly
rounded to the nearest integer value. Randomly assign whether they have a discipline issue. Print an appropriate
message if the user enters invalid data and ask that they re-enter the data.  Print out all information for the user
once they have completed entering their name, classes, and grades. Don’t forget to tell them their disciplinary
status and average.
*/
using namespace std;
typedef string str;
typedef unsigned int uint;

void usrClasses(map<str, int>& classes) {
	//get name and grade from user
	str name;
	int grade;
	bool isValid = false;
	cout << "Please input a name for the class: " << endl;
	toolong:
	getline(cin, name);
	if (name.length() > 20) {
		cout << "Name is too long. Please keep it under 20 characters." << endl;
		goto toolong;
	}
	do {
		cout << "Please input your grade for " << name << endl;
	} while (!(isValid = getValidInt(grade)));
	classes[name] = grade;
}

bool passer(map<str, int>& classes, bool infracs) {
	if (infracs) {
		return false;
	}
	
	if (classes.size() >= 5 && classes.size() <= 8) {
		int gradesum = 0;
		for (pair<str, int> i : classes) {
			gradesum += i.second;
		}
		if (gradesum / classes.size() < 90) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int main() {
	map<str, int> studclasses;
	bool infracs;
	string name;
	//get name
	cout << "Please input your name:" << endl;
	getline(cin, name);
	//now get their classes
	uint classnum;
	class_input:
	cout << "Please input the number of classes you're taking: " << endl;
	cin >> classnum;
	if (cin.fail()) {
		cin.clear(); cin.ignore(INT_MAX, '\n');
		cout << "That's not valid." << endl;
		goto class_input;
	}
	if (classnum > 8) {
		cout << "You can't take more than 8 classes. Lowering number to maximum." << endl;
		classnum = 8;
	}
	cin.ignore();
	for (uint i = 0; i < classnum; i++) {
		usrClasses(studclasses);
	}
	infracs = true ? rand() % 2 == 0 : false; //randomly assigned disciplinary infractions
	if (passer(studclasses, infracs)) {
		cout << "Congrats! Welcome to the Honour Roll." << endl;
		int sum;
		for_each(studclasses.begin(), studclasses.end(), [&](pair<str, int> x) {
			sum += x.second;
		});
		cout << "Average: " << sum / studclasses.size() << endl;
		cout << "Disciplinary Infractions: " << (infracs ? "true" : "false") << endl;
	}
	else {
		cout << "Unfortunately, you did not make the honour roll." << endl;
		int sum;
		for_each(studclasses.begin(), studclasses.end(), [&](pair<str, int> x) {
			sum += x.second;
			});
		cout << "Average: " << sum / studclasses.size() << endl;
		cout << "Disciplinary Infractions: " << (infracs ? "true" : "false") << endl;
	}
	return 0;
}