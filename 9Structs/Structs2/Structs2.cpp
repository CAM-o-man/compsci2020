#include <string>
#include <iostream>

using namespace std;
typedef unsigned int uint;

struct Zebra {

	string name;
	int age;
	string zoo;
	double height;
	double weight; //in kg
	string vet;

};

struct Zebra getZebra(string name, int age, string zoo, double height, double weight, string vet) {
	struct Zebra ret = { name, age, zoo, height, weight, vet };
	return ret;
}

ostream& operator<<(ostream& out, struct Zebra& in) {
	out << in.name;
	out << " at " << in.zoo;
	out << ": weight: " << in.weight;
	out << " kg, height: " << in.height;
	out << " m, age: " << in.age;
	out << ", keeper: " << in.vet;
	return out;
}

int main() {
	//declare 3 zebras
	struct Zebra zebras[3];
	
	zebras[0] = getZebra("Thomas", 7, "The 0xFF Zoo", 2.8, 130, "Dylan");
	zebras[1] = getZebra("Adam", 14, "The 0xFF Zoo", 3.5, 200, "Charles");
	zebras[2] = getZebra("Jeff", 12, "The 0xFF Zoo", 3.3, 190, "Sylvester");

	cout << zebras[0] << endl;
	cout << zebras[1] << endl;
	cout << zebras[2] << endl;
}