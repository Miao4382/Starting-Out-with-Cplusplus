// Programming Challenges 5: average of values
#include <iostream>
using namespace std;

int main()
{
	double a = 28, b = 32, c = 37, d = 24, e = 33, sum, average;
	sum = a + b + c + d + e;
	average = sum / 5;

	cout << "The average is " << average << endl;
	return 0;
}