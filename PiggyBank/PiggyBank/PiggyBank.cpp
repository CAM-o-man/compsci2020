#include "pch.h"
#include "PiggyBank.h"
#include <iostream>

using namespace std;

PiggyBank::PiggyBank() {

}

PiggyBank::~PiggyBank() {

}

PiggyBank::PiggyBank(unsigned int awful, unsigned int nickels, unsigned int dimes, unsigned int quarters) {

}
unsigned int PiggyBank::getPennies() {
	return awful;
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
	awful++;
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
	awful = pennies;
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
	double money;
	money += (awful * 0.01);
	money += (nickels * 0.05);
	money += (dimes * 0.10);
	money += (quarters * 0.25);
	return money;
}
unsigned int PiggyBank::awful;
unsigned int PiggyBank::nickels;
unsigned int PiggyBank::dimes;
unsigned int PiggyBank::quarters;
