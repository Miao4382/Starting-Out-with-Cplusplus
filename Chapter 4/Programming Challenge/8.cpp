//8. Color Mixer (if/else approach)
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string color_1, color_2;
	cout << "Input color_1:";
	cin >> color_1;
	cout << "Input color_2:";
	cin >> color_2;
	if ((color_1 == "red"&&color_2 == "red") || (color_1 == "blue"&&color_2 == "blue") || (color_1 == "yellow"&&color_2 == "yellow"))
		cout << "Mixing color is: " << color_1 << endl;
	else if ((color_1 == "red"&&color_2 == "blue") || (color_1 == "blue"&&color_2 == "red"))
		cout << "Mixing color is purple\n";
	else if ((color_1 == "red"&&color_2 == "yellow") || (color_1 == "yellow"&&color_2 == "red"))
		cout << "Mixing color is orange.\n";
	else if ((color_1 == "blue"&&color_2 == "yellow") || (color_1 == "yellow"&&color_2 == "blue"))
		cout << "Mixing color is green.\n";
	else
		cout << "Invalid input!";
	return 0;
}





//8. Color Mixing (switch approach)
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//variable definition
	string color_1, color_2;
	int num_1, num_2, num;

	//input the color
	cout << "Please input the first and second color: \n";
	cin >> color_1 >> color_2;
	//assign code to the first and second color
	if (color_1 == "red" || color_1 == "Red" || color_1 == "RED")
		num_1 = 1;
	else if (color_1 == "blue" || color_1 == "Blue" || color_1 == "BLUE")
		num_1 = 5;
	else if (color_1 == "yellow" || color_1 == "Yellow" || color_1 == "YELLOW")
		num_1 = 11;
	else
		cout << "Invalid Input!\n";

	if (color_2 == "red" || color_2 == "Red" || color_2 == "RED")
		num_2 = 1;
	else if (color_2 == "blue" || color_2 == "Blue" || color_2 == "BLUE")
		num_2 = 5;
	else if (color_2 == "yellow" || color_2 == "Yellow" || color_2 == "YELLOW")
		num_2 = 11;
	else
		cout << "Invalid Input!\n";

	num = num_1 + num_2;

	switch (num)
	{
	case 2:
		cout << "The mixing color is red.\n";
		break;
	case 10:
		cout << "The mixing color is blue.\n";
		break;
	case 22:
		cout << "The mixing color is yellow.\n";
		break;
	case 6:
		cout << "The mixing color is purple.\n";
		break;
	case 12:
		cout << "The mixing color is orange+.\n";
		break;
	case 16:
		cout << "The mixing color is green.\n";
		break;
	}

	return 0;
}
