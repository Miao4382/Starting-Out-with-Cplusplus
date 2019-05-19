#include "Park_ticket.h"

//define static variable
const int Park_ticket::base_fine = 25;
const int Park_ticket::rate = 10;

/* Constructor */
//initialize with blank info. Park_ticket can only be modified by Police object
Park_ticket::Park_ticket()
{
	make = "N/A";
	model = "N/A";
	color = "N/A";
	plate = "N/A";
	purchased_time = 0;
	parked_time = 0;
	fine = 0.0;
	name = "N/A";
	badge = "N/A";
	written = false;
}

/* Operator */
// << (to display the content of the ticket)
std::ostream& operator<< (std::ostream& out, const Park_ticket& t)
{
	out << "Car info:\n";
	out << "Make: " << t.make << "\n"
	<< "Model: " << t.model << "\n"
	<< "Color: " << t.color << "\n"
	<< "Plate number: " << t.plate << "\n";
	
	out << "Park info: \n"
	<< "Purchased time: " << t.purchased_time << "\n"
	<< "Parked time: " << t.parked_time << "\n"
	<< "Fine: $ " << t.fine << "\n";
	
	out << "Police officer:\n"
	<< "Name: " << t.name << "\n"
	<< "Badge: " << t.badge << "\n\n";
	
	return out;
	
}