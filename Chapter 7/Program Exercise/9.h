//9. Payroll
#include<iostream>
#include<iomanip>

//void get_data(long empID[], int hours[], double pay_rate[], double wages[]);

int main()
{
	//define
	long empID[7] = { 5658845,4520125,7895122,8777541,8451277,1302850,7580489 };
	int hours[7];
	double pay_rate[7], wages[7];

	//input data
	for (int i = 0; i < 7; i++)
	{
		std::cout << "Please input working hours for employee " << empID[i] << ": ";
		std::cin >> hours[i];
		while (hours[i] < 0)
		{
			std::cout << "Please input hours greater than zero: ";
			std::cin >> hours[i];
		}
		std::cout << "Please input payrate for employee " << empID[i] << ": ";
		std::cin >> pay_rate[i];
		while (pay_rate[i] < 15)
		{
			std::cout << "Please input pay rate greater than $15: ";
			std::cin >> pay_rate[i];
		}
		wages[i] = hours[i] * pay_rate[i];
	}

	//print out result
	std::cout << "\n\nGross wage information is as follows:\n\n";
	std::cout << "empID            Wages($)\n";
	std::cout << "------------------------\n";
	for (int i = 0; i < 7; i++)
	{
		std::cout << empID[i] << std::setw(16) << wages[i] << std::endl;
	}
	std::cout << "------------------------\n\n";

}