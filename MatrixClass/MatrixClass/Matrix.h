#pragma once
#include <ostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
typedef unsigned int uint;

template<typename T>
class Matrix {
private:
	std::vector< std::vector<T> > container;

public:

	Matrix<T>() {
		vector< vector< T > > tmp;
		this->container = tmp;
	}

	Matrix<T>(int x, int y) {
		vector< vector<T> > tmp;
		for (uint i = 0u; i < x; i++) {
			tmp.push_back(vector<T>(y, NULL)); //test: may not work, may work. (void*)0 is supposed to be the value of NULL
		}
		this->container = tmp;
	}

	void addRow() {
		
		this->container.push_back(vector<T>());
		return;
		
	}

	std::vector<T> getRow(int x) {
		return this->container[x];
	}

	int getValue(int x, int y) {
		return this->container[x][y];
	}

	void addValueToRow(int x, T val) {
		this->container[x].push_back(val);
	}

	void addValueAtCoordinates(int x, int y, T val) {
		typename vector<T>::iterator tmp = this->container[x].begin() + y; //typename included because it complained if I didn't (Compiler Error C7510)
		this->container[x].insert(tmp, val);
	}

	void addFilledRow(std::vector<T> x) {
		this->container.push_back(x);
	}

	void addValue(T x) {
		this->container.back().push_back(x); //vector<>::back() acquires a reference to the final element of the vector.
	}

	friend std::ostream& operator<< (std::ostream& out, const Matrix<T>& in) {
		for (vector<T> row : in.container) {
			for (T val : row) {
				cout << "[" << val << "]" << " ";
			}
			cout << endl;
		}

		return out;
	}

	typename vector<T>::iterator getIteratorAtPosition(int x, int y) {
		typename vector<T>::iterator iter = this->container[x].begin() + y;
		return iter;
	}
};