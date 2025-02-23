// PiggyBank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Author: Connor McDermid
//Date: 2019.10.04
//Lab: Piggy Bank Object-oriented
//Extra: enums properly declared in a header file (PiggyBank.h, line 5)
//Extra: Nested ternaries (in PiggyBank.cpp, line 141)
//KNOWN BUGS: When adding couns (add -c), even though the proper amount of coins and their type is processed correctly, the program still informs the user that the command is invalid.

#include "pch.h"
#include <iostream>
#include <string>
#include <chrono> //for sleeping
#include <thread> //also for sleeping
#include "PiggyBank.h"

using namespace std;
void title() {
	cout << "-----------------------------------------" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //sleeps thread for 1000 milliseconds
	cout << "|         hackSugar Piggy Bank          |" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << "|               v3.01                   |" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << "|              booting...               |" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << "-----------------------------------------" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	system("cls");
}

string getName() {
	cout << "Hello! What's your name?" << endl;
	string name;
	getline(cin, name); //shouldn't need typechecking; everything can be interpreted as a string
	return name;
	
}

int main() {
	title();
	PiggyBank bank = PiggyBank();
	cout << "Copyright (c) PiggyBankCorporation 2019.\n" << endl;
	while (1) {
		if (!(bank.execCommand() == 0)) {
			continue; //really it doesn't matter. but I find it important for some reason to have this structure in place.
		}
	}
	return 0;
}


