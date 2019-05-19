//2 Rectangle Area-Complete the Program
#include <iostream>

double get_length();
double get_width();
double get_area(double, double);
void display_data(double, double, double);

int main()
{
	double length, width, area;
	length = get_length();
	width = get_width();
	area = get_area(length, width);
	display_data(length, width, area);

	return 0;
}

//get length function
double get_length()
{
	double length;
	std::cout << "Please input the length of the rectangle: ";
	std::cin >> length;
	while (length <= 0)
	{
		std::cout << "The length cannot be less than zero, please input again.\n";
		std::cin >> length;
	}

	return length;
}

//get width function
double get_width()
{
	double width;
	std::cout << "Please input the length of the rectangle: ";
	std::cin >> width;
	while (width <= 0)
	{
		std::cout << "The length cannot be less than zero, please input again.\n";
		std::cin >> width;
	}

	return width;
}

//calculate area
double get_area(double length, double width)
{
	return length*width;
}

//display data function
void display_data(double length, double width, double area)
{
	std::cout << "The rectangle with a length of " << length << " and a width of " << width << " has an area of " << area << std::endl;
}