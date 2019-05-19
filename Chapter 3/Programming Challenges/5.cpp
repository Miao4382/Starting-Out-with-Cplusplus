//5. Male and Female Percentages
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double male, female;
	cout << "Please input the number of male registered in this class: ";
	cin >> male;
	cout << "Please input the number of female registed in this class: ";
	cin >> female;
	cout << "The percentage of male and female is shown in the table below: \n";
	cout << "--------------------\n" << setprecision(2) << fixed;
	cout << "Male\t" << male / (male + female) * 100 << "%\n";
	cout << "Female\t" << female / (male + female) * 100 << "%\n";
	cout << "--------------------\n";
	return 0;

}