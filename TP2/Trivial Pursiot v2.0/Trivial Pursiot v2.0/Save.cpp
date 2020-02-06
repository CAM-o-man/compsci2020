#include "Save.h"
#include <fstream>

using namespace std;

Save::Save(string fn) {
	this->filename = fn;
}

void Save::bufferAnswer(char ans) {
	answers.push_back(ans);
}

vector<char> Save::getBuf() {
	return this->answers;
}

void Save::writeBuf() {
	ofstream file(filename);
	
	for (char c : answers) {
		file << c << endl;
	}
}

char Save::getSpecific(int ans) {
	return answers[ans];
}
