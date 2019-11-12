#include "Pizza.h"
#include <vector>

using namespace std;

vector<string> Pizza::getCondiments() {
	return this->condiments;
}

unsigned int Pizza::getCondimentNumber() {
	return this->condiments.size();
}

void Pizza::addCondiment(string cond) {
	this->condiments.push_back(cond);
}

Pizza::Pizza(vector<string> conds) {
	this->condiments = conds;
}

Pizza::Pizza() {
	
}