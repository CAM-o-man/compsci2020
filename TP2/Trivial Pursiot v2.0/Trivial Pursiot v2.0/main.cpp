#include "Master.h"
#include "Save.h"
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;
typedef unsigned int uint;

int correct(Master& master, Save& save) {
	vector<char> right = master.getAllCorrect();
	vector<char> doubt = save.getBuf();
	int tally = 0;

	for (uint i = 0; i < doubt.size(); i++) {
		if (doubt[i] == right[i]) {
			tally++;
		}
	}
	return tally;
}

int main() {

	Master master("master.csv"); //init master file

	Save save("usr.sav"); //init save file; won't be written to for a while

	cout << "Welcome to TRIVIAL PURSUIT!" << endl;
	cout << "Let's get started, shall we?" << endl;

	for (uint i = 0; i < master.getAllData().size(); i++) {
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
		cin.ignore(INT_MAX, '\n'); // if multiple chars were entered, cin would consume them all and questions would be skipped
		save.bufferAnswer(usr);
	}

	save.writeBuf();
	cout << "Now, let's check your score." << endl;
	float denominator = (float)master.getAllData().size();
	float numerator = (float)correct(master, save);

	cout << "Your score is " << numerator << " correct out of " << denominator << "." << endl;
	cout << "That's " << (float)(numerator / denominator) * 100 << " percent." << endl;


}