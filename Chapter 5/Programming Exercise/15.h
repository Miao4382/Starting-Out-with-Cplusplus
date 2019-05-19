//15. Payroll Report
#include <iostream>
#include <iomanip>
#include <fstream>
int main()
{
	//variable definition
	double pay_gross, tax_state, tax_federal, FICA, pay_net;
	double state_tax_rate=100, federal_tax_rate=100, FICA_rate=100;
	int ID=1;

	//create file stream object and define proper format
	std::ofstream cout;
	cout.open("D:\\15.txt");
	cout << std::setprecision(2) << std::fixed;

	//input tax rate and check
	while (state_tax_rate + federal_tax_rate + FICA_rate > 100)
	{
		std::cout << "Please input the state tax rate (in percentage): ";
		std::cin >> state_tax_rate;
		while (state_tax_rate < 0)
		{
			std::cout << "The tax rate should be greater than zero, please input again: ";
			std::cin >> state_tax_rate;
		}

		std::cout << "Please input the federal tax rate (in percentage): ";
		std::cin >> federal_tax_rate;
		while (federal_tax_rate < 0)
		{
			std::cout << "The tax rate should be greater than zero, please input again: ";
			std::cin >> federal_tax_rate;
		}

		std::cout << "Please input the FICA tax rate (in percentage): ";
		std::cin >> FICA_rate;
		while (FICA_rate < 0)
		{
			std::cout << "The FICA tax rate should be greater than zero, please input again: ";
			std::cin >> FICA_rate;
		}

		if (state_tax_rate + federal_tax_rate + FICA_rate > 100)
			std::cout << "The tax can't be higher than the employee's pay, please reinput tax rate data:\n\n";
	}
	


	//print table header
	cout << "Pay check system v1.00\n\n" << "Tax information:\n" << "State tax rate: " << state_tax_rate << "%\n";
	cout << "Federal tax rate: " << federal_tax_rate << "%\n";
	cout << "FICA tax rate: " << FICA_rate << "%\n\n";
	cout << "Pay information table is as follows:\n\n";
	cout << std::setw(17) << "Employee ID" << std::setw(19) << "Gross Pay($)" << std::setw(18) << "State Tax($)" << std::setw(20) << "Federal Tax($)" << "      FICA with-holding($)" << "          Net Pay($)\n";
	cout << "--------------------------------------------------------------------------------------------------------------------------------\n";

	//use a loop to get and print the information. Employee ID = 0 is the stop sentinel
	while (ID != 0)
	{

		//input ID
		std::cout << "\nInput the employee ID: ";
		std::cin >> ID;
		if (ID == 0)
			break;
		while (ID < 0)
		{
			std::cout << "Employee ID should be greater than zero, input again: ";
			std::cin >> ID;
		}

		//input Gross Pay
		std::cout << "Input the gross pay: ";
		std::cin >> pay_gross;
		while (pay_gross < 0)
		{
			std::cout << "Gross pay should be greater than zero, input again: ";
			std::cin >> pay_gross;
		}

		//calculate taxes and net pay
		tax_state = pay_gross*state_tax_rate / 100;
		tax_federal = pay_gross*federal_tax_rate / 100;
		FICA = pay_gross*FICA_rate / 100;
		pay_net = pay_gross - tax_state - tax_federal - FICA;

		//write into the txt file
		cout << std::setw(7) << " ";
		cout.fill('0');
		cout << std::setw(10) << ID;
		cout.fill(' ');
		cout << std::setw(19) << pay_gross << std::setw(16) << tax_state << std::setw(21) << tax_federal << std::setw(20) << FICA << std::setw(27) << pay_net << std::endl;

		//inform the data input is complete, press enter to input next employee's data
		std::cout << "\nInput complete, data successfully saved. Press enter to begin inputting next employee's data, enter ID=0 to exit the program.\n";
		std::cin.ignore();
		std::cin.get();
	}

	//after the program, print the table tail
	cout << "--------------------------------------------------------------------------------------------------------------------------------\n";

	//print quit
	std::cout << "You have quited the program. Please check the txt file for record.\n";

	cout.close();
	return 0;
}