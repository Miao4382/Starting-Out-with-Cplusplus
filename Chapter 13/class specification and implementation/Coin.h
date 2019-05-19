#ifndef COIN_H
#define COIN_H

#include <string>
#include <cstdlib>
#include <ctime>

const int N_max = 2, N_min = 1;

class Coin
{
private:
	std::string sideup; //hold either "heads" or "tails", result of tossing
public:
	/* Constructor */
	Coin() //seed random generator, create a result for the side of the coin 
	{
		int result;
		int seed = time(0);
		srand(seed);
		
		result = rand() % (N_max + N_min - 1) + N_min;
		
		switch (result)
		{
		case 1:
			sideup = "heads"; break;
		case 2:
			sideup = "tails"; break;
		}
	}
	
	/* Mutator */
	void toss(); //toss coin, get a random number between 1 and 2, save result to sideup: 1-heads, 2-tails
	
	/* Accessor */
	std::string get_sideup() const; //check result of the side 
	
};

#endif