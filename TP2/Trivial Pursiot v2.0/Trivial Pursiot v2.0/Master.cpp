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
		questions.push_back(tmpvect[1]);
		vector<string> x{ tmpvect[2], tmpvect[3], tmpvect[4], tmpvect[5] };
		answers.push_back(x);
		correct.push_back(tmpvect.back());
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
	return answers[num];
}

char Master::getCorrect(int num) {
	return correct[num][0];
}

vector<char> Master::getAllCorrect() {
	vector<char> rtrn;
	for (int i = 0; i < data.size(); i++) {
		rtrn.push_back(getCorrect(i));
	}
	return rtrn;
}