#include "Patient_account.h"
#include <iomanip>
#include <iostream>

/* Constructor */
Patient_account::Patient_account(int stay) //set corresponding daily_rate and num_stay, then calculate the base fee and store into total_charge 
{
	daily_rate = 125.0;
	num_stay = stay;
	surgery_charge = 0.0;
	medication_charge = 0.0;
	total_charge = daily_rate * num_stay;
}

/* Mutator */
void Patient_account::add_to_total_charge(double cost) //add cost to total_charge, called by member function in Surgery and Pharmacy to add surgery or pharmacy fee to the total charge
{
	total_charge += cost;
}

void Patient_account::set_surgery_charge(double cost)
{
	surgery_charge += cost;
}

void Patient_account::set_medication_charge(double cost)
{
	medication_charge += cost;
}

/* Accessor */
void Patient_account::display_charge() const //display details of the bill 
{
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Patient bill:\n"
		<< "Daily rate: $" << daily_rate << "\n"
		<< "Days stayed: " << num_stay << "\n"
		<< "Surgery charge: $" << surgery_charge << "\n"
		<< "Medication charge: $" << medication_charge << "\n"
		<< "Total: $" << total_charge << "\n";
}