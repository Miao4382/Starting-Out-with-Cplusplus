#include "Coin.h"
#include <cstdlib>

/* Mutator */
void Coin::toss() //toss coin, get a random number between 1 and 2, save result to sideup: 1-heads, 2-tails
{

	int result;
	result = rand() % (N_max + N_min - 1) + N_min;

	switch (result)
	{
	case 1:
		sideup = "heads"; break;
	case 2:
		sideup = "tails"; break;
	}

}

/* Accessor */
std::string Coin::get_sideup() const //check result of the side 
{
	return sideup;
}
