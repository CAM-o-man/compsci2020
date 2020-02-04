#include "Save.h"
#include <string>
using namespace std;

Save::Save(fstream &file):playersave(file) {} //aaaaaah why

bool Save::align() {
	playersave.seekg(std::ios::end);
	if (playersave.fail() || !playersave.eof()) {
		return false;
	}
	return true;
}

inline void Save::checkAlign() {
	if (!align()) {
		cerr << "Alignment failed with call from getAnswers." << endl;
		cerr << "Current stream state: " << endl;
		cerr << "Current tellg: " << playersave.tellg() << endl;
		cerr << "Goodbit: " << playersave.goodbit << endl;
		cerr << "Badbit: " << playersave.badbit << endl;
		cerr << "Failbit: " << playersave.failbit << endl;
		cerr << "EOFbit: " << playersave.eofbit << endl;
		cerr << "Hard-crashing program..." << endl;
		abort(); //hard crash -- if save file can't be manipulated, something's gone wrong.
	}
}

vector<char> Save::getAnswers() {
	checkAlign();

	vector<char> rtrn;
	string tmp;
	while (getline(playersave, tmp)) {
		rtrn.push_back(tmp[0]);
	}

	return rtrn;
}

string Save::getName() {
	playersave.seekg(std::ios::beg);

	string tmp;
	getline(playersave, tmp);

	return tmp;
}

void Save::writeName(string name) {
	playersave.seekg(std::ios::beg);
	playersave << name << endl;
}

void Save::writeAns(char ans) {
	checkAlign();
	playersave << ans << endl;
}