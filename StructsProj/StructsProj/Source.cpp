#include "supporter.h"
#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <iomanip>
#include <vector>
typedef unsigned int uint;
using namespace std;

struct Supporter readSupporter(ifstream& file) {
	string full;
	string first;
	string last;
	string phone;
	string buf;
	double amount;
	getline(file, full);
	getline(file, phone);
	getline(file, buf);
	amount = stod(buf);
	first = full.substr(0, full.find_first_of(" "));
	last = full.substr(full.find_first_of(" "), full.size() - 1);

	struct Supporter newSupporter = { first, last, phone, amount };

	return newSupporter;
}

bool operator>(struct Supporter& l, struct Supporter& r) {
	if (l.amount == r.amount) {
		return l.firstname > r.firstname;
	}
	else {
		return l.amount > r.amount;
	}
}

bool operator<(struct Supporter& l, struct Supporter& r) {
	if (l.amount == r.amount) {
		return l.firstname < r.firstname;
	}
	else {
		return l.amount < r.amount;
	}
}

string formatPhone(string& phone) {
	phone = phone.insert(0, "("); // ##########
	phone = phone.insert(4, ")"); // (##########
	phone = phone.insert(8, "-"); // (###)#######
	// (###)###-####
	return phone;
}

void printSupporter(struct Supporter& sup) {
	cout << left << sup.firstname << " " << sup.lastname << endl;
	cout << left << "Phone: " << right << sup.phone << endl;
	cout << left << "Donated: " << right << sup.amount << endl;
	cout << endl << endl;
}

double average(vector<struct Supporter>& sups) {
	double avg = 0;
	for (struct Supporter sup : sups) {
		avg += sup.amount;
	}
	avg /= sups.size();
	return avg;
}

void swap(struct Supporter* a, struct Supporter* b)
{
	struct Supporter t = *a;
	*a = *b;
	*b = t;
}

int partition(vector<struct Supporter>& arr, int low, int high)
{
	struct Supporter pivot = arr[high]; // pivot  
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot  
		if (arr[j] > pivot)
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(vector<struct Supporter>& arr, int low, int high) {
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main() {
	vector<struct Supporter> sups;
	//find the file
	ifstream file;
	file.open("DonorList.txt");
	string line;
	uint count = 0;
	while (getline(file, line)) {
		count++;
	}
	file.clear();
	file.seekg(0, ios::beg); //go to beginning
	for (uint i = 0; i < count / 3; i++) { //lines will always be divisible by 3
		sups.push_back(readSupporter(file));
	}
	//sort the list
	quickSort(sups, 0, sups.size() - 1);

	//deal with phones
	for (uint i = 0; i < sups.size(); i++) { //foreach didn't work for some reason. Something weird with scopes and references, no doubt.
		sups[i].phone = formatPhone(sups[i].phone);
	}
	//print supporters
	cout << "And the award for \"Most Generous Donor\" goes to:" << endl;
	printSupporter(sups[0]);
	cout << "Other donors are:" << endl;
	for (uint i = 1; i < sups.size(); i++) {
		printSupporter(sups[i]);
	}
	cout << "Our average donor gave " << average(sups) << endl;

}