#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
	return;
}

void bubbleSort(int* arr, int siz) { //takes sizeof(arr) as parameter to make it less cluttered
	bool swapped;
	for (uint i = 0; i < siz - 1; i++) {
		swapped = false;
		for (uint j = 0; j < siz - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]); //passes a pointer to the jth and j+1th element of the arr, for ease of access.
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}

void ExchangeSort(int* arr) {
	int temp;   // holding variable
	int arrLength = sizeof(arr);
	for (uint i = 0; i < (arrLength - 1); i++)    // element to be compared
	{
		for (uint j = (i + 1); j < arrLength; j++)   // rest of the elements
		{
			if (arr[i] > arr[j])          // ascending order
			{
				temp = arr[i];          // swap
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}

template<class Iter, class T> Iter binary_find(Iter begin, Iter end, T val) {
	Iter i = lower_bound(begin, end, val);

	if (!!= end && !(val < *i)) {
		return i;
	}
	else {
		return end;
	}
}

int main() {
	int randnums[50];

	for (uint i = 0; i < sizeof(randnums); i++) {
		randnums[i] = rand() % 100;
	}

	cout << "The array contains 50 numbers between 0 and 100 inclusive." << endl;
	cout << "Please establish your key: " << endl;
	int key;
	redo_input:
	cin >> key;
	if (!cin) {
		cout << "That's not a valid number. Please try again." << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		goto redo_input;
	}

	cout << ((binary_find(begin(randnums), end(randnums), key) != end(randnums)) ? "Your key is in the array." : "Your key is not in the arrray.")
		<< endl;

	cout << "Array sorted in descending order using bubble sort." << endl;
	bubbleSort(randnums, sizeof(randnums));
	cout << randnums << endl;

	cout << "Array sorted in ascending order by exchange sort." << endl;


}