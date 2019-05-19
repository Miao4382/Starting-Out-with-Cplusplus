#include "Dice.h"

#include <ctime>
#include <cstdlib>

/* Constructor (both constructor will seed random generator) */
Dice::Dice() //default constructor, will create a 6-sided dice, initialize sideup with 1, total_rolled with 0
{
	side = 6;
	sideup = 1;
	total_rolled = 0;

	srand((unsigned int)time(0));
}

Dice::Dice(int side_input) //constructor, to set the dice's side to side_input 
{
	side = side_input;
	sideup = 1;
	total_rolled = 0;

	srand((unsigned int)time(0));
}

/* Mutator */
int Dice::roll() //roll the dice 
{
	int N_max = side, N_min = 1;
	sideup = rand() % (N_max + N_min - 1) + N_min;
	total_rolled++;
	return sideup;
}

/* Accessor */
int Dice::get_sideup() const //return current sideup value of the dice 
{
	return sideup;
}
int Dice::get_side() const //return the maximum side of the dice 
{
	return side;
}
int Dice::get_rolled_num() const //return the number this dice has rolled 
{
	return total_rolled;
}
