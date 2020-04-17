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
	T container[][];

public:
	Matrix<T>(int x, int y) {
		T tmp[x][y];
		this->container = tmp;
	}

	

};