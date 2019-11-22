#include "HotDog.h"
#include <string>
#include <vector>
using namespace std;

vector<string> HotDog::getCondiments() {
	return this->condiments;
}

void HotDog::addCondiment(string toAdd) {
	this->condiments.push_back(toAdd);
}

unsigned int HotDog::getCondimentNumber() {
	return this->condiments.size();
}

HotDog::HotDog(vector<string> conds) {
	this->name = "Hot Dog";
	this->price = 7.00f;
	this->condiments = conds;
}

HotDog::HotDog() {
	this->name = "Hot Dog";
	this->price = 7.00f;
}