//24. long-Distance Calls
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//variable definition
	double start_time, call_time;

	//input
	cout << "Please input your start time of call in the form of HH.MM:	";
	cin >> start_time;
	cout << "Please input your call time in minutes: ";
	cin >> call_time;

	//range check
	if (start_time > 23.59 || (start_time - static_cast<int>(start_time) > 0.59)||start_time<0||(static_cast<int>(start_time*100)!=start_time*100))
	{
		cout << "Your input has following error:\n";
		if (start_time > 23.59)
			cout << "Start time should not exceed 23:59.\n";
		if ((start_time - static_cast<int>(start_time) > 0.59))
			cout << "Number of minitues in your start time should not exceed 59.\n";
		if (start_time < 0)
			cout << "Start time cannot be negative numbers.\n";
		if ((static_cast<int>(start_time * 100) != start_time * 100))
			cout << "Only two digits for minutes in start time is allowed.\n";
	}

	//range check complete, begin assigne rate
	else 
	{
		double rate;
		if (start_time >= 0 && start_time <= 6.59)
			rate = 0.05;
		else if (start_time >= 7 && start_time <= 19)
			rate = 0.45;
		else
			rate = 0.2;

		//calculate charge
		double charge;
		charge = rate*call_time;
		cout << "The charge will be: $" << setprecision(2) << fixed << charge << endl;

	}
	return 0;


}