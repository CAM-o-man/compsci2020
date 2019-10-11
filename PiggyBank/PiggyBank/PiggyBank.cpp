#include "pch.h"
#include "PiggyBank.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;


unsigned int PiggyBank::pennies;
unsigned int PiggyBank::nickels;
unsigned int PiggyBank::dimes;
unsigned int PiggyBank::quarters;
double PiggyBank::balance;
string name;

PiggyBank::PiggyBank() {
	getName();
}

void PiggyBank::getName() {
	cout << "Enter your name." << endl;
	string nm;
	getline(cin, nm);
	name = nm;
}

PiggyBank::~PiggyBank() {

}

PiggyBank::PiggyBank(unsigned int pennies, unsigned int nickels, unsigned int dimes, unsigned int quarters) {

}
unsigned int PiggyBank::getPennies() {
	return pennies;
}

unsigned int PiggyBank::getNickels() {
	return nickels;
}

unsigned int PiggyBank::getDimes() {
	return dimes;
}

unsigned int PiggyBank::getQuarters() {
	return quarters;
}

void PiggyBank::addPennies() {
	PiggyBank::pennies++;
}

void PiggyBank::addNickels() {
	PiggyBank::nickels++;
}

void PiggyBank::addDimes() {
	PiggyBank::dimes++;
}

void PiggyBank::addQuarters() {
	PiggyBank::quarters++;
}

void PiggyBank::setPennies(unsigned int pennies) {
	PiggyBank::pennies = pennies;
}

void PiggyBank::setNickels(unsigned int nick) {
	PiggyBank::nickels = nick;
}

void PiggyBank::setDimes(unsigned int dim) {
	PiggyBank::dimes = dim;
}

void PiggyBank::setQuarters(unsigned int quar) {
	PiggyBank::quarters = quar;
}

double PiggyBank::checkBalance() {
	return PiggyBank::balance;
}


command PiggyBank::hashCommand(string cmdstring) {
	if (cmdstring.find("exit") != (std::string::npos)) {
		return command::ext;
	} else if (cmdstring.find("bal") != (std::string::npos)) {
		return command::bal;
	} else if (cmdstring.find("name") != (std::string::npos)) {
		return command::namecom;
	} else if (cmdstring.find("chusr") != (std::string::npos)) {
		return command::chusr;
	} else if (cmdstring.find("add") != (std::string::npos)) {
		if (cmdstring.find("-c") != (std::string::npos)) {
			return command::addc;
		} else {
			return command::addmon;
		}
	} else if (cmdstring.find("help") != (std::string::npos)) {
		return command::help;
	}
	else if (cmdstring.find("cls") != (std::string::npos)) {
		return command::cls;
	} else {
		return command::invalid;
	}
}

void PiggyBank::add() {
	retry:
	cout << "How much would you like to add?" << endl;
	string mon;
	getline(cin, mon);
	if (mon.find(".") == std::string::npos) {
		cout << "Please enter a valid monetary amount.";
		goto retry;
	}
	double money = stod(mon);
	PiggyBank::balance += money;
}

void PiggyBank::addc() {
	retry: //apparently labels are in fact scope-dependent. Learn something new every day.
	cout << "Would you like to add (p)ennies, (n)ickels, (d)imes, or (q)uarters?" << endl;
	char type;
	string tmp;
	getline(cin, tmp);
	type = tmp[0];
	if (type != 'p' && type != 'n' && type != 'd' && type != 'q') {
		cout << "Invalid coin type." << endl;
		goto retry;
	}
	cout << "How many?" << endl;
	int amt;
	cin >> amt;
	PiggyBank::balance += (amt * type == 'p' //extra here, nested ternaries
							? 0.01
							: type == 'n'
								? 0.05
								: type == 'd'
									? 0.1
									: 0.25);
	if (type == 'p') {
		PiggyBank::pennies += amt;
	} else if (type == 'n') {
		PiggyBank::nickels += amt;
	} else if (type == 'd') {
		PiggyBank::dimes += amt;
	} else {
		PiggyBank::quarters += amt;
	}
}

int PiggyBank::execCommand() {
	cout << name << "@piggy~$ ";
	string com;
	getline(cin, com);
	command cmd = hashCommand(com);

	switch (cmd) {
		case command::ext:
			exit(0);
			break;
		case command::bal:
			cout << checkBalance() << endl;
			break;
		case command::namecom:
			cout << name << endl;
			break;
		case command::chusr: { //braces to properly scope variable declaration
			cout << "What is your name?" << endl;
			string nm;
			getline(cin, nm);
			name = nm;
			break;
		}
		case command::addmon:
			add();
			break;
		case command::help:
			cout << "bal: check balance\ncls: clear screen\nchusr: change user\nadd: add money \n\t-c: add coins\nhelp: show this menu\nexit: exit the program" << endl;
			break;
		case command::addc:
			addc();
			break;
		case command::cls:
			system("cls");
			break;
		default:
			cout << "That is not a recognised command." << endl;
			return 1;
	};


	return 0;

}