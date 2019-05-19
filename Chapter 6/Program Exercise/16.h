//16. population
#include<iostream>

void get_info(double &P, double &B, double &D, int &Y);
double calc_N(double P, double B, double D);

int main()
{
	double P, B, D, N;
	int Y;
	get_info(P, B, D, Y);
	N=calc_N(P, B, D);

	std::cout << "The size of the population for year " << Y << " is: " << N << std::endl;
	return 0;
}

//get info function
void get_info(double &P, double &B, double &D, int &Y)
{
	std::cout << "Input present population, birth rate, death rate and year:\n";
	std::cin >> P >> B >> D >> Y;
	while (P < 2 || B < 0 || D < 0 || Y < 1)
	{
		std::cout << "Invalid input. The present population size should be greater than 2. Birth rate and death rate should be higher than zero. Year should be greater than 1. Please re-input: \n";
		std::cin>> P >> B >> D >> Y;
	}
}

//calculate new size
double calc_N(double P, double B, double D)
{
	return P + P*B - D*P;
}
