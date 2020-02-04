#include "Master.h"
#include <iomanip>
#include "Save.h"

using namespace std;

typedef string str;

template<typename T> void printElement(T t, uint width) {
	cout << left << setw(width) << setfill(' ') << t;
}


int main() {
	//Initiate new Master interface
	ofstream tmp;
	tmp.open("master.csv");
	tmp << "4|In what order were the Star Wars movies released?|a:123456789|b:123789456|c:456123789|d:456123|c";
	tmp.close();
	ifstream master_file_reference;
	master_file_reference.open("master.csv");
	Master master(master_file_reference); // despite not using & here anywhere, this works.
										  // Prepare for inevitable segfaults!

	fstream save_file_reference;
	save_file_reference.open("usr.sav");
	Save save(save_file_reference); //again, probable inevitable segfaults

	string name;
	cout << "WELCOME TO TRIVIAL PURSUIT!" << endl;
	cout << "Please enter your name: " << endl;
	getline(cin, name);
	save.writeName(name);
	cout << "Excellent. Let's begin." << endl;
	
	//enter gameplay loop
	for (uint i = 0; i < master.getLines(); i++) {
		char usr;
		cout << "Question " << i + 1 << endl;
		cout << master.getQuestion(i) << endl;
		cout << "Your answer? Type the character of the answer." << endl;
		cin >> usr;
		if (!cin) {
			cout << "That's not a valid answer. Please try again." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			--i;
			continue; //very nice way to reset the loop
		}
		save.writeAns(usr); //record answer
		cout << "Answer recorded. Next!" << endl;
	}
}