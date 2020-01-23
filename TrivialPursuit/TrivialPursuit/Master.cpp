#include "Master.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned int uint;

bool Master::isOpen() {
	return master_table.is_open();
}

bool Master::open() {
	master_table.open("master.txt");
	return (master_table.fail() ? false : true);
}

string Master::getQuestion(uint questionNum) {
	gotoLine(master_table, questionNum);
	return sliceByDelim(readLine(), MASTER_DELIM)[1];
}

void Master::gotoLine(ifstream& file, uint num) {
	file.seekg(std::ios::beg);
	for (int i = 0; i < num - 1; i++) {
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	//pass-by-reference yay!
}

vector<string> Master::sliceByDelim(string str, char delim) {
	vector<string> end;
	istringstream iss { str };
	string s;

	while (getline(iss, s, delim)) {
		end.push_back(s);
	}
	return end;
}

string Master::readLine() {
	string tmp;
	getline(master_table, tmp);
	return tmp;
}

vector<string> Master::getAnswers(int quest) {
	// Go to the question line specified
	gotoLine(master_table, quest);

	vector<string> ln = sliceByDelim(readLine(), MASTER_DELIM);
	
	//position 0 is the number of answers
	//fetch all answers starting from position 2
	vector<string> rtrn;
	for (int i = 2; i < (2 + stoi(ln[0])); i++) {
		rtrn.push_back(ln[i]);
	}
	return rtrn; //return the vector of answers
}

char Master::getCorrect(int lineNum) {
	//fetch question line and parse
	gotoLine(master_table, lineNum);
	vector<string> ln = sliceByDelim(readLine(), MASTER_DELIM);

	//correct answer is final position
	return ln.back()[0]; //grab first char
}

vector<char> Master::getAllCorrect() {
	master_table.seekg(std::ios::beg); //easiest way to go to first line of file
	string tmp;
	vector<char> rtrn;
	while (getline(master_table, tmp)) {
		rtrn.push_back(sliceByDelim(tmp, MASTER_DELIM).back()[0]); //what a cancer line of code.
	}
	return rtrn;

}

uint Master::getLines() {
	master_table.seekg(std::ios::beg);
	uint index = 0;
	string tmp;
	while (getline(master_table, tmp)) {
		index++;
	}
	return index;
}

Master::Master(string masterfile) {
	master_table.open(masterfile);
}