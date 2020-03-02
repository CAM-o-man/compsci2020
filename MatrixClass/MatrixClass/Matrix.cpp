/*
#include "Matrix.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;
typedef unsigned int uint;

extern template class Matrix<int>; //expandable, just add `extern template class Matrix<typename>;`

template<typename T>
Matrix<T>::Matrix() {
	this->container = vector<T>();
}

template<typename T>
void Matrix<T>::addRow() {
	this->container.push_back(vector<T>());
	return;
}

template<typename T>
vector<T> Matrix<T>::getRow(int x) {
	return this->container[x];
}

template<typename T>
int Matrix<T>::getValue(int x, int y) {
	return this->container[x][y];
}

template<typename T>
void Matrix<T>::addValueToRow(int x, T val) {
	this->container[x].push_back(val);
}

template<typename T>
void Matrix<T>::addValueAtCoordinates(int x, int y, T val) {
	this->container[x].insert(y, val);
}

template<typename T>
void Matrix<T>::addFilledRow(vector<T> x) {
	this->container.push_back(x);
}

template<typename T>
void Matrix<T>::addFilledRow(T* x) {
	vector<T> vals(begin(x), end(x)); //range constructor
	this->container.push_back(vals);
}

template<typename T>
void Matrix<T>::addValue(T val) {
	this->container.back().push_back(T); //vector<>::back() acquires a reference to the final element of the vector.
}

template<typename T>
ostream& operator<< <> (ostream& out, Matrix<T>& in) {
	for (vector<T> row : in.container) {
		for (T val : row) {
			cout << val << ", ";
		}
		cout << endl;
	}

	return out;
}
*/