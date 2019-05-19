//11. Math Tutor (with timing gadget and correctness gadget)
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	//variable definition
	const int N_MAX = 10000, N_MIN = 0;
	int num_1, num_2, seed, result, key;
	unsigned long time0, time1; //used to calculate time

	//generate random number
	seed = time(0);
	srand(seed);
	num_1 = rand() % (N_MAX - N_MIN + 1) + N_MIN;
	num_2 = rand() % (N_MAX-N_MIN + 1) + N_MIN;
	key = num_1 + num_2;

	//output the problem and ask input the key
	cout << "Welcome to math tutor! Please press enter to begin your exercise!";
	cin.get();
	cout << setw(15) << num_1 << endl;
	cout << "+";
	cout << setw(14) << num_2 << endl;
	cout << "_______________\n";
	cout << "Please input your answer!\n";
	time0 = time(0);
	cin >> result;
	time1 = time(0);

	//determine
	if (result == key)
		cout << "Congratulations! You are correct! You spend " << time1-time0 << " seconds on this problem\n";
	else
		cout << "You are incorrect, the key is: " << key << ". You spend: " << time1-time0 << " seconds on this problem." << endl;
	return 0;


}