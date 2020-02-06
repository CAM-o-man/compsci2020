#include "Master.h"
#include <sstream>



using namespace std;
typedef unsigned int uint;

Master::Master(string name) {
	this->file = name;
	this->readAll();
}

void Master::readAll() {
	ifstream quest;
	quest.open(this->file);
	string tmp;
	vector<string> tmpvect;

	while (getline(quest, tmp)) {
		data.push_back(tmp);
	}

	for (string s : data) {
		istringstream iss{ s };
		while (getline(iss, tmp, '|')) {
			tmpvect.push_back(tmp);
		}
		questions.push_back(tmpvect[2]);
		answers.push_back(tmpvect.back());
		tmpvect.clear();
	}
	return;
}

vector<string> Master::getAllData() {
	return this->data;
}

string Master::getQuestion(int num) {
	return this->questions[num];
}

vector<string> Master::getAnswers(int num) {
	vector<string> rtrn;
	string line = this->data[num];
	string tmp;
	istringstream iss{ line };
	for (int i = 0; getline(iss, tmp); i++) {
		if (i > 2) {
			if (tmp.length > 1) {
				rtrn.push_back(tmp);
			}
			else {
				continue;
			}
		}
	}

	return rtrn;
}

char Master::getCorrect(int num) {
	string line = this->data[num];
	vector<string> full;
	string tmp;
	istringstream iss{ line };
	while (getline(iss, tmp, '|')) {
		full.push_back(tmp);
	}
	return full.back()[0];
}

vector<char> Master::getAllCorrect() {
	vector<char> rtrn;
	for (int i = 0; i < data.size(); i++) {
		rtrn.push_back(getCorrect(i));
	}
	return rtrn;
}