#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

class Patient_account
{
private:
	double total_charge; //hold total charge for the patient, including in-hospital fee, surgery fee and medication fee; should be initialized with zero by constructor
	double daily_rate; //hold the daily charge of the hospital, should be initialized by constructor, used to calculate base fee (daily_rate * num_stay)
	int num_stay; //hold the number of staying days, used to calculate base fee, should be initialized by constructor 
	double surgery_charge; //hold surgery charge 
	double medication_charge; //hold medication charge 
public:
	/* Constructor */
	Patient_account(int stay); //set corresponding daily_rate and num_stay, then calculate the base fee and store into total_charge 
	
	/* Mutator */
	void add_to_total_charge(double cost); //add cost to total_charge, called by member function in Surgery and Pharmacy to add surgery or pharmacy fee to the total charge 
	void set_surgery_charge(double cost); //called by surgery object
	void set_medication_charge(double cost); //called by pharmacy object
	
	/* Accessor */
	void display_charge() const; //display details of the bill 
};

#endif