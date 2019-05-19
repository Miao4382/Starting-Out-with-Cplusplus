//15. Overloaded Hospital
#include <iostream>

double total_charge(double charge_service, double charge_medication);
double total_charge(double charge_service, double charge_medication, double charge_daily, int days);
void get_info_in(double &charge_service, double &charge_medication, double &charge_daily, int &days);
void get_info_out(double &charge_service, double &charge_medication);


int main()
{
	char choice;
	std::cout << "Choose a type below:\n";
	std::cout << "1. In-patient;\n2. Out-patient;\n";
	std::cin >> choice;
	while (choice != '1'&&choice != '2')
	{
		std::cout << "Invalid input, please input 1 or 2:\n";
		std::cin >> choice;
	}
	//to hold total charges
	double total;

	//input and calculation
	if (choice == '1')
	{
		double charge_service, charge_medication, charge_daily;
		int days;
		get_info_in(charge_service, charge_medication, charge_daily, days);
		total=total_charge(charge_service, charge_medication, charge_daily, days);
	}
	else
	{
		double charge_service, charge_medication;
		get_info_out(charge_service, charge_medication);
		total = total_charge(charge_service, charge_medication);
	}

	//display result
	std::cout << "The total charge is $" << total << std::endl;

	return 0;
}

//get in-patient info
void get_info_in(double &charge_service, double &charge_medication, double &charge_daily, int &days)
{
	std::cout << "Please input the charges for the hospital services, charges for hospital medication, daily rate and number of days respectively:\n";
	std::cin >> charge_service >> charge_medication >> charge_daily >> days;
	while (charge_daily < 0 || charge_medication < 0 || charge_service < 0||days<0)
	{
		std::cout << "Invalid input. Charges can not be negative value. Please input again:\n";
		std::cin >> charge_service >> charge_medication >> charge_daily >> days;
	}
}

//get out-patient info
void get_info_out(double &charge_service, double &charge_medication)
{
	std::cout << "Please input the charges for the hospital services, charges for hospital medication:\n";
	std::cin >> charge_service >> charge_medication;
	while (charge_medication < 0 || charge_service < 0)
	{
		std::cout << "Invalid input. Charges can not be negative value. Please input again:\n";
		std::cin >> charge_service >> charge_medication;
	}
}

//total charge for in patient
double total_charge(double charge_service, double charge_medication, double charge_daily, int days)
{
	return charge_daily + charge_medication + charge_daily*days;
}

//total charge for out patient
double total_charge(double charge_service, double charge_medication)
{
	return charge_medication + charge_service;
}