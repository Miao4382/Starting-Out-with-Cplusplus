//Program 3-26: Rolling dice
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	unsigned seed;
	const int Nmax = 6, Nmin = 1;
	cout << "The two dices are on the table. \n" << "[Press enter to pick it up]";
	cin.get();
	cout << "Excellent! Now you have two dice in your hand!\n" << "[Press enter to roll the dice.";
	cin.get();
	seed = time(0);
	srand(seed);
	cout << "The dices are still. Now read the dice: \n" << "One is: " << rand() % (Nmax - Nmin + 1) + Nmin << endl;
	cout << "The other one is: " << rand() % (Nmax - Nmin + 1) + Nmin << endl;
	return 0;
}