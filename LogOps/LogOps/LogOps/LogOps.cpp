// LogOps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Connor McDermid
//Lab: 3.1 Logical Operators
//Extra: substrings
//Known Bugs: N/A

#include "pch.h"
#include <iostream>
using namespace std;

int malware() {
	cout << "This program may reformat your hard drive. Do you wish to continue? [Y|N]" << endl;
	string usr;
	cin >> usr;
	char answer = usr[0];
	if (answer == 'y' || answer == 'Y') {
		cout << "Adios data!" << endl;
	} else if (answer == 'n' || answer == 'N') {
		cout << "Wise choice." << endl;
	} else {
		cout << "That answer was unclear. Guess I have free reign to trash your filesystem!" << endl;
	}
	return 0;
}

int lottery() {
	redo:
	cout << "Please enter a number between 50 and 100." << endl;
	int usr;
	cin >> usr;
	if (cin.fail()) {
		cin.clear();
		cout << "That's not even an integer." << endl;
		goto redo;
	}
	if (usr > 50 && usr < 100) {
		cout << "You've won $" << usr << "!" << endl;
	} else {
		cout << "Since you couldn't be bothered to follow directions, I suppose I shouldn't be bothered to give you money." << endl;
	}
	return 0;
}

int main() {
	malware();
	lottery();
	return 0;
}