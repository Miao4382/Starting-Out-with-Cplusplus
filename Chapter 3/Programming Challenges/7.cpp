//7. Box Office
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	const double adult_unit = 10, child_unit = 6, box_rate=0.2;
	string movie_name;
	double gross_profit, net_profit_box, net_profit_maker, adult_price, child_price;
	int adult_ticket, child_ticket;
	cout << "Please input the name of the film: ";
	getline(cin, movie_name);
	cout << "Please input the number of adult ticket sold: ";
	cin >> adult_ticket;
	cout << "Please input the number of children ticket sold: ";
	cin >> child_ticket;

	/*movie_name = "Wheels of Fury";
	adult_ticket = 382;
	child_ticket = 127;*/ //This part is used to help check the type setting

	adult_price = adult_unit*adult_ticket;
	child_price = child_unit*child_ticket;
	gross_profit = adult_price + child_price;
	net_profit_box = gross_profit*box_rate;
	net_profit_maker = gross_profit*(1 - box_rate);
	cout << "Sales information is as follows: \n\n";
	cout << left << setw(30) << "Movie Name:" << "\"" << movie_name << "\"\n";
	cout << left << setw(32) << "Adult Tickets Sold:" << setw(21) << adult_ticket << endl;
	cout << left << setw(32) << "Child Tickets Sold:" << setw(21) << child_ticket << endl;
	cout << setprecision(2) << fixed;
	cout << left << setw(30) << "Gross Box Office Profit:" << "$" << right << setw(8) << gross_profit << endl;
	cout << left << setw(30) << "Net Box Office Profit:" << "$" << right << setw(8) << net_profit_box << endl;
	cout << left << setw(30) << "Amount paid to Distributor:" << "$" << right << setw(8) << net_profit_maker << endl;
	return 0;

}