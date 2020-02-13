#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

int main() {
	cout << "Worksheet 1, question 1: " << endl;
	
	vector<int> sneakers(3);
	sneakers[0] = 10;
	sneakers[1] = 22;
	sneakers[2] = 15;
	vector<double> sneakersPrice(3);
	sneakersPrice[0] = 64.45;
	sneakersPrice[1] = 87.35;
	sneakersPrice[2] = 93.98;
	cout << "The total number of sneakers we have in stock = ";
	cout << sneakers[0] + sneakers[1] + sneakers[2] << " pairs." << endl;
	cout << "We have " << sneakers[1] << " available pairs of sneakers which cost  $";
	cout << sneakersPrice[1] << " per pair. \n"; double total = sneakers[0] * sneakersPrice[0];
	total += sneakers[1] * sneakersPrice[1];
	total += sneakers[2] * sneakersPrice[2];
	cout << "Our total store investment in sneakers is $" << total << ". \n";

	cout << "Worksheet 1, part 2: \n";

	float finalGrade[] = { 85.8f,    93.7f,   76.0f,   88.5f,   100.0f,    91.3f };
	float sum = 0;
	for (float i : finalGrade) {
		sum += i;
	}
	sum /= 6;
	cout << "Average: " << setprecision(2) << fixed << sum << endl;

	cout << "Worksheet 1 Part 3: " << endl;

	vector<int> rands;

	for (int i = 0; i < 10; i++) {
		rands.push_back(rand());
	}

	for (int i : rands) {
		cout << i << endl;
	}

	reverse(rands.begin(), rands.end());

	for (int i : rands) {
		cout << i << endl;
	}

	int total3 = 0;
	for (int i : rands) {
		if (i % 2 != 0) {
			continue;
		}
		total3++;
	}

	cout << "Total even numbers in array: " << total3 << endl;

	cout << "Worksheet 1 part 4" << endl;

	int ages[20];

	for (uint i = 0; i < size(ages); i++) {
		cout << "Enter age #" << i + 1 << ": " << endl;
		cin >> ages[i];
		if (!cin) {
			cout << "That's not valid input. Try again." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			i--;
			continue;
		}
	}
	total = 0;
	
	for (int age : ages) {
		if (age <= 15) {
			continue;
		}
		total++;
	}
	cout << setprecision(0) << fixed << "There are " << total << " people over 15 in the ages you entered." << endl;

	cout << "Worksheet 1 part 5" << endl;

	int sales[7];

	for (int i = 0; i < 7; i++) {
		*(sales + i) = rand(); //assign values to array
	}

	bool quit = false;
	int dayNum;
	string response;
	do {
		cout << "Please enter the number of the day you wish to view sales for." << endl;
		cin >> dayNum;
		if (!cin) {
			cout << "That's not valid input." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}

		cout << *(sales + (dayNum - 1)) << "" << endl;

		cout << "Do you wish to continue? " << endl;

		cin.ignore(INT_MAX, '\n');
		getline(cin, response);
		if (response == "yes") {
			continue;
		}
		else {
			quit = true;
		}

	} while (quit == false);
	
	return 0;
}