//21. The Speed of Sound in Gas
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//variable definition
	int selection;
	double speed=0;
	const double CO2 = 258, AIR = 331.5, HELIUM = 972, H2 = 1270;

	//make a selection
	cout << "Please choose one of the following gases:\n";
	cout << "1. Carbon Dioxide\n2. Air\n3. Helium\n4.Hydrogen\n";
	cin >> selection;
	
	//assign speed
	switch (selection)
	{
	case 1: speed = CO2; break;
	case 2: speed = AIR; break;
	case 3: speed = HELIUM; break;
	case 4: speed = H2; break;
	default: cout << "Invalid selection!\n"; break;
	}

	//check and calculate
	if (speed != 0)
	{
		cout << "What is the time of detection (time should be in 0 to 30 s):\n";
		double time, distance;
		cin >> time;
		if (time >= 0 && time <= 30)
		{
			distance = time*speed;
			cout << "The distance is " << distance << " m" << endl;
		}
		else
			cout << "Time is out of range, please check again.\n";
	}
	else;

	return 0;
}