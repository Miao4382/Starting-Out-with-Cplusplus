#include <iostream>
#include "Patient_account.h"
#include "Surgery.h"
#include "Pharmacy.h"

void charge_input(Patient_account &p); //used to input charge 
void display_menu(char &choice); //display input menu

int main()
{
	/* Define account object */
	int num_stay;
	std::cout << "How many days stayed: ";
	std::cin >> num_stay;
	Patient_account p1(num_stay);

	/* Call charge_input() function to input surgery and medication charge */
	charge_input(p1);

	/* Call Patient_account's member function display_charge() to display charge */
	std::cout << "\nYour input is complete, press enter to view the patient's bill.\n";
	std::cin.get();
	p1.display_charge();

	return 0;

}

void charge_input(Patient_account &p) //used to input charge 
{
	char choice; //hold user's choice 
	bool surgery_inputed = false; //to indicate whether the surgery cost is recorded
	bool pharmacy_inputed = false; //to indicate whether the pharmacy cost is recorded 
	Surgery s;
	Pharmacy m;

	do
	{
		display_menu(choice);

		switch (choice)
		{
		case '1':
			//Surgery s;
			s.display_surgery_cost();
			s.choose_surgery(p);
			surgery_inputed = true;
			break;
		case '2':
			//Pharmacy m;
			m.display_medication_cost();
			m.choose_medication(p);
			pharmacy_inputed = true;
			break;
		}
	} while (!(surgery_inputed && pharmacy_inputed));


}
void display_menu(char &choice) //display input menu
{
	std::cout << "Please select one term below to input charge info. Program will continue after surgery and pharmacy charges are both inputed.\n"
		<< "1) input surgery charge;\n"
		<< "2) input pharmacy charge;\n";
	std::cin >> choice;
	while (choice != '1' && choice != '2')
	{
		std::cout << "Invalid input, please choose 1 or 2: ";
		std::cin >> choice;
	}
	std::cin.ignore();
}