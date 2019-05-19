//7-23. Case study: Pin-match
#include <iostream>

//global constant
const int NUM_OF_PIN=7;

int main()
{

}

bool compare(int user_input[], int user_pin[], int size)
{
	bool result = true;
	for (int i = 0; i < size; i++)
	{
		if (user_input[i] != user_pin[i])
		{
			result = false;
			break; //you can also use "return" directly to exit the function
		}
	}
	return result;
}