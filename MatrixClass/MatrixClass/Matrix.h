#pragma once
#include <vector>

template<typename T>
class Matrix {
private:
	std::vector< std::vector<T> > container;

public:

	Matrix<T>();

	void addRow();

	std::vector<T> getRow(int);

	int getValue(int, int);

	void addValueToRow(int, T);

	void addValueAtCoordinates(int, int, T);

	void addFilledRow(std::vector<T>);

	void addFilledRow(T*);
};