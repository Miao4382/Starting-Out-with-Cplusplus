//4. Safest Driving Area
#include <iostream>
#include <string>

//function prototype
int getNumAccidents(std::string);
void findLowest(int, int, int, int, int);

//global constant
int num_N, num_S, num_E, num_W, num_C;

int main()
{

	num_N = getNumAccidents("North");
	num_S = getNumAccidents("South");
	num_E = getNumAccidents("East");
	num_W = getNumAccidents("West");
	num_C = getNumAccidents("Central");
	findLowest(num_N, num_S, num_E, num_W, num_C);

	return 0;
}

//get accident number program
int getNumAccidents(std::string area)
{
	int num;
	std::cout << "Please input the number of accidents in " << area << std::endl;
	std::cin >> num;
	while (num < 0)
	{
		std::cout << "The number of accident can not be less than zero, please input again:\n";
		std::cin >> num;
	}

	return num;
}

//get the lowest value
void findLowest(int N, int S, int E, int W, int C)
{
	int low = N;
	if (low > S)
		low = S;
	if (low > E)
		low = E;
	if (low > W)
		low = W;
	if (low > C)
		low = C;
	if (low == N)
		std::cout << "North area is the safest region, with only " << low << " accidents.\n";
	if (low == S)
		std::cout << "South area is the safest region, with only " << low << " accidents.\n";
	if (low == E)
		std::cout << "East area is the safest region, with only " << low << " accidents.\n";
	if (low == W)
		std::cout << "West area is the safest region, with only " << low << " accidents.\n";
	if (low == C)
		std::cout << "Central area is the safest region, with only " << low << " accidents.\n";
}
