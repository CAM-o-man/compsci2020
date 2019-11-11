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
 * Known Bugs: Output not aesthetically pleasing, occasional errors with cin regarding trailing whitespace
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
	getline(cin, name);
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
		cout << "That's not valid." << endl;
		goto class_input;
	}
	cin.ignore();
	for (uint i = 0; i < classnum; i++) {
		usrClasses(studclasses);
	}
	cout << "Has Mr. Menadier scheduled a meeting with you?" << endl;
	str reply;
	cin.ignore(); // clear trailing whitespace
	getline(cin, reply);
	if (reply == "yes" || reply == "Yes" || reply == "YES") {
		infracs = true;
	}
	else {
		infracs = false;
	}
	if (passer(studclasses, infracs)) {
		cout << "Congrats! Welcome to the Honour Roll." << endl;
	}
	else {
		cout << "Unfortunately, you did not make the honour roll." << endl;
	}
	return 0;
}