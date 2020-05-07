#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
typedef unsigned int uint;

struct Program {

	string name;
	int channel;
	struct Location {

		double lat;
		double lon;

	} loc;
	string host;
};

int main() {
	struct Program shows[3];

	for (int i = 0; i < 3; i++) {
		cout << "Please enter the name of show #" << i + 1 << endl;
		string name;
		getline(cin, name); //getline should consume its own trailing whitespace
		cout << "On what channel will it be broadcast?" << endl;
		int chan;
		cin >> chan;
		if (!cin) {
			cout << "It appears your input is invalid. Let's try that again, shall we?" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			i--;
			continue; //resets to top of loop
		}
		cout << "Now, where does this take place? Latitude first, please." << endl;
		double lat;
		cin >> lat;
		if (!cin) {
			cout << "It appears your input is invalid. Let's try that again, shall we?" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			i--;
			continue; //resets to top of loop
		}
		cout << "Now, longitude." << endl;
		double lon;
		cin >> lon;
		if (!cin) {
			cout << "It appears your input is invalid. Let's try that again, shall we?" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			i--;
			continue; //resets to top of loop
		}
		cout << "Finally, what's the name of your host?" << endl;
		string hostname;
		cin.ignore(INT_MAX, '\n'); //making sure getline doesn't eat cin's trailing whitespace
		getline(cin, hostname);

		shows[i] = { name, chan, { lat, lon }, hostname };
	}

	//print in some organised manner
	for (int i = 0; i < 3; i++) {
		cout << "Show #" << i + 1 << ":" << endl;
		cout << '\t' << left << "Name: " << right << shows[i].name << endl;
		cout << '\t' << left << "Channel No: " << right << shows[i].channel << endl;
		cout << '\t' << left << "Location: " << right << shows[i].loc.lat << " degrees North, " << shows[i].loc.lon << " degrees West." << endl;
		cout << '\t' << left << "Hosted by: " << right << shows[i].host << endl;

	}
}