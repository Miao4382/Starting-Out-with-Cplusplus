#include <iostream>
#include "Patient_account.h"
#include "Pharmacy.h"

/* Constructor */
Pharmacy::Pharmacy() //to initialize cost of each medication
{
	m1 = 10.0;
	m2 = 20.0;
	m3 = 30.0;
	m4 = 40.0;
	m5 = 50.0;
}

/* Accessor */
void Pharmacy::display_medication_cost() const //to display cost for each medication 
{
	std::cout << "Pharmacy type and cost:\n"
		<< "Type_1: $" << m1 << "\n"
		<< "Type_2: $" << m2 << "\n"
		<< "Type_3: $" << m3 << "\n"
		<< "Type_4: $" << m4 << "\n"
		<< "Type_5: $" << m5 << "\n"
		<< "\n";
}

/* Method */
void Pharmacy::choose_medication(Patient_account &p) const //ask user to input choice of medication, then call add_to_total_charge() to add corresponding charge to patient account
{
	char choice;
	std::cout << "Input the medication type: ";
	std::cin >> choice;
	std::cin.ignore();

	switch (choice)
	{
	case '1': p.add_to_total_charge(m1); p.set_medication_charge(m1); break;
	case '2': p.add_to_total_charge(m2); p.set_medication_charge(m2); break;
	case '3': p.add_to_total_charge(m3); p.set_medication_charge(m3); break;
	case '4': p.add_to_total_charge(m4); p.set_medication_charge(m4); break;
	case '5': p.add_to_total_charge(m5); p.set_medication_charge(m5); break;
	}

	std::cout << "Pharmacy cost has been recorded, press enter to continue.\n";
	std::cin.get();
}

