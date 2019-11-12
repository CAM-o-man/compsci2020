#pragma once
#include <string>
#ifndef FOOD_H
#define FOOD_H
class Food
{
protected:
	float price;
	std::string name;

public:
	virtual float getPrice(void) = 0;

	virtual std::string getName(void) = 0;

	virtual void setPrice(float) = 0;
};

#endif
