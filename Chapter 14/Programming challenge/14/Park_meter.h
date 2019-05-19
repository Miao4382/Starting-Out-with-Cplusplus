#ifndef PARKMETER_H
#define PARKMETER_H
#include "Police.h"

class Parked_car;
class Park_ticket;

class Park_meter
{
private:
	int purchased_time;
public:
	/* Constructor */
	Park_meter(int t);

	/* Friend */
	friend bool Police::CheckCar(const Parked_car& car, const Park_meter& meter); //grant access to this function
	friend void Police::WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket);
};


#endif