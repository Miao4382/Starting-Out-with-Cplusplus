#include "Odometer.h"
#include "Fuel_gauge.h"
#include <iostream>

// define static member variable
int Odometer::fuel_economy = 24;
int Odometer::max_mileage = 999999;

/* Mutator */
// increase mileage by 1, if mileage > 999999, mileage -= 999999; Check fuel first before  do the increment. If gallon_mile >= 24 after increment, burn 1 gallon fuel
void Odometer::Increment(Fuel_gauge& f)
{
	if (f.fuel == 0)
	{
		std::cout << "No fuel! Please re-fill the car.\n";
		return;
	}
	
	mileage++;
	gallon_mile++;
	if (mileage > max_mileage)
		mileage = 0;
	
	if (gallon_mile == fuel_economy)
	{
		f.Burn(); //call Burn() function to burn 1 gallon fuel 
		gallon_mile = 0; //re-set gallon mile
	}
	
}