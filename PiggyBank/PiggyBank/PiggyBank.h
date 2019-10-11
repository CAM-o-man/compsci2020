#pragma once
#include <string>
#include "pch.h"
using namespace std;
enum class command {
	ext,
	bal,
	namecom,
	chusr,
	addmon,
	invalid,
	addc,
	help,
	cls
};

class PiggyBank {
public:
	PiggyBank();
	~PiggyBank();
	PiggyBank(unsigned int pennies, unsigned int nickels, unsigned int dimes, unsigned int quarters);
	unsigned int getPennies();
	unsigned int getNickels();
	unsigned int getDimes();
	unsigned int getQuarters();
	void addPennies();
	void addNickels();
	void addDimes();
	void addQuarters();
	void setPennies(unsigned int pennies);
	void setNickels(unsigned int nickels);
	void setDimes(unsigned int dimes);
	void setQuarters(unsigned int quarters);
	double checkBalance();

	command hashCommand(string cmdstring);

	void add();

	void addc();

	int execCommand();

	void getName();
private:
	static unsigned int pennies;
	static unsigned int nickels;
	static unsigned int dimes;
	static unsigned int quarters;
	static double balance;
	
};

