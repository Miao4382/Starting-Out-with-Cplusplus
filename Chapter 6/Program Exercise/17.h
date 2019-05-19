//17. Transient population
#include <iostream>

//function prototype
void get_info(double &population_start, double &birth_rate, double &death_rate, double &arrival, double &depature, int &years);
double calc_population(double population_start, double birth_rate, double death_rate, double arrival, double depature, int years);

int main()
{
	//variable definition
	double population_start, birth_rate, death_rate, arrival, departure;
	int years;

	//use get_info function to get the value for the above variable
	get_info(population_start, birth_rate, death_rate, arrival, departure, years);

	//use calculation function to calculate the future population
	double population_future;
	population_future = calc_population(population_start, birth_rate, death_rate, arrival, departure, years);

	//print out the future population
	std::cout << "The population after " << years << " years is: " << population_future << std::endl;

	return 0;
}

//get information
void get_info(double &population_start, double &birth_rate, double &death_rate, double &arrival, double &depature, int &years)
{
	std::cout << "What is the starting population: ";
	std::cin >> population_start;
	std::cout << "What is the birth rate: ";
	std::cin >> birth_rate;
	std::cout << "What is the death rate: ";
	std::cin >> death_rate;
	std::cout << "What is the typical number of people arriving here: ";
	std::cin >> arrival;
	std::cout << "What is the typical number of people leaving here: ";
	std::cin >> depature;
	std::cout << "How many years: ";
	std::cin >> years;
}

//calculate the number after inputed year
double calc_population(double population_start, double birth_rate, double death_rate, double arrival, double depature, int years)
{
	double population=population_start;
	
	for (int i = 2; i <= years; i++)
	{
		population *= (1 + birth_rate - death_rate);
		population += arrival - depature;
	}

	return population;
}

