#include "Parked_car.h"
/* Constructor */
//initialize the car
Parked_car::Parked_car(Mystring ma, Mystring mo, Mystring co, Mystring pl, int t)
{
	make = ma;
	model = mo;
	color = co;
	plate = pl;
	parked_time = t;
}