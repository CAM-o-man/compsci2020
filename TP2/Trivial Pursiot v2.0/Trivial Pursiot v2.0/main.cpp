#include "Master.h"
#include "Save.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;
typedef unsigned int uint;

int main() {

	Master master("master.csv"); //init master file

	Save save("usr.sav"); //init save file; won't be written to for a while

	cout << "Welcome to TRIVIAL PURSUIT!" << endl;
	cout << "Let's get started, shall we?" << endl;

	for (int i = 0; i < master.getAllData().size(); i++) {
		cout << "Question " << i + 1 << ":" << endl;
		string tmp = master.getQuestion(i);
		cout << tmp << endl;
		cout << left << "a: " << master.getAnswers(i)[0] << right << " b: " << master.getAnswers(i)[1] << endl;
		cout << left <<  "c: " << master.getAnswers(i)[2] << right << " d: " << master.getAnswers(i)[3] << endl;
		cout << endl;
		cout << "Your answer? Please enter the character: " << endl;
		char usr;
		cin >> usr;
		if (!cin) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input. Please try again. " << endl;
			i--;
			continue;
		}
		save.bufferAnswer(usr);
		cout << "Next!" << endl;
	}
	save.writeBuf();

}