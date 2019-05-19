#include "Fuel_gauge.h"
#include <iostream>

int Fuel_gauge::maximum_fuel = 15;

/* Mutator */
void Fuel_gauge::Fill(int gas) //fill up the gas tank, maximum = maximum_fuel
{
	if (gas + fuel > maximum_fuel)
	{
		std::cout << "The car's gas tank can only hold 15 gallon gas. Added to 15 gallon.\n";
		fuel = 15;
	}
	
	else 
		fuel += gas;
}

void Fuel_gauge::Burn() //burn 1 gallon fuel
{
	fuel--;
}