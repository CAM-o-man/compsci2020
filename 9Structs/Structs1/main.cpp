#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

struct rocketStats {
	
	int capacity;

	int gross;

};

struct rocketType {

	string name;

	int year;

	string centre;

	struct rocketStats stats;
};

bool operator>(struct rocketType const& lhs, struct rocketType const& rhs) {
	return lhs.stats.gross > rhs.stats.gross;
}

bool operator<(struct rocketType& lhs, struct rocketType& rhs) {
	return lhs.stats.gross < rhs.stats.gross;
}

// shamelessly copied from https://stackoverflow.com/a/12468109/7327253
string random_string(uint length) {
	auto randchar = []() -> char {
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const uint max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	string str(length, 0);
	generate_n(str.begin(), length, randchar);
	return str;
}

void fillerFunc(struct rocketType& rkt, string name, int year, string centre, int cap, int gross) {
	rkt = { name, year, centre, { cap, gross } };
	return;
}

//sorts rockets by gross weight in ascending order
void sorterFunc(struct rocketType* rkt, uint size) {
	struct rocketType tmp;
	for (int i = 0; i < size - 1; i++) {
		if (rkt[i] > rkt[i + 1]) {
			tmp = rkt[i];
			rkt[i] = rkt[i + 1];
			rkt[i + 1] = tmp;
		}
	}
}

int main() {
	//declare struct var
	struct rocketType rocket;

	rocket.year = 1972;

	//declare a second rocket with more data

	struct rocketType rocket72 = { "rocket72", 1972, "Cape Canaveral", { 6400, 1800 } };

	cout << rocket72.centre << endl;

	//an array of 140 rockets

	struct rocketType NASAsInventory[140];

	for (struct rocketType &rkt : NASAsInventory) {
		rkt = { random_string(7), rand(), random_string(4), { rand(), rand() } };
	}

	cout << NASAsInventory[14].name << endl;

	sorterFunc(NASAsInventory, 140);

}