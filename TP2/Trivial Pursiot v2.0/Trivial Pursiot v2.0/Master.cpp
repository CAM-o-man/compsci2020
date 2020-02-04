#include "Master.h"

using namespace std;
typedef unsigned int uint;

Master::Master(string name) {
	this->file = name;
	this->readAll();
}

void Master::