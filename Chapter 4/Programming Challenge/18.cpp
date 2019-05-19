//Fat Gram Calculator
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//variable definition
	double fat_gram, calorie_fat, calorie_total,calorie_fat_percent;
	const double calorie_per_gram_fat = 9;

	//input
	cout << "Please input the number of calories in the food:";
	cin >> calorie_total;
	cout << "Please input the grams of fat in the food: ";
	cin >> fat_gram;

	//calculation
	calorie_fat = fat_gram*calorie_per_gram_fat;
	calorie_fat_percent = calorie_fat / calorie_total;

	//check and calculation
	if (fat_gram >= 0 && calorie_total >= 0 && calorie_fat_percent <= 1)
	{
		cout << calorie_fat_percent*100 << "% of calories come from fat. ";
		if (calorie_fat_percent <= 0.3)
			cout << "This food is low in fat!\n";
	}
	else //show error message
	{
		cout << "Your input has some errors, please check below for reason:\n";
		if (!(fat_gram >= 0))
			cout << "Grams of fat in food should be numbers greater than zero.\n";
		if (!(calorie_total >= 0))
			cout << "Calories of the food should be numbers greater than zero.\n";
		if (!(calorie_fat_percent <= 1))
			cout << "Calories of fat cannot exceed the total calorie in the food.\n";
	}

	return 0;
}