#ifndef DICE_H
#define DICE_H

#include <ctime>
#include <cstdlib>

class Dice
{
private:
	int side; //maximum side of the dice
	int sideup; //current value of the up side 
	int total_rolled; //total number rolled by this dice
public:
	/* Constructor (both constructor will seed random generator) */
	Dice(); //default constructor, will create a 6-sided dice, initialize sideup with 1, total_rolled with 0
	Dice(int side_input); //constructor, to set the dice's side to side_input 
	
	/* Mutator */
	int roll(); //roll the dice 
	
	/* Accessor */
	int get_sideup() const; //return current sideup value of the dice 
	int get_side() const; //return the maximum side of the dice 
	int get_rolled_num() const; //return the number this dice has rolled 
	
};

#endif