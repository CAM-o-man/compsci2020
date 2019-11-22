#pragma once
#include "Food.h"
#include <vector>
class Pizza :
	public Food
{
protected:
	std::vector<std::string> condiments;

public:
	std::vector<std::string> getCondiments();

	unsigned int getCondimentNumber();

	void addCondiment(std::string);

	Pizza(std::vector<std::string>);

	Pizza();
};

