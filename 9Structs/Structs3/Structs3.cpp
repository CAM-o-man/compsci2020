#include <iostream>
#include <string>
#include <sstream>

using namespace std;
typedef unsigned int uint;

struct Student {

	string name;
	int avg;
	int clss;

};

ostream& operator<<(ostream& out, struct Student in) {
	out << in.name;
	return out;
}

int main() {
	
	struct Student studs[5];

	for (struct Student& stud : studs) {
		redo: //I'm going to hate myself
		cout << "Please enter the student's name: " << endl;
		string tmp;
		getline(cin, tmp);
		cout << "Now, that student's grade: " << endl;
		int grd;
		cin >> grd;
		if (!cin) {
			cout << "Looks like that's not valid input. Let's try that again, shall we?" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			goto redo;
		}
		cin.ignore(INT_MAX, '\n'); //flush cin buffer
		int grad;
		cout << "Graduation year? : " << endl;
		cin >> grad;
		if (!cin) {
			cout << "Looks like that isn't valid input. Let's try that again, shall we?" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			goto redo;
		}
		cin.ignore(INT_MAX, '\n');

		stud = { tmp, grd, grad };
		//next
	}

	//print list of all students to graduate in 2020
	ostringstream oss;
	for (struct Student& stud : studs) {
		if (stud.clss == 2020) {
			oss << stud << endl;
		}
	}
	if (oss.tellp() == 0) {
		cout << "There are no students graduating in 2020." << endl;
	}
	else {
		cout << "Students graduating in 2020: " << endl;
		cout << oss.str();
	}

	return 0;
}