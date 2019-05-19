#include <iostream>
#include "car.h"
#include "truck.h"
#include "suv.h"

int main()
{
	Car car1("Honda", "2010 Accord", 55555, 10500, 4);
	Truck truck1("Toyota", "2012 Cruser", 100500, 7000.5, "FWD");
	Suv suv1("Audio", "2015 Q5", 50000, 15590, 4);

	return 0;
}