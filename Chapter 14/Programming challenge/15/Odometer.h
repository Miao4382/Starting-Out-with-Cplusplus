#ifndef ODOMETER_H
#define ODOMETER_H

class Fuel_gauge;

class Odometer
{
private:
	int mileage;
	int gallon_mile; //hold the mileage of current fuel cycle, if it is >= fuel_economy, subtract fuel_economy and decrease fuel gauge by 1 (24 mile per gallon)
	
	static int fuel_economy; //24 mile per gallon
	static int max_mileage; //999999
	
public:
	/* Constructor */
	Odometer(int m = 10000)
	{
		mileage = m;
		gallon_mile = 0;
	}
	
	/* Accessor */
	int GetMileage() const 
	{ return mileage; }
	
	/* Mutator */
	// increase mileage by 1, if mileage > 999999, mileage -= 999999; Check fuel first before  do the increment. If gallon_mile >= 24 after increment, burn 1 gallon fuel
	void Increment(Fuel_gauge& f); 

	
};


#endif