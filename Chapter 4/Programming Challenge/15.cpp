//15. Shipping Charges
#include <iostream>
using namespace std;
int main()
{
	//variable definition
	double weight, distance, charge;

	//program input: weight, and the corresponding check
	cout << "What is the weight of the cargo?\n";
	cin >> weight;
	if (weight <= 0 || weight > 20)
	{
		cout << "Error message:\n";
		if (weight <= 0)
			cout << "Your cargo's weight can't be zero or less than zero.\n";
		if (weight > 20)
			cout << "Your cargo's weight can't excess 20 kg.\n";
	}
	else //The check of weight is done, proceed to input distance
	{
		cout << "What is the distance you wish to ship your cargo?\n";
		cin >> distance;
		if (distance < 10 || distance>3000)
		{
			if (distance < 10)
				cout << "Your distance can't be less than 10 miles.\n";
			if (distance > 3000)
				cout << "Your distance can't be more than 3000 miles.\n";
		}
		else
		{
			if (weight <= 2)
				charge = weight*1.1*distance / 500;
			else if (weight <= 6)
				charge = weight*2.2*distance / 500;
			else if (weight <= 10)
				charge = weight*3.7*distance / 500;
			else if (weight <= 20)
				charge = weight*4.8*distance / 500;

			cout << "Your charge is going to be: $" << charge << endl;
		}
	}

	return 0;
		
}





//15-(2):Shipping Charge, another approach
#include <iostream>
using namespace std;
int main()
{
	//variable definition
	double weight, distance, charge;

	//program input
	cout << "What is the weight of your cargo?";
	cin >> weight;
	cout << "What is the distance of your shipping?";
	cin >> distance;

	//check status
	//When the shipping is available
	if ((weight > 0 && weight <= 20) && (distance >= 10 && distance <= 3000))
	{
		if (weight <= 2)
			charge = 1.1*weight*distance / 500;
		else if (weight <= 6)
			charge = 2.2*weight*distance / 500;
		else if (weight <= 10)
			charge = 3.7*weight*distance / 500;
		else
			charge = 4.8*weight*distance / 500;
		cout << "The shipping charge is: $" << charge << endl;
	}
	//Display error message
	else
	{
		cout << "Error message:\n";
		if (weight <= 0)
			cout << "Invalid weight.\n";
		if (weight > 20)
			cout << "Over-weighted.\n";
		if (distance < 10)
			cout << "Distance is not applicable.\n";
		if (distance > 3000)
			cout << "Distance is too far to be reached.\n";
	}

	return 0;
}