#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned int uint;


int favourite(int favnum, int* nums) {
	int count = 0;
	for (uint i = 0; i < 10; i++) { // I can be sure that the arr is only 10 long.
		if ( *(nums + i) == favnum ) {
			count++;
		}
	}
	return count;
}

int recogniser(string* words) {
	int count = 0;
	for (uint i = 0; i < 5; i++) {
		const string tmp = *(words + i); //preserve original value
		reverse((words + i)->begin(), (words + i)->end()); //modifies by reference
		cout << *(words + i) << endl;
		if (tmp == *(words + i)) {
			count++;
		}
	}

	return count;
}

int main() {
	// part 1

	cout << "Please enter 10 numbers." << endl;
	int usrarr[10];
	for (uint i = 0; i < 10; i++) {
		cin >> usrarr[i];
		if (!cin) {
			cout << "It appears that input isn't valid. Let's try that again, shall we?" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			i--;
			continue;
		}
		cout << "Successfully received." << endl;
	}

	cout << "What's your favourite number?" << endl;
	redo_fav: //just gotta ruin program flow really quick
	int fav;
	cin >> fav;
	if (!cin) {
		cout << "That's not valid. Try again." << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		goto redo_fav;
	}

	//pass into func
	int favtimes = favourite(fav, usrarr);

	cout << "You entered your favourite number " << favtimes << " times." << endl;
	

	// part 2: palindrome recogniser
	//it's perfect, because strings are just char arrays, and as such, can be reversed.
	//unlike java

	string palinarr[5] = {
		"radar", "warts", "evil", "racecar", "toot"
	};

	int palins = recogniser(palinarr);

	cout << palins << " of those words were palindromes." << endl;

}