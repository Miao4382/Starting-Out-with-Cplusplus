#include "Sphere.h"
#include <iostream>



void Sphere::set_radius(double r)
{
	if (r > 0)
		radius = r;
	else
	{
		std::cout << "Invalid input, program exit...\n";
		exit(EXIT_FAILURE);
	}

}


double Sphere::get_radius() const
{
	return radius;
}

Sphere::Sphere(char *str) //constructor
{
	strcpy2(name, str); //copy string stored in str to name, to initialize the name of ab object
}


char *Sphere::show_name()
{
	return name;
}

void Sphere::strcpy2(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}