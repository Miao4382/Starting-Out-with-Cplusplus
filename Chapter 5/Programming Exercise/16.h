//16. Savings Account Balance
#include <iostream>
#include <iomanip>
#include <fstream>
int main()
{
	//create file stream object
	std::ofstream cout;
	cout.open("D:\\16.txt");
	cout << std::setprecision(2) << std::fixed;

	//variable definition
	double annual_rate, balance, month, rate, deposit, withdrawn, interest;
	double deposit_total = 0, withdrawn_total = 0, interest_total=0;

	//input annual interest rate and check
	std::cout << "Please input the annual interest rate in percentage: ";
	std::cin >> annual_rate;
	while (annual_rate < 0)
	{
		std::cout << "Invalid input. Please input an annual interest rate greater than zero.\n";
		std::cin >> annual_rate;
	}
	rate = annual_rate / 12;

	//write head information into the txt file
	cout << "Savings Account Balance Calculation Program v1.00\n";
	cout << "****************************************************\n\n";
	cout << "Annual interest rate: " << annual_rate << "%\n";
	cout << "Monthly interest rate: " << rate << "%\n\n";
	cout << std::setw(10) << "Month" << std::setw(24) << "Starting Balance($)" << std::setw(15) << "Deposit($)" << std::setw(17) << "Withdrawn($)" << std::setw(16) << "Interest($)" << std::setw(22) << "Ending Balance($)\n";
	cout << "---------------------------------------------------------------------------------------------------------------\n";

	//input starting balance
	std::cout << "Please input the starting balance: ";
	std::cin >> balance;
	if (balance < 0)
	{
		std::cout << "The balance is negative value. The account has been suspended.\n";
		cout << std::setw(80) << "<The Account Has Been Suspended Due to Insufficient Balance>\n";
		cout.close();
	}
	else
	{
		//input the total month
		std::cout << "Please input the total number of months: ";
		std::cin >> month;
		while (month <= 0)
		{
			std::cout << "Invalid input. Should be at least one month.\n";
			std::cin >> month;
		}

		//use loop to input deposit, withdrawn data and do interest calculation
		std::cin.ignore();
		std::cout << "\nPress enter to begin inputing your deposit and withdrawn data for each month.\n";
		std::cin.get();
		for (int i = 1; i <= month; i++)
		{
			//write in txt file: month & starting balance
			cout << std::setw(8) << i;
			cout << std::setw(18) << balance;

			//input deposit 
			std::cout << "\nInput deposit in month " << i << ": ";
			std::cin >> deposit;
			//check validity
			while (deposit < 0)
			{
				std::cout << "Invalid deposit! Deposit cannot be negative number. Please input again.\n";
				std::cin >> deposit;
			}
			//write in txt file: deposit
			cout << std::setw(12) << "+" << std::setw(11) << deposit;

			//input withdrawn
			std::cout << "\nInput withdrawn in month " << i << ": ";
			std::cin >> withdrawn;
			//check validity
			while (withdrawn < 0)
			{
				std::cout << "Invalid withdrawn! Withdrawn cannot be negative number. Please input again.\n";
				std::cin >> withdrawn;
			}
			//write in txt file: withdrawn
			cout << std::setw(7) << "-" << std::setw(10) << withdrawn;
			
			//calculate balance. If balance < 0, stop the loop and write suspend information
			balance = balance + deposit - withdrawn;
			if (balance < 0)
			{
				std::cout << "Your account is suspended due to insufficient balance. Check the files for details.\n";
				cout << std::setw(12) << "N/A";
				cout << std::setw(25) << balance << std::endl;
				cout << std::setw(80) << "<The Account Has Been Suspended Due to Insufficient Balance>\n";
				break;
			}

			//calculate monthly interest. Update total deposit, total withdrawn, total interest
			interest = balance*rate / 100;
			balance += interest;
			deposit_total += deposit;
			withdrawn_total += withdrawn;
			interest_total += interest;
			//write interest and ending balance into txt file
			cout << std::setw(15) << interest;
			cout << std::setw(22) << balance << std::endl;

		}
		//write table tail
		cout << "---------------------------------------------------------------------------------------------------------------\n\n\n";

		//if balance >=0, print out the ending balance, total deposit, total withdrawn, total interest
		if (balance >= 0)
		{
			cout << std::setw(25) << "Summary Table\n";
			cout << "--------------------------------------------\n";
			cout << "Term" << std::setw(37) << "Amount ($)\n";
			cout << "--------------------------------------------\n";
			cout << "Ending Balance:" << std::setw(25) << balance << std::endl;
			cout << "Total Deposit:" << std::setw(26) << deposit_total << std::endl;
			cout << "Total Withdrawn:" << std::setw(24) << withdrawn_total << std::endl;
			cout << "Total Interest:" << std::setw(25) << interest_total << std::endl;
			cout << "--------------------------------------------\n";
			cout.close();
			std::cout << "The processing is complete, check the txt file for result.\n";
		}

	}

	return 0;


}