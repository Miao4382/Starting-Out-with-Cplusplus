//20. The Speed of Sound
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//variable definition
	const double AIR_SPEED = 1100, WATER_SPEED = 4900, STEEL_SPEED = 16400;
	int selection;
	double speed;

	//ask for medium
	cout << "*******Sound travel time calculation program*******\n";
	cout << "Please select a medium that sound travels:\n";
	cout << "1. Air\n2. Water\n3. Steel\n";
	cin >> selection;

	//assign appropriate speed to the speed variable
	switch (selection)
	{
	case 1: speed = AIR_SPEED; break;
	case 2: speed = WATER_SPEED; break;
	case 3: speed = STEEL_SPEED; break;
	default: cout << "Invalid selection!\n"; break;
	}

	if (selection == 1 || selection == 2 || selection == 3)
	{
		cout << "Please input the distance of travel: ";
		double distance, time;
		cin >> distance;
		if (distance >= 0)
		{
			time = distance / speed;
			cout << setprecision(4) << fixed << "The time it will take is: " << time  << " s" << endl;
		}
		else
			cout << "Invalid distance input, please check again!\n";

	}
	else;
	return 0;
}