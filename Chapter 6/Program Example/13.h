//13. Calculate Circle Area
#include <iostream>
double get_radius();
double square(double);
void area_calculation(double);

int main()
{
	area_calculation(get_radius());
	return 0;
}

void area_calculation(double radius)
{
	const double PI = 3.1415926535;
	std::cout << "The area is " << PI*square(radius) << std::endl;
}

double get_radius()
{
	double radius;
	std::cout << "Please input the radius of the circle: ";
	std::cin >> radius;
	return radius;
}

double square(double num)
{
	return num*num;
}

