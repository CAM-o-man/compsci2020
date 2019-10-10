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
	pennies++;
}

void PiggyBank::addNickels() {
	nickels++;
}

void PiggyBank::addDimes() {
	dimes++;
}

void PiggyBank::addQuarters() {
	quarters++;
}

void PiggyBank::setPennies(unsigned int pennies) {
	pennies = pennies;
}

void PiggyBank::setNickels(unsigned int nick) {
	nickels = nick;
}

void PiggyBank::setDimes(unsigned int dim) {
	dimes = dim;
}

void PiggyBank::setQuarters(unsigned int quar) {
	quarters = quar;
}

double PiggyBank::checkBalance() {
	double money = 0.00;
	money += (pennies * 0.01);
	money += (nickels * 0.05);
	money += (dimes * 0.10);
	money += (quarters * 0.25);
	return money;
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
		return command::addmon;
	} else {
		return command::invalid;
	}
}

void PiggyBank::add() {
	retry:
	cout << "How much would you like to add?" << endl;
	string mon;
	getline(cin, mon);
	char* moncstring = (char*)mon.c_str();
	const char* monconstc = mon.c_str();
	if (!strtok(moncstring, ".")) {
		cout << "That is not a valid amount of money." << endl;
		goto retry;
	}

	double money = strtod(monconstc, '\0'); //requires a null terminator apparently

	balance += money;
}

int PiggyBank::execCommand() {
	cout << "Copyright (c) PiggyBankCorporation 2019.\n" << endl;
	cout << name << "@piggy~$";
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
		case command::chusr:
		{
			cout << "What is your name?" << endl;
			string nm;
			getline(cin, nm);
			name = nm;
			break;
		}
		case command::addmon:
			add();
			break;
		default:
			cout << "That is not a recognised command." << endl;
			return 1;
	};


	return 0;

}