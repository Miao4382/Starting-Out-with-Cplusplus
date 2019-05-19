//22. Freezing and Boiling Points
#include <iostream>
using namespace std;
int main()
{
	//constant definition
	const int ETOH_F = -173, ETOH_B = 172, MER_F = -38, MER_B = 676, O2_F = -362, O2_B = -306, H2O_F = 32, H2O_B = 212;

	//variable definition
	double T;
	
	//input
	cout << "Enter a temperature in Fahrenheit: ";
	cin >> T;

	//compare and output
	if (T <= ETOH_F)
		cout << "Ethanol will freeze.\n";
	if (T <= MER_F)
		cout << "Mercury will freez.\n";
	if (T <= O2_F)
		cout << "Oxygen will freeze.\n";
	if (T <= H2O_F)
		cout << "Water will freeze.\n";
	if (T >= ETOH_B)
		cout << "Ethanol will boil.\n";
	if (T >= MER_B)
		cout << "Mercury will boil.\n";
	if (T >= O2_B)
		cout << "Oxygen will boil.\n";
	if (T >= H2O_B)
		cout << "Water will boil.\n";
	return 0;
}