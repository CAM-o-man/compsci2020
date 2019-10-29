#include "GetData.h"
#include <string>
using namespace std;

bool getValidInt(int& t_int) {
	string intScratch = "";
	bool isValid = false;

	getline(cin, intScratch);
	isValid = intScratch.find_first_not_of("0123456789") == string::npos;
	if (isValid) {
		t_int = stoi(intScratch);
	}
	return isValid;
}
bool getValidFloat(float& t_float) {
	string floatScratch = "";
	bool isValid = false;

	getline(cin, floatScratch);
	isValid = floatScratch.find_first_not_of("0123456789.") == string::npos;
	if (isValid) {
		t_float = stof(floatScratch);
	}
	return isValid;
}
bool getValidDouble(double& t_double) {
	string doubleScratch = "";
	bool isValid = false;

	getline(cin, doubleScratch);
	isValid = doubleScratch.find_first_not_of("0123456789.") == string::npos;
	if (isValid) {
		t_double = stod(doubleScratch);
	}
	return isValid;
}
