//Program 4-25: Use the fall through feature of the switch statement
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//variable definition
	const string FUNC_1 = "Remote Control", FUNC_2 = "Stereo Sound", FUNC_3 = "Picture in a picture";
	const int MODEL_1 = 100, MODEL_2 = 200, MODEL_3 = 300;
	int model;

	//data input
	cout << "Please input the model number to look for the function: \n";
	cin >> model;

	//Display the model function using fall through feature of the switch statement
	cout << "The model has the following features:\n";
	switch (model)
	{
	case MODEL_3:
		cout << FUNC_3 << endl;
	case MODEL_2:
		cout << FUNC_2 << endl;
	case MODEL_1:
		cout << FUNC_1 << endl;
		break;
	default:
		cout << "You can only choose the 100, 200 and 300.\n";
	}
	//with this feature you don't have to type all the long function list!

	return 0;
}