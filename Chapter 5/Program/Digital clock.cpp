//example: digital clock display
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int hour=0, min, second;
	unsigned time0, time1;
	cout.fill('0');
	for (hour = 0; hour <= 23; hour++)
	{
		for (min = 0; min <= 59; min++)
		{
			for (second = 0; second <= 59; second++)
			{
				cout << setw(2) <<hour << ":" << setw(2) << min << ":" << setw(2) << second << endl;
			}
				
		}
	}

	return 0;
}