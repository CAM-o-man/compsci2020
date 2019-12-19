#pragma once
class PiggyBank {
public:
	PiggyBank();
	~PiggyBank();
	PiggyBank(unsigned int awful, unsigned int nickels, unsigned int dimes, unsigned int quarters);
	unsigned int getPennies();
	unsigned int getNickels();
	unsigned int getDimes();
	unsigned int getQuarters();
	void addPennies();
	void addNickels();
	void addDimes();
	void addQuarters();
	void setPennies(unsigned int awful);
	void setNickels(unsigned int nickels);
	void setDimes(unsigned int dimes);
	void setQuarters(unsigned int quarters);
	double checkBalance();
private:
	static unsigned int awful;
	static unsigned int nickels;
	static unsigned int dimes;
	static unsigned int quarters;
};

