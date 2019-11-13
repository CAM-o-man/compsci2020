#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "GetData.h"
#include <map>
/*
 * Author: Connor McDermid
 * Lab: Honour Roll Procedural
 * Extra: Maps
 * Known Bugs: None
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
	cin.ignore();
	for (uint i = 0; i < classnum; i++) {
		usrClasses(studclasses);
	}
	infracs = true ? rand() % 2 == 0 : false; //randomly assigned disciplinary infractions
	if (passer(studclasses, infracs)) {
		cout << "Congrats! Welcome to the Honour Roll." << endl;
	}
	else {
		cout << "Unfortunately, you did not make the honour roll." << endl;
	}
	return 0;
}