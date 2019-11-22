#pragma once
#include "Food.h"
#include <string>
#ifndef BEVERAGE_H
#define BEVERAGE_H

class Beverage :
	public Food
{
public:
	float getPrice();
	
	std::string getName();

	void setPrice(float pr);

	Beverage();

};

#endif