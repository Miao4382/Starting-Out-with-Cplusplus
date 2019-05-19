//10. Health Program: menue driven program
#include <iostream>
void show_fee(double, int);
void show_menu();
int main()
{
	int choice=1;
	char choice2;
	int month;
	const double ADULT_RATE = 40, SENIOR_RATE = 30, CHILD_RATE = 20;

	//to print out the welcome page
	std::cout << "***********************\n";
	std::cout << "***********************\n";
	std::cout << "***Health Club Plan***\n";
	std::cout << "***********************\n";
	std::cout << "***********************\n\n";
	std::cout << "Welcome to the Health Club Plan Purchasing Program (v1.00)\n";
	std::cout << "--------------------------------------------------------------\n\n";
	
	//show the menue and do the calculation
	do
	{
		show_menu();
		std::cin >> choice;

		//input validity check and quit check
		if (choice == 4)
			break;
		while (choice != 1 && choice != 2 && choice != 3)
		{
			std::cout << "Input invalid, please re-input: \n";
			std::cin >> choice;
		}

		//use switch to call different function
		std::cout << "What is the month of your purchase?\n";
		std::cin >> month;
		switch (choice)
		{
		case 1: 		
			show_fee(ADULT_RATE,month);
			break;
		case 2: 
			show_fee(SENIOR_RATE, month);
			break;
		case 3:
			show_fee(CHILD_RATE, month);
			break;
		}

		//ask if the user want to do another check
		std::cout << "Would you want to check other rate? (Y/N)\n";
		std::cin >> choice2;
		while (choice2 != 'Y'&&choice2 != 'y'&&choice2 != 'N'&&choice2 != 'n')
		{
			std::cout << "Invalid input, please input Y or N.\n";
			std::cin >> choice2;
		}
		if (choice2 == 'Y' || choice2 == 'y')
			continue;
		else
			break;

	} while (choice != 4);

	if (choice == 4 || choice2 == 'N' || choice2 == 'n')
		std::cout << "You quited.\n";

	return 0;

}

//define different functions
void show_fee(double rate, int month)
{
	double charge;
	charge = rate*month;
	std::cout << "The rate of the plan is: " << charge << std::endl;
}

void show_menu()
{
	std::cout << "\nPlease choose the following number to check purchase information:\n";
	std::cout << "1. Adult plan\n";
	std::cout << "2. Senior Plan\n";
	std::cout << "3. Child Plan\n";
	std::cout << "4. Quit\n\n";
}