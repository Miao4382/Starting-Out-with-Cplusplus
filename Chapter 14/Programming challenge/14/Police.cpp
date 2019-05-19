#include "Police.h"
#include "Parked_car.h"
#include "Park_meter.h"
#include "Park_ticket.h"

/* Constructor */
//initialize the police officer
Police::Police(Mystring n, Mystring b)
{
	name = n;
	badge = b;
}

/* Function */
bool Police::CheckCar(const Parked_car& car, const Park_meter& meter) //check park time and purchased time, if expired, return true
{
	if (car.parked_time > meter.purchased_time)
		return true;
	else 
		return false;
}

void Police::WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket) //write a ticket for an illegally parked car, can access private members of a ticket
{
	/* Check ticket content */
	if (ticket.written == true)
	{
		std::cout << "Ticket already written, please change a ticket and try again.\n";
		return;
	}
	
	ticket.written = true;
	
	/* Calculate fine */
	int exceed_time = car.parked_time - meter.purchased_time;
	
	if (exceed_time <= 60)
		ticket.fine = ticket.base_fine;
	else
	{
		ticket.fine += ticket.base_fine;
		int exceed_hour = exceed_time/60;
		if (exceed_time % 60 != 0)
			exceed_hour++;
		ticket.fine += exceed_hour * ticket.rate;
	}
	
	/* Write info onto the ticket */
	ticket.make = car.make;
	ticket.model = car.model;
	ticket.color = car.color;
	ticket.plate = car.plate;
	ticket.purchased_time = meter.purchased_time;
	ticket.parked_time = car.parked_time;
	ticket.name = name;
	ticket.badge = badge;
	
}










