//5. Membership Fees Increase
#include<fstream>
#include<iostream>
#include<iomanip>
int main()
{
	double charge=2500;
	const double RATE = 1.04;

	std::ofstream cout;
	cout.open("D:\\5.txt");

	cout << "Year" << std::setw(15) << "Charge" << std::endl;
	cout << "--------------------\n";
	cout << std::setw(2) << "0" << std::setw(15) << charge << std::endl;

	for (int i = 1; i <= 6; i++)
	{
		charge *= RATE;
		cout << std::setw(2) << i << std::setw(15) << charge << std::endl;
	}

	cout << "--------------------\n";

	std::cout << "Writting complete.\n";
	cout.close();
	return 0;
}