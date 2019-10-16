#include "Student.h"
#include "Class.h"
#include <iostream>
#include <string>

using namespace std;


bool checkRoll(Student s) { //FIXME: Exception thrown: read access violation. \n **this** was 0x9AC9906C
	unsigned int count = s.getClassCount();
	if (!(count >= 5 && count <= 8)) {
		return false;
	}
	unsigned int avg = s.getAvg();
	if (!(avg >= 90)) {
		return false;
	}
	return true;
}

int main() {
	cout << "Welcome, student! Please enter your full name." << endl;
	string name;
	cin.ignore();
	getline(cin, name);
	Student stud = Student(name);
	retry:
	cout << "Welcome, student! Please enter the number of courses you are taking." << endl;
	int coursenum;
	cin >> coursenum;
	if (cin.fail()) {
		cin.clear();
		cout << "That's not a number. Please try again." << endl;
		goto retry;
	}
	if (coursenum > 8) {
		cout << "Hey! What are you trying to pull?" << endl;
		cout << "That's not a legal number of courses!" << endl;
		goto retry;
	}
	int tmpgrade;
	string tmpname;
	for (int i = 0; i < coursenum; i++) {
		cout << "Please enter the name of your course." << endl;
		cin.ignore();
		getline(cin, tmpname);
		cout << "Now, please enter your grade in said course." << endl;
		cin >> tmpgrade;
		if (cin.fail()) {
			cin.clear();
			cout << "That's not a number. Please try again." << endl;
			i--;
			continue;
		}
		if (tmpgrade > 100) {
			cout << "That's not a valid grade. Please try again." << endl;
			i--;
			continue;
		}
		Class newclass = { tmpgrade, tmpname };
		stud.addClass(newclass);
	}

	if (checkRoll(stud)) {
		cout << "Congratulations, " << stud.getName() << " you have made the honour roll!" << endl;
	} else {
		cout << "Unfortunately, " << stud.getName() << ", you have not made the honour roll." << endl;
	}
	return 0;
}