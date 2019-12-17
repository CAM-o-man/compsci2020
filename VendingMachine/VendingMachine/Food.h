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
	virtual float getPrice(void);

	virtual std::string getName(void);

	virtual void setPrice(float);
};

#endif
