#ifndef POPULATION_H
#define POPULATION_H

class Population
{
private:
	int population;
	int birth;
	int death;

public:
	Population(int p, int b, int d)
	{
		population = p;
		birth = b;
		death = d;
	}

	double get_birth_rate() const
	{
		return static_cast<double>(birth) / population;
	}

	double get_death_rate() const
	{
		return static_cast<double>(death) / population;
	}
};

#endif

