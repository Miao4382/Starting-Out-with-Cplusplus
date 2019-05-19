#ifndef TEMPERATURE_CHECK_H
#define TEMPERATURE_CHECK_H

class Temperature_check
{
private:
	int temperature;
	const int freeze_ethanol = -173;
	const int freeze_oxygen = -362;
	const int freeze_water = 32;
	const int boil_ethanol = 172;
	const int boil_oxygen = -306;
	const int boil_water = 212;
public:
	/* Constructor */
	Temperature_check()
	{
		temperature = 0;
	}

	/* Mutator */
	void set_temperature(int t)
	{
		temperature = t;
	}

	/* Accessor */
	int get_temperature() const
	{
		return temperature;
	}
	bool is_ethanol_freezing() const;
	bool is_oxygen_freezing() const;
	bool is_water_freezing() const;
	bool is_ethanol_boiling() const;
	bool is_oxygen_boiling() const;
	bool is_water_boiling() const;

};

#endif