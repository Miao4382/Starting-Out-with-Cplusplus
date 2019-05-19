#include <iostream>
void qualify()
{
	std::cout << "You're qualify. The annual rate is 12%.\n";
}

void no_qualify()
{
	std::cout << "You're not qualify. You have to earn more than 17000 per year and have a job for at lease two years to be qualify.\n";
}

int main()
{
	double income, year;
	std::cout << "Please input your annual income: ";
	std::cin >> income;
	std::cout << "Please input the years since you have your current job: ";
	std::cin >> year;

	if (income < 17000 || year < 2)
	{
		no_qualify();
	}

	else
		qualify();
	return 0;
}