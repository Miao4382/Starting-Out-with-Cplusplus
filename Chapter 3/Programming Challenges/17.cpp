//17. Math Tutor (a time recording gadget is added)
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	//variable definition
	int number1, number2, sum, seed, time0, time1;
	const int Nmax = 10000, Nmin = 1; //defines the interval of the addition problem

	//random seed and initiate
	seed = time(0);
	srand(seed);
	
	//assignment of the number
	number1 = rand() % (Nmax + Nmin - 1) + Nmin;
	number2 = rand() % (Nmax + Nmin - 1) + Nmin;

	//calculate the sum
	sum = number1 + number2;

	//Output
	cout << "This program is a electronic math tutor. It will help you practice addition problem, press enter to continue.";
	cin.get();
	time0 = time(0);
	cout << setw(5) << number1 << endl
		<< "+" << setw(4) << number2 << endl;
	cout << "_____  (Press enter to show answer)\n";
	cin.get();
	time1 = time(0);
	cout << setw(5) << sum << endl; //show the answer
	cout << "You've spent " << time1 - time0 << " seconds to solve this problem.\n"; //this is a time gadget showing the amount of time spent on this problem
	return 0;
	
}