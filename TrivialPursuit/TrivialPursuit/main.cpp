#include "Master.h"
#include <iomanip>

using namespace std;

typedef string str;

template<typename T> void printElement(T t, uint width) {
	cout << left << setw(width) << setfill(' ') << t;
}


int main() {
	//Initiate new Master protocol

	Master master("master.csv"); //FILE NAME SHOULD ALWAYS BE IDENTICAL.

	//enter gameplay loop
	for (uint i = 0; i < master.getLines(); i++) {
		cout << "WELCOME TO TRIVIAL PURSUIT!" << endl;
		cout << "Answer 12 out of 15 questions correctly and YOU WIN!" << endl;
		cout << "First, however, please enter your name." << endl;
	}
}