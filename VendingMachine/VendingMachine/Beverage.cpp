#include "Beverage.h"

using namespace std;

const float Beverage::getPrice() {
	return this->price;
}

string Beverage::getName() {
	return this->name;
}

void Beverage::setPrice(float pr) {
	this->price = pr;
}

Beverage::Beverage() {
	std::string prodname[6]{
		"Mountain Dew Code Red",
		"Red Bull",
		"Sprite Cranberry",
		"Diet Coke",
		"Starbucks Nitro Cold Brew with 350mg of caffeine", //tejas
		"Soylent" //at request of frank
	};
	int drinktype = rand() % 6;
	switch (drinktype) {
	case 0:
		this->price = 2.50f;
		this->name = prodname[drinktype];
		break;
	case 1:
		this->price = 3.00f;
		this->name = prodname[drinktype];
		break;
	case 2:
		this->price = 2.50f;
		this->name = prodname[drinktype];
		break;
	case 3:
		this->price = 1.50f;
		this->name = prodname[drinktype];
		break;
	case 4:
		this->price = 7.00f;
		this->name = prodname[drinktype];
		break;
	case 5:
		this->price = 0.0f;
		this->name = prodname[drinktype];
		break;
	default:
		this->price = 0.0f;
		this->name = "literally nothing!";
		break;
	}
}