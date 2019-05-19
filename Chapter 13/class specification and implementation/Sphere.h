#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>

class Sphere
{
private:
	//variables
	double radius; //the radius of the sphere
	char name[20]; //the name of the sphere

	//member functions
	void strcpy2(char *destination, const char *source); //function prototype for strcpy function
public:

	Sphere(char *str); //constructor
	~Sphere() //destructor
	{
		std::cout << name << " has been destroyed.\n";
	}

	char *show_name();
	void set_radius(double r);
	double get_radius() const;
};


#endif
