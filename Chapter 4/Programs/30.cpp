//Program 4-30: Variable using the same name
#include <iostream>
using namespace std;
int main()
{
	int num = 2;
	{
		double num = 3;
		num += 2;
		cout << num << endl;
	}
	cout << num << endl;

	return 0;
}