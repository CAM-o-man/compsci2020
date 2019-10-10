#include "pch.h"
#include <iostream>

using namespace std;

int main() {
	int test;
	cin >> test;
	cout << typeid(test).name() << endl;
	return 0;
}