#pragma once

#ifndef SUPPORTER_H
#define SUPPORTER_H
#include <string>
#include <functional>
typedef unsigned int uint;

struct Supporter {
	std::string firstname;
	std::string lastname;
	std::string phone; //represented as string because separating digits of ints is hard
	double amount;
	//originally wanted a hash value -- apparently, however, Visual Studio disagreed with me, and assailed me with errors until I removed it.
};


#endif