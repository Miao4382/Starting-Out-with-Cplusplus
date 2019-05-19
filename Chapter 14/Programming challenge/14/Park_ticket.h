#ifndef PARKTICKET_H
#define PARKTICKET_H
#include "Mystring.h"
#include <iostream>
#include "Police.h"

class Parked_car;
class Park_meter;


class Park_ticket
{
private:
	//car info 
	Mystring make;
	Mystring model;
	Mystring color;
	Mystring plate;
	//park info
	int purchased_time;
	int parked_time;
	double fine;
	//police info 
	Mystring name;
	Mystring badge;
	//fine rate 
	static const int base_fine; //$25 for the first hour
	static const int rate; //$10 for every hour
	
	/* Ticket written status */
	bool written;
		
public:
	/* Constructor */
	//initialize with blank info. Park_ticket can only be modified by Police object
	Park_ticket();
	
	/* Accessor */
	bool GetStatus() const
	{ return written; }
	
	/* Friend */
	//only police object can modify private member of ticket
	friend void Police::WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket);
	
	/* Operator */
	// << (to display the content of the ticket)
	friend std::ostream& operator<< (std::ostream& out, const Park_ticket& t);
	
};

#endif