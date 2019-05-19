//17. Sales Bar Chart
#include <iostream>
#include <fstream>
int main()
{
	double sales;
	int num_asterisk;

	std::ofstream cout;
	cout.open("D:\\17.txt");

	cout << "SALES BAR CHART\n" << "(Each * = $100)\n";

	for (int i = 1; i <= 5; i++)
	{
		std::cout << "Enter today's sales for store " << i << std::endl;
		std::cin >> sales;

		num_asterisk = sales / 100;
		cout << "Store " << i << ": ";

		for (int j = 1; j <= num_asterisk; j++)
		{
			cout << "*";
		}
		cout << std::endl;
	}
	cout.close();

	return 0;
}