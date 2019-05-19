//Checkpoint 3-18
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string person = "Wolfgang Smith";
	cout << right;
	cout << setw(20);
	cout << person << endl;
	cout << left;
	cout << person << endl;
	return 0;

}