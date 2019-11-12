#include "Candy.h"

using namespace std;

Candy::Candy() {
	string prodname[5]{
		"Snickers",
		"Charleston Chew",
		"Milky Way",
		"Heath",
		"M&Ms"
	};

	int picker = rand() % 5;

	switch (picker) {
		case 0:
			this->price = 1.0f;
			this->name = prodname[picker];
			break;
		case 1:
			this->price = 2.0f;
			this->name = prodname[picker];
			break;
		case 2:
			this->price = 1.0f;
			this->name = prodname[picker];
			break;
		case 3:
			this->price = 0.5f;
			this->name = prodname[picker];
			break;
		case 4:
			this->price = 0.75f;
			this->name = prodname[picker];
			break;
		default:
			this->price = 0.0f;
			this->name = "Absolutely nothing.";
	}

}