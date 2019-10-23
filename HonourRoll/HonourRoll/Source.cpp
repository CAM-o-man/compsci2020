#include "Class.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;


unsigned int findAvg(Student& s) {
	vector<Class> classes = s.getClasses();
	unsigned int sum = 0;

	for (unsigned int i = 0; i < classes.size(); i++) {
		sum += classes[i].getGrade();
	}

	unsigned int avg = sum / classes.size();

	return avg;
}

bool passer(Student& s) {
	if (s.hasInfractions()) {
		return false;
	}
	if (s.getClasses().size() >= 5 && s.getClasses().size() <= 8) {
		if (findAvg(s)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	cout << "Welcome to the Honour Roll Acceptance Test." << endl;
	cout << "Due to technical constraints, at this time admission relies on the honour system." << endl;
	cout << "If you're trying to join an honour society, you should be honourable." << endl;
	cout << "Keeping this in mind, please enter your name." << endl;
	string name;
	cin.ignore();
	getline(cin, name);
	cout << "Now, please enter the number of classes you're taking." << endl;
	retry:
	unsigned int classnum;
	cin >> classnum;
	if (cin.fail()) {
		cin.clear();
		cout << "That wasn't a natural number. Please try again." << endl;
		goto retry;
	}
	vector<Class> classes;
	string tmpname;
	unsigned int tmpgrade;
	for (unsigned int i = 0; i < classnum; i++) {
		cout << "Please enter the name of class number " << i + 1 << endl;
		cin.ignore();
		getline(cin, tmpname);
		cout << "Now please enter the grade you have in this class." << endl;
		cin >> tmpgrade;
		if (cin.fail()) {
			cin.clear();
			cout << "That's not a valid grade." << endl;
			i--;
			continue;
		}
		Class tmpclass(tmpgrade, tmpname);
		classes.push_back(tmpclass); //critical question here - tmpclass immediately goes out of scope and its memory will be deallocated. 
									//Does a vector store a copy of or a reference to tmpclass?
	}								//Answer - it does store a copy as opposed to a reference as far as I can tell. Otherwise, memory would leak and the program would break.
	Student stud(name, classes);
	cout << "Do you have any disciplinary infractions? [Y|N]" << endl;
	cin.ignore();
	string dis;
	getline(cin, dis);
	stud.setInfractions(dis == "Y");
	if (passer(stud)) {
		cout << "You have passed, and are on the honour roll. Congratulations." << endl;
		return 0;
	}
	else {
		cout << "Unfortunately, you have not made the honour roll. Better luck next time!" << endl;
		return 0;
	}
}