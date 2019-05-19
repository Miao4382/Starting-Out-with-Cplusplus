#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
	double radius;
	const double PI = 3.1415926;
public:
	/* Constructor */
	Circle(); //default constructor, assign radius to zero
	Circle(double r); //constructor, assign radius with r
	
	/* Mutator */
	void set_radius(double r); //assign radius with r
	
	/* Accessor */
	double get_radius() const; //return radius 
	double get_area() const; //return area
	double get_diameter() const; //return diameter
	double get_circumference() const; //return circumference
};

#endif

