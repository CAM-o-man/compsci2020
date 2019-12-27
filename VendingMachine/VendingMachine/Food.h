#pragma once
#include <string>
#ifndef FOOD_H
#define FOOD_H
class Food
{

public:

	std::string name;

	float price;

	virtual const float getPrice(void);

	virtual std::string getName(void);

	virtual void setPrice(float);
};

#endif
