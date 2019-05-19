//Program 5-4: Decreasing Temperature
#include <iostream>
using namespace std;
int main()
{
	//define the maximum temperature (constant) and temperature
	const double MAX_T = 102.5;
	double T;

	//display input information
	cout << "Please input the temperature: ";
	cin >> T;
	while (T > MAX_T)
	{
		cout << "The temperature is too hot, please adjust the heater.\n";
		cout << "Turn it down a little and wait five minutes to see the\n";
		cout << "result. Please input the temperature here: ";
		cin >> T;
	}
	cout << "The temperature is acceptable, check it again in 15 minutes.\n";

	return 0;
}