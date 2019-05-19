#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
private:
	int year_model;
	std::string make;
	int speed;

public:
	/* Constructor */
	Car(int year_model_input, std::string make_input)
	{
		year_model = year_model_input;
		make = make_input;
		speed = 0;
	}

	/* Accessor */
	int get_year_model() const
	{
		return year_model;
	}
	std::string get_make() const
	{
		return make;
	}
	int get_speed() const
	{
		return speed;
	}

	/* Mutator */
	void accelerate()
	{
		speed += 5;
	}
	void brake()
	{
		speed -= 5;
	}
};

#endif
