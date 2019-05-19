//19. Spectral analysis
#include <iostream>
using namespace std;
int main()
{
	//variable definition
	double wavelength;

	//input
	cout << "Please input the wavelength:\n";
	cin >> wavelength;
	//check validation
	if (wavelength <= 0)
		cout << "Invalid input! Wavelength should be greater than zero.\n";
	else if (wavelength > 0)
	{
		if (wavelength <= 1E-11)
			cout << "Gamma Rays\n";
		else if (wavelength <= 1E-8)
			cout << "X Rays\n";
		else if (wavelength <= 4E-7)
			cout << "Ultraviolet\n";
		else if (wavelength <= 7E-7)
			cout << "Visible Light\n";
		else if (wavelength <= 1E-3)
			cout << "Infrared\n";
		else if (wavelength <= 1E-2)
			cout << "Microwaves\n";
		else if (wavelength > 1E-2)
			cout << "Radio Waves\n";
	}
	else
		cout << "Invalid input! Wavelength should be numbers greater than zero.\n";
	return 0;

}