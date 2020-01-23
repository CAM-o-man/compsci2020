#include "Save.h"
#include <string>
using namespace std;



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