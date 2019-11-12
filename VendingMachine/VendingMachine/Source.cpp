#include "Food.h"
#include "Beverage.h"
#include "Candy.h"
#include "HotDog.h"
#include "Popcorn.h"
#include "Pizza.h"
#include <iostream>

using namespace std;

int main() {
	Beverage test = Beverage();
	cout << test.getName() << endl;
	cout << test.getPrice() << endl;
	cout << typeid(test).name() << endl;
}