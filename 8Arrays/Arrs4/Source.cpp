#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

template<class Iter, class T> Iter binary_find(Iter begin, Iter end, T val) {
	Iter i = lower_bound(begin, end, val);

	if (i != end && !(val < *i)) {
		return i; //found
	}
	else {
		return end; //not found
	}
}

int main() {

	int winning[6] = {
		307, 521, 416, 154, 243, 893
	};

	redo_ticket:
	cout << "Please enter your ticket number." << endl;
	int usr;
	cin >> usr;
	if (!cin) {
		cout << "That doesn't sound like a ticket we sell. Maybe try again, or check a different retailer?" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		goto redo_ticket;
	}
	if (binary_search(begin(winning), end(winning), usr)) {
		cout << "Congratulations! You're a winner!" << endl;
	}
	else {
		cout << "Unfortunately, that's not a winning number. Try again next time!" << endl;
	}

	int testarr[8] = {
		5, 6, 10, 14, 15, 16, 18, 22
	};

	cout << "Your key?" << endl;

	int key;
	redo_key:
	cin >> key;
	if (!cin) {
		cout << "That's not valid input." << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		goto redo_key;
	}
	cout << ((binary_find(begin(testarr), end(testarr), key) != end(testarr)) ? "Your key is in the array." : "Your key is not in the array.") << endl;

	return 0;
	
}