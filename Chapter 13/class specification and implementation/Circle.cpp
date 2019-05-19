#include "Circle.h"

/* Constructor */
Circle::Circle() //default constructor, assign radius to zero
{
	radius = 0;
}

Circle::Circle(double r) //constructor, assign radius with r
{
	radius = r;
}

/* Mutator */
void Circle::set_radius(double r) //assign radius with r
{
	radius = r;
}

/* Accessor */
double Circle::get_radius() const //return radius 
{
	return radius;
}
double Circle::get_area() const //return area
{
	return PI*radius*radius;
}
double Circle::get_diameter() const //return diameter
{
	return 2 * radius;
}
double Circle::get_circumference() const //return circumference
{
	return 2 * PI*radius;
}
