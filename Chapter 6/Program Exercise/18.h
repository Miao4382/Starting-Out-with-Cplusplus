//18. Paint Job Estimator
#include <iostream>
const double paint_per_squarefeet = 1 / 110.0, labor_per_squarefeet = 8.0 / 110;
const double price_labor_per_hour = 25;

void get_info(int &room_num, double &price_paint);
void get_area(int room_num, double &area_total);
void data_process(double area_total, double price_paint);

int main()
{
	int room_num;
	double price_paint;

	//get info about room number and paint price
	get_info(room_num, price_paint);

	//get total area of the rooms
	double area_total=0;
	get_area(room_num, area_total);

	//calculate cost and display
	data_process(area_total, price_paint);

	return 0;
}

//info input: number of rooms and price of paint
void get_info(int &room_num, double &price_paint)
{
	std::cout << "How many rooms you want to paint: ";
	std::cin >> room_num;
	while (room_num < 1)
	{
		std::cout << "Invalid, room number must be no less than 1, please reinput: ";
		std::cin >> room_num;
	}

	std::cout << "What is the price for paint per gallon: ";
	std::cin >> price_paint;
	while (price_paint < 10)
	{
		std::cout << "paint price should be no less than $10, please re-input:";
		std::cin >> price_paint;
	}
}

//input area
void get_area(int room_num, double &area_total)
{
	double area;
	for (int i = 1; i <= room_num; i++)
	{
		std::cout << "What is the area of room " << i << " : ";
		std::cin >> area;
		while (area < 0)
		{
			std::cout << "Invalid input. The area of a room should be greater than 1. Please re-input: ";
			std::cin >> area;
		}
		area_total += area;
	}
}

//calculate the cost
void data_process(double area_total, double price_paint)
{
	//calculate total gallon of paint and hour of labor needed
	double paint_gallon_total, labor_hour_total;
	paint_gallon_total = area_total*paint_per_squarefeet;
	labor_hour_total = area_total*labor_per_squarefeet;

	//calculate total paint price
	double paint_price_total;
	paint_price_total = price_paint*paint_gallon_total;

	//calculate total labor price
	double labor_price_total;
	labor_price_total = labor_hour_total*price_labor_per_hour;

	//calculate total price
	double price_total;
	price_total = paint_price_total + labor_price_total;

	//print out result
	std::cout << "Total gallons of paint needed: " << paint_gallon_total << "\n"
		<< "Total hours of labor needed: " << labor_hour_total << "\n"
		<< "Paint cost: " << paint_price_total << "\n"
		<< "Labor cost: " << labor_price_total << "\n"
		<< "Total cost: " << price_total << "\n";

}
