//19. Hospital Report on file
#include <iostream>
#include<fstream>
#include<iomanip>

void show_menu_choice(char &choice);
void input(int &days, double &daily_rate, double &charge_medication, double &charge_service);
void input(double &charge_medication, double &charge_service);
double cost(int days, double daily_rate, double charge_medication, double charge_service);
double cost(double charge_medication, double charge_service);

int main()
{
	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\Overloaded Hospital Report.txt");
	cout << std::setprecision(2) << std::fixed;
	
	//define choice variable
	char choice;
	show_menu_choice(choice);

	//write down patient type in report
	cout << "Overloaded Hospital Report\n"
		<< "----------------------------\n\n"
		<< "Patient Type: ";
	if (choice == '1')
		cout << "In-patient\n";
	else
		cout << "Out-patient\n";

	//data input for different patient
	int days;
	double daily_rate, charge_medication, charge_service;
	switch (choice)
	{
	case '1':
		input(days, daily_rate, charge_medication, charge_service);
		//print additional information to file
		cout << "Number of days in hospital: " << days << std::endl
			<< "Daily charge: $" << daily_rate << std::endl
			<< "Medication charge: $" << charge_medication << std::endl
			<< "Service charge: $" << charge_service << std::endl;
		//print total charges
		cout << "Total charges: $" << cost(days, daily_rate, charge_medication, charge_service) << std::endl;
		break;
	case '2':
		input(charge_medication, charge_service);
		//print additional information to file
		cout << "Medication charge: $" << charge_medication << std::endl
			<< "Service charge: $" << charge_service << std::endl;
		cout << "Total charges: $" << cost(charge_medication, charge_service) << std::endl;
		break;
	}

	std::cout << "Process complete. Please check report.\n";
	cout.close();

	return 0;	

}

//show menue and pick up choice function
void show_menu_choice(char &choice)
{
	std::cout << "Please select one term below:\n";
	std::cout << "1. In patient\n2. Out patient\n";
	std::cin >> choice;
	while (choice != '1'&&choice != '2')
	{
		std::cout << "Invalid choice. Please choose 1 or 2:\n";
		std::cin >> choice;
	}
}

//input function: in-patient
void input(int &days, double &daily_rate, double &charge_medication, double &charge_service)
{
	std::cout << "How many days in hospital: ";
	std::cin >> days;
	while (days < 0)
	{
		std::cout << "Please input days greater than zero: ";
		std::cin >> days;
	}

	std::cout << "What is the daily rate: ";
	std::cin >> daily_rate;
	while (daily_rate < 0)
	{
		std::cout << "Please input daily rate greater than zero: ";
		std::cin >> daily_rate;
	}

	std::cout << "What is the hospital medication charges: ";
	std::cin >> charge_medication;
	while (charge_medication < 0)
	{
		std::cout << "Please input a medication charge greater than zero: ";
		std::cin >> charge_medication;
	}

	std::cout << "What is the service charge: ";
	std::cin >> charge_service;
	while (charge_service < 0)
	{
		std::cout << "Please input a service charge greater than zero: ";
		std::cin >> charge_service;
	}
}

//input function: out patient
void input(double &charge_medication, double &charge_service)
{
	std::cout << "What is the hospital medication charges: ";
	std::cin >> charge_medication;
	while (charge_medication < 0)
	{
		std::cout << "Please input a medication charge greater than zero: ";
		std::cin >> charge_medication;
	}

	std::cout << "What is the service charge: ";
	std::cin >> charge_service;
	while (charge_service < 0)
	{
		std::cout << "Please input a service charge greater than zero: ";
		std::cin >> charge_service;
	}
}

//cost function: in and out
double cost(int days, double daily_rate, double charge_medication, double charge_service)
{
	return daily_rate*days + charge_medication + charge_service;
}
double cost(double charge_medication, double charge_service)
{
	return charge_medication + charge_service;
}