#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <iomanip>

using namespace std;
typedef unsigned int uint;

/*!
Binary Search!
From https://stackoverflow.com/a/446327
*/
template<class Iter, class T> Iter binary_find(Iter begin, Iter end, T val) {
	Iter i = std::lower_bound(begin, end, val);
	
	if (i != end && !(val < *i)) {
		return i; //found
	}
	else {
		return end; //not found
	}
}

void printarr(string* arr) {
	for (uint i = 0; i < arr->length; i++) {
		cout << arr[i] << endl;
	}
}

int main() {
	//part 1
	vector<int> dist({ 50, 100, 200, 400, 800, 1000 });

	double time[6] = {
		7.24, 13.54, 28.03, 71.12, 158.67, 220.15
	};

	cout << "What distance would you like to search?" << endl;
	redo_query:
	int usr;
	cin >> usr;
	if (!cin) {
		cout << "Seems like you didn't enter a valid value." << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		goto redo_query;
	}
	
	//find location
	std::vector<int>::iterator x = binary_find(dist.begin(), dist.end(), usr);
	int query = x - dist.begin();

	cout << "For your query of " << usr << " at index " << query /*For debugging*/ << " the time was " << time[query] << endl;

	//part 3

	string studnames[5] = {
		"Zachary", "Jordan", "Frank", "Tejas", "Sai"
	};
	string addresses[5] = {
		"a house probably", "a second house, probably", "Maybe like a house or something", "a house", "who knows"
	};
	string phones[5] = {
		"666-666-6666", "999-999-9999", "1-800-222-4444", "1-800-420-6969", "0x0: no phone number"
	};

	printarr(studnames);
	printarr(addresses);
	printarr(phones);

	cout << studnames[2] << " " << addresses[2] << " " << phones[2] << endl;

}