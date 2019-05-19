#ifndef FUELGAUGE_H
#define FUELGAUGE_H
#include "Odometer.h"

class Fuel_gauge
{
private:
	int fuel;
	static int maximum_fuel; //define = 15
public:
	/* Constructor */
	Fuel_gauge() //initialize with 15 gallon
	{ fuel = maximum_fuel; }
	
	/* Accessor */
	int GetFuel() const
	{ return fuel; }
	
	/* Mutator */
	void Fill(int gas = 1); //fill the gas tank, maximum = maximum_fuel
	void Burn(); //burn 1 gallon fuel
	
	/* Friend */
	friend void Odometer::Increment(Fuel_gauge& fuel); 
};

#endif