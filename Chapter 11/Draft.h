#include <iostream>

struct Hourly_paid
{
	int hour;
	double rate;
};

struct Salaried
{
	double salary;
	double bonus;
};

union Worker
{
	Hourly_paid hour_w;
	Salaried sal_w;
};

int main()
{
	char choice;
	Worker pay; //create a union type variable, which is either hourly paid or salaried worker
	//ask the user to select a type
	std::cout << "What is the work type: \n"
	<< "1) Hourly paid worker;\n2) Salaried worker\n";
	
	std::cin >> choice;
	while (choice != '1' && choice != '2')
	{
		std::cout << "Invalid input, please input 1 or 2: ";
		std::cin >> choice;
	}
	
	switch (choice)
	{
	case '1':
		std::cout << "How many hours you worked: ";
		std::cin >> pay.hour_w.hour;
		while (pay.hour_w.hour <=0 || pay.hour_w.hour > 80)
		{
			std::cout << "Invalid input, please input again: ";
			std::cin >> pay.hour_w.hour;
		}
		std::cout << "What is your pay rate: ";
		std::cin >> pay.hour_w.rate;
		while (pay.hour_w.rate <= 0)
		{
			std::cout << "Invalid rate, please input rate that is greater than 0: ";
			std::cin >> pay.hour_w.hour;
		}
		std::cout << "Your salary is: $" << pay.hour_w.hour * pay.hour_w.rate << "\n";
		
	case '2':
		std::cout << "What is your basic salary: ";
		std::cin >> pay.sal_w.salary;
		while (pay.sal_w.salary <= 0)
		{
			std::cout << "Please input salary that is greater than zero: ";
			std::cin >> pay.sal_w.salary;
		}
		std::cout << "Please input your bonus: ";
		std::cin >> pay.sal_w.bonus;
		while (pay.sal_w.bonus <= 0)
		{
			std::cout << "Please input bonus greater than zero: ";
			std::cin >> pay.sal_w.bonus;
		}
		std::cout << "Your salary is: $" << pay.sal_w.salary + pay.sal_w.bonus << "\n";
	}
	
	return 0;
}