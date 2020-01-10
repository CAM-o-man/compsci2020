// projfcircles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Name: Connor McDermid
Lab: 5.0 Functions
Requirements:
	Calculates the area of circles with radii from 1-10 *
	Radii is generated in main *
	Area is calculated in a separate function *
	Area is returned to main *
	Area is printed in main *
	Area has a precision of 1 decimal (tenths place)
	Printed in a 2 column table with radii and area underlined (as seen on lab information sheet)
	Passes all even radii to a method to calculate the volume of a sphere
	Returns volume value to main
	Volume has a precision of one decimal (tenths place)
	Printed in a 2 column table with radii and volume underlined (as seen on lab information sheet)
	User must be prompted to input 2 radii
	Inputs must be error trapped to prompt for another input upon incorrect input
	Both radii are sent to a function to compute the volume
	Method also computes the difference between the two volumes
	Volumes are printed from main
	Differences are printed from main
	Output is nicely formatted

*/
#include <iostream>
#define _USE_MATH_DEFINES // required for using math.h's pi
#include <math.h>
#include <iomanip>
#include <string>

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

//help with printing. I didn't want to type everything all over again.
template<typename T> void printElement(T t, int width) {
	cout << left << setw(width) << setfill(' ') << setprecision(1) << fixed << t;
}

string compare(int rad1, int rad2) {
	int vol1 = calcVol(rad1);
	int vol2 = calcVol(rad2);

	if (vol1 > vol2) {
		return "The first input's volume is greater than the second's by " + to_string(calcDiff(vol1, vol2));
	}
	else if (vol2 > vol1) {
		return "The second input's volume is greater than the first's by " + to_string(calcDiff(vol1, vol2));
	}
	else {
		return "Your input's volumes, and thus your inputs, are exactly the same.";
	}
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
		cout << endl;
	}
	
	printElement("Radii", 15);
	printElement("Volumes", 15);
	cout << endl;

	for (int r : rads) {
		if (r % 2 != 0) {
			continue;
		}
		printElement(r, 15);
		printElement(calcVol(r), 15);
		cout << endl;
	}

	//prompt user for 2 radii

	int usr[2];
	redo:
	cout << "Please enter a radius: " << endl;

	cin >> usr[0];
	if (!cin.good()) {
		cin.clear();
		cout << "That's not a valid input. Please try again." << endl;
		goto redo;
	}
	cin.ignore(INT_MAX, '\n');

	cout << "Please enter a second radius: " << endl;

	cin >> usr[1];
	if (!cin.good()) {
		cin.clear();
		cout << "That's not a valid input. Please try again." << endl;
		goto redo;
	}
	cin.ignore(INT_MAX, '\n');
	
	//both radii obtained, run through diff
	cout << compare(usr[0], usr[1]);

}