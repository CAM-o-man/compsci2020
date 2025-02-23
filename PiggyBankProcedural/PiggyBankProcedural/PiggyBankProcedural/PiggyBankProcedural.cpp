// PiggyBankProcedural.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Connor McDermid
//Date: 2019.10.04
//Lab: Piggy Bank Procedural
//Extra: Enums
//KNOWN BUGS: When entering coins (add -c), the console always interprets the final input (the amount of said coins) properly, however informs the user (falsely) that their command is invalid.

#include "pch.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

unsigned int pennies;
unsigned int nickels;
unsigned int dimes;
unsigned int quarters;
string name;
double balance;

void title() { //Prints bootanimation
	cout << "-----------------------------------------" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //sleeps thread for 1000 milliseconds
	cout << "|         hackSugar Piggy Bank          |" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	cout << "|               v3.01                   |" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	cout << "|              booting...               |" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	cout << "-----------------------------------------" << endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	system("cls");
}

string getName() {
	cout << "Hello! What's your name?" << endl;
	string name;
	getline(cin, name); //shouldn't need typechecking; everything can be interpreted as a string
	return name;
}

unsigned int getPennies() {
	return pennies;
}

unsigned int getNickels() {
	return nickels;
}

unsigned int getDimes() {
	return dimes;
}

unsigned int getQuarters() {
	return quarters;
}

void addPenny() {
	pennies++;
}

void addNickel() {
	nickels++;
}

void addDime() {
	dimes++;
}

void addQuarter() {
	quarters++;
}

void compound() {
	double money = 0;
	money += (pennies * 0.01);
}

double getTotalMoney() {
	return balance;
}

void addfunc(double money) {
	balance += money;
}

void addcoin(char coin, unsigned int amount) {
	switch (coin) {
		case 'p':
			pennies += amount;
			balance += (amount * 0.01);
			break;
		case 'n':
			nickels += amount;
			balance += (amount * 0.05);
			break;
		case 'd':
			dimes += amount;
			balance += (amount * 0.1);
			break;
		case 'q':
			quarters += amount;
			balance += (amount * 0.25);
			break;
	}
}

enum command {
	cls,
	bal,
	chusr,
	add,
	ext,
	invalid,
	addc,
	help
};

command hashCommand(string cmd) {


	if (cmd.find("cls") != std::string::npos) {
		return cls;
	} else if (cmd.find("balance") != std::string::npos || cmd.find("bal") != std::string::npos) {
		return bal;
	} else if (cmd.find("chusr") != std::string::npos) {
		return chusr;
	} else if (cmd.find("add") != std::string::npos) {
		if (cmd.find("-c") != std::string::npos) {
			return addc;
		} else {
			return add;
		}
	} else if (cmd.find("exit") != std::string::npos) {
		return ext;
	} else if (cmd.find("help") != std::string::npos) {
		return help;
	} else {
		return invalid;
	}
}

int commandline() {
	string command;
	cout << name << "@piggy~$ ";
	getline(cin, command);
	switch (hashCommand(command)) {
		case cls:
			system("cls");
			break;
		case bal:
			cout << getTotalMoney() << endl;
			break;
		case chusr:
			cout << "Beginning change user process..." << endl;
			name = getName();
			break;
		case add: { //Braces required to avoid transfer of control past initialisation
			redo:
			cout << "How much would you like to add?" << endl;
			string mon;
			getline(cin, mon); //needs to be double, string is part of type checking
			const char* cstrmon = mon.c_str();
			size_t found;
			found = mon.find('.');
			if (found == string::npos) {
				cout << "Please enter a monetary amount." << endl;
				goto redo;
			}
			double money = stod(cstrmon);
			addfunc(money);
			break;
		}
		case ext:
			exit(0);
			break;
		case invalid:
			cout << "Invalid command" << endl;
			break;
		case help:
			cout << "bal: check balance\ncls: clear screen\nchusr: change user\nadd: add money.\n\t-c: add coins\nexit: exit" << endl;
			break;
		case addc: { //Using braces to scope block. Can't go jumping over nontrivial initialisations.
			retry:
				cout << "What type of coins are you adding? (p)ennies, (n)ickels, (d)imes, or (q)uarters?" << endl;
				char type;
				string temp;
				getline(cin, temp);
				type = temp[0]; //Takes first character from user input
				cout << "How many?" << endl;
				unsigned int amt;
				cin >> amt; //will only fetch an int, otherwise sets failbit
				if (cin.fail()) {
					cin.clear();
					cout << "Try again." << endl;
					goto retry;
				}
				if (type != 'p' && type != 'n' && type != 'd' && type != 'q') {
					cout << "Not a valid coin type." << endl;
					goto retry;
				}
				addcoin(type, amt);

				break;
			}
		default:
			cout << "Invalid command" << endl;
			break;
	}
}

int main() {
	name = getName();
	while (1) {
		commandline();
	}
}