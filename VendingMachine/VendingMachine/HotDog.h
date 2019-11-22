#pragma once
#include "Food.h"
#include <string>
#include <vector>
class HotDog :
	public Food
{
protected:
	std::vector<std::string> condiments;

public:
	std::vector<std::string> getCondiments();

	void addCondiment(std::string);

	unsigned int getCondimentNumber();

	HotDog(std::vector<std::string>);

	HotDog();
};

