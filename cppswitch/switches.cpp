#include <string>
#include <iostream>
#include <map>
using namespace std;


int main() {
	redo: //For invalid inputs
	cout << "Please enter your letter grade" << endl;
	string usr;
	map<string, int> grades = { //switch/case can only take integral values
		{"A", 1}, {"B", 2}, //Not zero based because default value is 0
		{"C", 3}, {"D", 4},
		{"F", 5}
	};
	cout << grades["E"]; //Testing map shit
	getline(cin, usr);
	switch(grades[usr]) {
		case 0:
			cout << "Your work is outstanding!" << endl;
			break;
		case 1:
			cout << "You are doing good work!" << endl;
			break;
		case 2:
			cout << "YOur work is satisfactory." << endl;
			break;
		case 3:
			cout << "You need to work a little harder." << endl;
			break;
		case 4:
			cout << "Please see me for extra help!" << endl;
			break;
		default:
			cout << "THat's not a valid letter grade." << endl;
			cout << "Have you checked that it's captital?" << endl;
			goto redo;
	}
	return 0;
}
