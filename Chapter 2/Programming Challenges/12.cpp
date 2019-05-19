// Programming Challenges 12: Land Calculation
#include <iostream>
using namespace std;

int main()
{
	double acre, feet2 = 391876, feet2_per_acre=43560;

	acre = feet2 / feet2_per_acre;

	cout << "Number of acres: " << acre << endl;
	return 0;
}