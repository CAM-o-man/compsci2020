#include "Food.h"

std::string Food::getName(void) {
	return this->name;
}

float Food::getPrice(void) {
	return this->price;
}

void Food::setPrice(float p) {
	this->price = p;
}