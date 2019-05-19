//4. Larger Than n
#include<iostream>

void larger_than_n(int num[], int size, int number);

int main()
{
	int num[100];
	int number;
	for (int i = 0; i < 100; i++)
		num[i] = 2 * i - 4 * i*i + 6 + i*i*i;

	//input a number to begin
	std::cout << "Please input a number to begin test: ";
	std::cin >> number;

	//call function and try
	larger_than_n(num, 100, number);

	return 0;
}

void larger_than_n(int num[], int size, int number)
{
	std::cout << "Numbers that are larger than " << number <<": " << std::endl;

	for (int i = 0; i < size; i++)
	{
		if (num[i] > number)
			std::cout << num[i] << std::endl;
	}

}
