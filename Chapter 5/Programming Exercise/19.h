//19. Budget Analysis Program
#include<iostream>
#include<fstream>
int main()
{
	double budget, expense=0, expense_total=0;
	
	//open file stream pbject
	std::ofstream cout;
	cout.open("D:\\19.txt");
	
	//input budget
	std::cout << "What is your budget for this month: ";
	std::cin >> budget;
	
	//print out title and budget
	cout << "Budget Analysis Program v1.00\n";
	cout << "-----------------------------------\n";
	cout << "Budget: $" << budget << std::endl;
	cout << "Expense:\n";

	//use a while loop to input budget, use -1 as the stop sentinel
	std::cout << "Please input your expense. Input -1 to end your input and create a report.\n";
	while (expense != -1)
	{
		std::cin >> expense;
		if (expense == -1)
			break;
		while (expense < 0)
		{
			std::cout << "Input expense that is greater than zero.\n";
			std::cin >> expense;
		}
		expense_total += expense;
		cout << "$ " << expense << std::endl;
	}
	cout << "-----------------------------------\n";
	if (budget == expense)
	{
		cout << "Your budget is equal to your expense.\n";
	}
	else if (budget > expense)
		cout << "Your budget is higher than your expense.\n";
	else
		cout << "Your budget is lower than your expense.\n";

	std::cout << "Data processing complete, please refer to the txt file for result.\n";
	cout.close();

	return 0;
}