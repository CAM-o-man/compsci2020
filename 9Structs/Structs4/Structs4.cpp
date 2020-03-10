#include <iostream>

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

ostream& operator<<(ostream& out, struct Program& in) {
	out << in.name;
	return out;
}