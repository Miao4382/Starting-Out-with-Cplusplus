#include <iostream>
void display();
double input();
void calculation(double);
int main()
{
	display();
	double cup;
	cup=input();
	calculation(cup);
	return 0;
}

//definition of display function
void display()
{
	std::cout << "Welcome to the conversion program.\n";
	std::cout << "This program will convert US cup to fluid ounce.\n";
}

//definition of input function
double input()
{
	double cup;
	std::cout << "Please input the cup number: ";
	std::cin >> cup;
	return cup;
}

//definition of calculation function
void calculation(double cup)
{
	double ounce;
	ounce = cup * 8;
	std::cout << "The corresponding ounce will be: " << ounce << std::endl;
}