//6. Kinetic Energy
#include <iostream>

//function prototype
double calculate_KE(double mass, double velocity);
void input(double &mass, double &velocity);

int main()
{
	double mass, velocity, kinetic_energy;
	input(mass, velocity);
	kinetic_energy=calculate_KE(mass, velocity);
	std::cout << "The kinetic energy for an object with mass " << mass << " kg and velocity: " << velocity << " m/s is: " << kinetic_energy << " J\n";

	return 0;
}

//input function
void input(double &mass, double &velocity)
{
	std::cout << "Please input the mass and the velocity of the object: \n";
	std::cin >> mass >> velocity;
	while (mass <= 0 || velocity < 0)
	{
		std::cout << "Invalid input. mass and velocity should be greater than zero. Please input again:\n";
		std::cin >> mass >> velocity;
	}
}

//kinetic energy calculation
double calculate_KE(double mass, double velocity)
{
	return 1.0 / 2 * mass*velocity*velocity;
}
