#include "Food.h"
#include "Beverage.h"
#include "Candy.h"
#include "HotDog.h"
#include "Popcorn.h"
#include "Pizza.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

float pricecompile(vector<Food const*> order) {
	float price = 0.0f;
	for (uint i = 0; i < order.size(); ++i) {
		price += order[i]->price; //bypassing getPrice() member var due to const issues
	}

	return price;
}

void acquireOrder(vector<Food const*>* order) {
	cout << "Please enter the item you wish to purchase: " << endl;
	cout << "1: Beverage" << endl;
	cout << "2: Candy" << endl;
	cout << "3: Hot Dog" << endl;
	cout << "4: Pizza" << endl;
	cout << "5: Popcorn" << endl;
	
	int choice;
	choosing:
	cin >> choice;
	if (!cin.good()) {
		cin.clear();
		cout << "That's not a valid input. Please try again." << endl;
		goto choosing;
	}
	cin.ignore(INT_MAX, '\n'); //Flush cin buffer

	switch (choice - 1) {
		case 0:
			order->push_back(new Beverage());
			break;
		case 1:
			order->push_back(new Candy());
			break;
		case 2:
			order->push_back(new HotDog());
			break;
		case 3:
			order->push_back(new Pizza());
			break;
		case 4:
			order->push_back(new Popcorn());
			break;
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
	//No return value, thanks to the glory of pass-by-reference.
}

int main() {
	//initialise order vector
	vector<Food const*> order;

	//acquire the user's order to parse, and modify this function's order accordingly
	acquireOrder(&order); //thanks, pass-by-reference!

	float total = pricecompile(order);

	cout << "For your order of: " << endl;

	for (uint i = 0; i < order.size(); ++i) {
		cout << order[i]->name << endl;
	}

	cout << "\nYou must pay: " << total << " dollars" << endl;

}