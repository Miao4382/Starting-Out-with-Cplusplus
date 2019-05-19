#ifndef POLICE_H
#define POLICE_H
#include "Mystring.h"

class Parked_car;
class Park_meter;
class Park_ticket;

class Police
{
private:
	//police info 
	Mystring name;
	Mystring badge;
	
public:
	/* Constructor */
	//initialize the police officer
	Police(Mystring n, Mystring b);
	
	/* Function */
	bool CheckCar(const Parked_car& car, const Park_meter& meter); //check park time and purchased time, if expired, return true 
	
	void WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket); //write a ticket for an illegally parked car, can access private members of a ticket
};


#endif