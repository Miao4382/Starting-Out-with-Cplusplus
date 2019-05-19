// Programming Challenges 18: Energy Drink Consumption
#include <iostream>
using namespace std;

int main()
{
	double pool = 16500, ED_customer_rate = 0.15, ED_customer = pool*ED_customer_rate, CF_ED_customer_rate = 0.58,
		CF_ED_customer = CF_ED_customer_rate*ED_customer;

	cout << "The approximate number of customers in the survey who purchase one or more energy drinks per week: "
		<< ED_customer << endl << "The approximate number of customers in the survey who prefer cirtus-flavored energy drink: "
		<< CF_ED_customer << endl;
	return 0;
}