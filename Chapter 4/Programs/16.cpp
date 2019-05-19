//Program 4-16: First time using || opeartor
#include <iostream>
using namespace std;
int main()
{
	//variable definition
	double earn, empoly_year;
	const double MINIMUM_EARN = 35000, MINIMUM_YEAR = 5;

	//input information
	cout << "What is your annual income?\n";
	cin >> earn;
	cout << "How many years you've been employed?\n";
	cin >> empoly_year;

	//conditions check
	if (earn >= MINIMUM_EARN || empoly_year >= MINIMUM_YEAR)
		cout << "You are qualified for the loan!\n";
	else
		cout << "You have to earn more than 35000 or be empolyed over\n"
		<< "five years to be able to accept the loan.\n";

	return 0;
}