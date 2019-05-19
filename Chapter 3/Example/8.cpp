#include <iostream>
using namespace std;

int main()
{
	double a;
	a = 2.0e38*1000; //should overflow a;
	cout << a << endl;
	a = 2.0e-38 / 2.0e38; //should underflow a;
	cout << a << endl;
	return 0;
}