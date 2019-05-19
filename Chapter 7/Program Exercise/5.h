//5. monkey Business
#include <iostream>
const int DAYS = 5, MONKEYS = 3;

void get_data(double num[][DAYS], int rows);
void average(double num[][DAYS], int rows);
void high_low(double num[][DAYS], int rows);

int main()
{
	double food[MONKEYS][DAYS];
	get_data(food, MONKEYS);

	//find and display average
	average(food, MONKEYS);

	//find least and greatest food
	high_low(food, MONKEYS);

	return 0;

}

//get data
void get_data(double num[][DAYS], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < DAYS; j++)
		{
			std::cout << "How much did monkey " << i + 1 << " eat on day " << j + 1 << ": ";
			std::cin >> num[i][j];
			while (num[i][j] < 0)
			{
				std::cout << "Please input non-negative pounds of food eaten: ";
				std::cin >> num[i][j];
			}
		}
	}
}

//Find average
void average(double num[][DAYS], int rows)
{
	double total = 0;
	for (int i = 0; i < MONKEYS; i++)
	{
		for (int j = 0; j < DAYS; j++)
			total += num[i][j];
	}

	std::cout << "The average pounds of food eaten per day is: " << total / DAYS << std::endl;

}

//find least and highest food
void high_low(double num[][DAYS], int rows)
{
	double high_food = 0, low_food = 99999999, total_food_by_one_monkey;
	int high_ID, low_ID; //use ID to store the monkey has highest or lowest food

	for (int i = 0; i < rows; i++)
	{
		total_food_by_one_monkey = 0;
		for (int j = 0; j < DAYS; j++)
		{
			total_food_by_one_monkey += num[i][j];
		}
		if (high_food < total_food_by_one_monkey)
		{
			high_food = total_food_by_one_monkey;
			high_ID = i + 1;
		}
		if (low_food > total_food_by_one_monkey)
		{
			low_food = total_food_by_one_monkey;
			low_ID = i + 1;
		}
	}

	//print out result
	std::cout << "The least amount of food eaten during the week is " << low_food << " pounds, by monkey " << low_ID << std::endl;
	std::cout << "The greatest amount of food eaten during the week is " << high_food << " pounds, by monkey " << high_ID << std::endl;

}