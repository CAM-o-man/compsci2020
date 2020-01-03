#include "Food.h"
#include "Beverage.h"
#include "Candy.h"
#include "HotDog.h"
#include "Popcorn.h"
#include "Pizza.h"
#include <iostream>
#include <fstream>
#include <string>


/*
Name: Connor McDermid
Lab: Vending Machine
Extra: Class Inheritance
Requirements:
	Prompts and intakes the user’s full name !
	Food selection is formatted neatly !
	Food selection shows its name with a character surrounded in parentheses !
	Every food item has a corresponding food price ! 
	Food selection is not case-sensitive !
	User must be told to use the corresponding characters for the food items !
	User must be told how to stop selecting items !
	User can choose more than one item in one order !
	If the user chooses an invalid menu item, print out the provided phrase. !
	After the user enters their choice(s) print out what the user has chosen !
	After the user enters their choice(s) print out the price of the food chosen !
	After the user confirms their choice, the loop starts over and another patron is allowed to order !
	After the 1000th customer is served, the machine prints out that it must be refurbished !
	After the 1000th customer is served, the machine shuts down. !
	User can enter a special code (‘Q’) to be able to enter a command !
	Users can enter ‘ShutMeDown’ to shut down the terminal after typing ‘Q’ !
*/
using namespace std;

typedef unsigned int uint;

/**
Check if file exists. Taken from https://stackoverflow.com/a/12774387
Inline mostly just because it can be, and I don't want to break it.
*/
inline bool exists(string const& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

int readUses() {
	if (!exists("uses.dat")) {
		return -1;
	}
	ifstream usefile;
	usefile.open("uses.dat");
	int x;
	usefile >> x;
	usefile.close();
	return x;
}

int writeUses(int add) {
	int cur = readUses();
	ofstream usefile;
	usefile.open("tmp.dat");
	usefile << cur + add;
	usefile.close();
	remove("uses.dat");
	return rename("tmp.dat", "uses.dat");
}

int setUses(int uses) {
	ofstream usefile;
	usefile.open("tmp.dat");
	usefile << uses;
	usefile.close();
	remove("uses.dat");
	return rename("tmp.dat", "uses.dat");
}

int commandParser() {
	cout << ":";
	string cmd;
	getline(cin, cmd);
	if (cmd == "ShutMeDown") {
		exit(0);
	}
	else if (cmd == "uses") {
		cout << (readUses() != -1 ? readUses() : 0) << endl;
		return 0;
	}
	else if (cmd == "break") {
		cout << "Breaking machine..." << endl;
		writeUses(1000);
		return 0;
	}
	else if (cmd == "fix") {
		cout << "Repairing machine..." << endl;
		setUses(0);
		return 0;
	}
	else if (cmd == "help") {
		cout << "ShutMeDown: Shut down the machine.\n"
			<< "uses: obtain uses count.\n"
			<< "break: simulate a machine failure.\n"
			<< "fix: execute default machine recovery script.\n"
			<< "help: display this menu.\n";
	}
}

float pricecompile(vector<Food const*> order) {
	float price = 0.0f;
	for (uint i = 0; i < order.size(); ++i) {
		price += order[i]->price; //bypassing getPrice() member function due to const issues
	}

	return price;
}

void acquireOrder(vector<Food const*> *order) {
	cout << "Please enter the item you wish to purchase: " << endl;
	cout << "1: (B)everage" << endl;
	cout << "2: (C)andy" << endl;
	cout << "3: (H)ot Dog" << endl;
	cout << "4: (P)izza" << endl;
	cout << "5: P(o)pcorn" << endl;
	
	string choice;
	choosing:
	getline(cin, choice);
	if (!cin.good()) {
		cin.clear();
		cout << "That's not a valid input. Please try again." << endl;
		goto choosing;
	}

	switch (choice.c_str()[0]) { //cheating so I can use a switch/case
		case 'B':
		case 'b':
			// dynamic allocation of memory here because of pointers and how they work.
			// should not be dangerous
			order->push_back(new Beverage());
			break;
		case 'C':
		case 'c':
			order->push_back(new Candy());
			break;
		case 'H':
		case 'h':
			order->push_back(new HotDog());
			break;
		case 'P':
		case 'p':
			order->push_back(new Pizza());
			break;
		case 'O':
		case 'o':
			order->push_back(new Popcorn());
			break;
		case 'Q':
		case 'q':
			commandParser();
			goto choosing;
			exit(2);
		default:
			cout << "That's not a valid input. Please try again." << endl;
			goto choosing;
	}

	cout << "Would you like to add anything else to your order? [Y|N]" << endl;
	end_choice:
	char usr;
	cin >> usr;
	if (!cin.good()) {
		cin.clear();
		cout << "That's not a valid input." << endl;
		goto end_choice;
	}
	cin.ignore(INT_MAX, '\n');

	if (usr == 'Y') {
		acquireOrder(order);
	}
	else if (usr == 'Q' || usr == 'q') {
		commandParser();
	}
	//No return value, thanks to the glory of pass-by-reference.
}



int main() {
	do {
		//setup
		if (exists("uses.dat")) {
			if (readUses() >= 1000) {
				cout << "Error encountered. Maintenance required." << endl;
				cout << "Booting into recovery mode..." << endl;
				do {
					commandParser();
				} while (true);
			}
		}
		else {
			ofstream usefile;
			usefile.open("uses.dat");
			usefile << 0;
			usefile.close();
		}

		//initialise order vector
		//Use a `Food const*` as opposed to a `Food const&` because otherwise issues were encountered that would require casting away const-ness
		vector<Food const*> order;

		//acquire the user's order to parse, and modify this function's order accordingly
		acquireOrder(&order); //thanks, pass-by-reference!

		float total = pricecompile(order);

		cout << "For your order of: " << endl;

		for (uint i = 0; i < order.size(); ++i) {
			cout << order[i]->name << endl;
		}

		cout << "\nYou must pay: " << total << " dollars" << endl;

		writeUses(1);
	} while (true);

}