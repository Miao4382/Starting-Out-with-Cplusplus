// Programming Challenges 11: Distance per Tank of Gas
#include <iostream>
using namespace std;

int main()
{
	const double gas = 20;
	double mpg_town = 23.5, mpg_high = 28.9;
	double distance_town, distance_high;

	distance_town = gas*mpg_town;
	distance_high = gas*mpg_high;

	cout << "Distance in town: " << distance_town << " miles\n";
	cout << "Distance on highway: " << distance_high << " miles\n";

	return 0;

}