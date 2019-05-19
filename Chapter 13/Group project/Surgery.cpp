#include <iostream>
#include "Surgery.h"
#include "Patient_account.h"

/* Constructor */
Surgery::Surgery() //to initialize the cost for each surgery 
{
	s1 = 100.0;
	s2 = 200.0;
	s3 = 300.0;
	s4 = 400.0;
	s5 = 500.0;
}

/* Accessor */
void Surgery::display_surgery_cost() const //display cost for each surgery, called in choosing surgery menu
{
	std::cout << "Surgery type and cost:\n"
		<< "Type_1: $" << s1 << "\n"
		<< "Type_2: $" << s2 << "\n"
		<< "Type_3: $" << s3 << "\n"
		<< "Type_4: $" << s4 << "\n"
		<< "Type_5: $" << s5 << "\n"
		<< "\n";
}

/* Method */
void Surgery::choose_surgery(Patient_account &p) //ask user to input choice of surgery, then call add_to_total_charge() to add corresponding charge to patient account
{
	char choice;
	std::cout << "Input the surgery type: ";
	std::cin >> choice;
	std::cin.ignore();

	switch (choice)
	{
	case '1': p.add_to_total_charge(s1); p.set_surgery_charge(s1); break;
	case '2': p.add_to_total_charge(s2); p.set_surgery_charge(s2); break;
	case '3': p.add_to_total_charge(s3); p.set_surgery_charge(s3); break;
	case '4': p.add_to_total_charge(s4); p.set_surgery_charge(s4); break;
	case '5': p.add_to_total_charge(s5); p.set_surgery_charge(s5); break;
	}

	std::cout << "Surgery cost has been recorded, press enter to continue.\n";
	std::cin.get();
}
