// cppifs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Connor McDermid
//Lab: Working with IFs
//Extra: input validation with cin's goodbit and failbit
//Known bugs: none

#include <iostream>
using namespace std;

void heinz() {
	redo:
	cout << "Please enter a number." << endl;
	int num;
	cin >> num;
	if (cin.fail()) {
		cin.clear();
		cout << "That's not a number." << endl;
		goto redo;
	}
	if (num == 57) {
		cout << "Hey, it's a Heinz number!" << endl;
	} else {
		cout << "Cool number. Bit boring, though." << endl;
	}
}

void range() {
	retry:
	cout << "Please enter a number between 5 and 10 inclusive." << endl;
	int num;
	cin >> num;
	if (cin.fail()) {
		cin.clear();
		cout << "That's not even a number." << endl;
		goto retry;
	}
	if (num > 10) {
		cout << "Too big!" << endl;
	}
	else if (num < 5) {
		cout << "Too small!" << endl;
	}
	else if (num == 7) {
		cout << "Lucky number!" << endl;
	}
	else {
		cout << "Well, you did what I asked. I can't fault you for that, I suppose." << endl;
	}
}

int main() {
	heinz();
	range();
	return 0;
}