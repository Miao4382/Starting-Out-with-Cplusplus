//22, 23. Prime function
#include<iostream>
#include<fstream>

bool prime(int num);
void get_input(int &num1, int &num2);

int main()
{
	//define and input the range
	int num1, num2, N_min, N_max;
	get_input(num1, num2);
	if (num1 > num2)
	{
		N_min = num2;
		N_max = num1;
	}
	else
	{
		N_min = num1;
		N_max = num2;
	}

	//create a file stream object, write head into the file
	std::ofstream cout;
	cout.open("D:\\Prime Number List.txt");
	cout << "Prime Number List\n" << "------------------\n\n";
	cout << "Range: " << N_min << " ~ " << N_max << "\n\n";

	//use a loop to find out all the prime numbers and write into the file
	std::cout << "Processing...please wait...\n";
	for (int j = N_min; j <= N_max; j++)
	{
		if (prime(j))
			cout << j << std::endl;
	}
	
	//operation end notice
	std::cout << "Processing complete, please check the file.\n";
	cout.close();

	return 0;

	
}

bool prime(int num)
{
	for (int i = 2; i <= num - 1; i++)
	{
		if (num%i == 0)
			return false;
	}

	return true;
}


void get_input(int &num1, int &num2)
{
	std::cout << "This program will find out all prime numbers between two positive numbers you input: ";
	std::cin >> num1;
	std::cin >> num2;
	while (num1 < 0 || num2 <= 0)
	{

		std::cout << "Numbers cannot be less than zero, please input again:\n";
		std::cin >> num1 >> num2;
	}
	while (num1 == num2)
	{
		std::cout << "Numbers cannot be equal, please input again:\n";
		std::cin >> num1 >> num2;
	}
}
