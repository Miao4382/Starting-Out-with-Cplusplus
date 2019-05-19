#ifndef PARKEDCAR_H
#define PARKEDCAR_H
#include "Mystring.h"
#include "Police.h"

class Park_meter;
class Park_ticket;

class Parked_car
{
private:
	Mystring make;
	Mystring model;
	Mystring color;
	Mystring plate;
	int parked_time; //number of minute that the car has been parked
public:
	/* Constructor */
	//initialize the car
	Parked_car(Mystring ma, Mystring mo, Mystring co, Mystring pl, int t);
	
	/* Friend */
	friend bool Police::CheckCar(const Parked_car& car, const Park_meter& meter);
	friend void Police::WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket);
};


#endif