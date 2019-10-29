#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "GetData.h"
#include <map>

using namespace std;
typedef string str;

void usrClasses(map<str, int>& classes) {
	//get name and grade from user
	str name;
	int grade;
	bool isValid = false;
	cout << "Please input a name for the class: " << endl;
	getline(cin, name);
	do {
		cout << "Please input your grade for " << name << endl;
	} while (!(isValid = getValidInt(grade)));
	classes[name] = grade;
}

bool passer(map<str, int>& classes, bool& infracs) {
	if (infracs) {
		return false;
	}
	
	if (classes.size() >= 5 && classes.size() <= 8) {
		for (auto i : classes) {

		}
	}
}