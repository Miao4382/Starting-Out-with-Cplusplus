//Program 5-26: DVD Rental
#include<iostream>
int main()
{
	//variable definition
	int num, count=1;
	double total=0;
	char choice;

	//define constant rate
	const double CURRENT_RATE = 3.5, OTHER_RATE = 2.5;

	//input
	std::cout << "How many DVDs are being rented? ";
	std::cin >> num;

	//calculate
	for (; count <= num; count++)
	{
		//check if it is the third DVD
		if (count % 3 == 0)
		{
			std::cout << "DVD #" << count << " is free!\n";
			continue; //break the current iteration by using "continue" statement
		}

		//input the current/other information
		std::cout << "Is DVD #" << count << " a current release?   (Y/N)";
		std::cin >> choice;

		//input check
		while (choice != 'Y'&&choice != 'y'&&choice != 'N'&&choice != 'n')
			std::cout << "Invalid input, please input again (Y/N):   ";

		//calculate rate based on different types of DVD
		if (choice == 'Y' || choice == 'y')
			total+= CURRENT_RATE;
		else
			total+= OTHER_RATE;		
	}
	std::cout << "The total is $" << total << std::endl;

	return 0;
}