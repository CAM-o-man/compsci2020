#include "Matrix.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

extern template class Matrix<int>; //only use ints here. To expand, just add another extern template declaration
//extern template class Matrix<string>;

int main() {
	Matrix<int> mat = Matrix<int>(); //initialised as dynamic just for example.

	vector<int> arr;
	for (uint i = 0; i < 10; i++) {
		arr.push_back(rand() % 16);
	}

	mat.addFilledRow(arr);
	mat.addRow();
	mat.addValue(7);
	mat.addValue(11);

	cout << mat;

}