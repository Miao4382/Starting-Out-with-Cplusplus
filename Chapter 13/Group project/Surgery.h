#ifndef SURGERY_H
#define SURGERY_H

#include "Patient_account.h" //to update charges variable stored in Patient_account, by calling add_to_total_charge() member function in Patient_account

class Surgery
{
private:
	double s1; //surgery cost for s1
	double s2; //surgery cost for s2
	double s3; //surgery cost for s3
	double s4; //surgery cost for s4
	double s5; //surgery cost for s5
public:
	/* Constructor */
	Surgery(); //to initialize the cost for each surgery 
	
	/* Accessor */
	void display_surgery_cost() const; //display cost for each surgery, called in choosing surgery menu
	
	/* Method */
	void choose_surgery(Patient_account &p); //ask user to input choice of surgery, then call add_to_total_charge() to add corresponding charge to patient account
};


#endif