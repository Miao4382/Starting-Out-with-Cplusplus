#ifndef MORTGAGE_H
#define MORTGAGE_H


class Mortgage
{
private:
	double loan;
	double rate;
	int year;
public:
	/* Constructor */
	Mortgage(); //to initialize loan, rate and year to zero
	
	/* Mutator */
	void set_loan(double loan_input);
	void set_rate(double rate_input);
	void set_year(int year_input);
	
	/* Accessor */
	double get_payment() const;
	double get_total_payment() const;
};

#endif