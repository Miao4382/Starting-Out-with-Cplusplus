//12. Sofeware sales
#include <iostream>
using namespace std;
int main()
{
	//variable definition
	const int PRICE = 99;
	int unit;
	double sale;

	//input data
	cout << "Please input how many software you want to buy?\n";
	cin >> unit;

	if (unit > 0 && unit < 10)
	{
		sale = PRICE*unit;
		cout << "Your sale is: $" << sale << endl;
	}
	else if (unit >= 10 && unit < 20)
	{
		sale = PRICE*unit*0.8;
		cout << "Your sale is: $" << sale << endl;
	}
	else if (unit >= 20 && unit < 50)
	{
		sale = PRICE*unit*0.7;
		cout << "Your sale is: $" << sale << endl;
	}
	else if (unit >= 50 && unit < 100)
	{
		sale = PRICE*unit*0.6;
		cout << "Your sale is: $" << sale << endl;
	}
	else if (unit >= 100)
	{
		sale = PRICE*unit*0.5;
		cout << "Your sale is: $" << sale << endl;
	}
	else
		cout << "Your input is invalid!\n";

	return 0;
}