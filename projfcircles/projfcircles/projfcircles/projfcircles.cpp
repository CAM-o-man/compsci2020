// projfcircles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#define _USE_MATH_DEFINES // required for using math.h's pi
#include <math.h>
#include <iomanip>

using namespace std;

float calcArea(int rad) {
	return (M_PI * pow(rad, 2));
}

float calcVol(int rad) {
	return ((4 / 3) * M_PI * pow(rad, 3));
}

float calcDiff(float vol1, float vol2) {
	if (vol1 > vol2) {
		return vol1 - vol2;
	}
	else {
		return vol2 - vol1;
	}
}

//help with printing
template<typename T> void printElement(T t, int width) {
	cout << left << setw(width) << setfill(' ') << setprecision(1) << fixed << t;
}

int main() {
	int rads[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char separator = ' ';
	int numLen = 4;

	printElement("Radii", 15);
	printElement("Areas", 15);
	cout << endl;
	for (int r : rads) {
		printElement(r, 15);
		printElement(calcArea(r), 15);
	}
}