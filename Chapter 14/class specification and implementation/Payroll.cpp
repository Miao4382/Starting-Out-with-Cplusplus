#include "Payroll.h"
#include <cstdlib>
#include <iostream>

/* Mutator */
void Payroll::set_hour(int hour_input) //set work hour and calculate total pay, store to total_pay
{
	if (hour_input < 0)
	{
		std::cout << "Invalid input, program quitting...\n";
		exit(EXIT_FAILURE);
	}
	
	hour = hour_input;
	total_pay = hour * pay_rate;
}

/* Accessor */
double Payroll::get_total_pay() const
{
	return total_pay;
}
