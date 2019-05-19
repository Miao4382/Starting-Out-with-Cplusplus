//6 Mass and Weight
#include <iostream>
using namespace std;
int main()
{
	double mass, weight;
	cout << "What is the mass of the object?";
	cin >> mass;
	weight = mass*9.8;

	if (weight > 1000)
		cout << "It is too heavy!\n";
	else if (weight < 10 && weight>0)
		cout << "It is too light!\n";
	else if (weight < 0)
		cout << "invalid input!\n";
	else
		cout << "The weight is: " << weight << " N" << endl;
	return 0;
}