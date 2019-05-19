#ifndef PHARMACY_H
#define PHARMACY_H

#include "Patient_account.h"

class Pharmacy
{
private:
	double m1;
	double m2;
	double m3;
	double m4;
	double m5;
public:
	/* Constructor */
	Pharmacy(); //to initialize cost of each medication
	
	/* Accessor */
	void display_medication_cost() const; //to display cost for each medication 
	
	/* Method */
	void choose_medication(Patient_account &p) const; //ask user to input choice of medication, then call add_to_total_charge() to add corresponding charge to patient account
};

#endif