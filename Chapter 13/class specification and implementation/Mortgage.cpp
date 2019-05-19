#include "Mortgage.h"
#include <cmath>

/* Constructor */
Mortgage::Mortgage() //to initialize loan, rate and year to zero
{
	loan = 0.0;
	rate = 0.0;
	year = 0;
}

/* Mutator */
void Mortgage::set_loan(double loan_input)
{
	loan = loan_input;
}
void Mortgage::set_rate(double rate_input)
{
	rate = rate_input;
}
void Mortgage::set_year(int year_input)
{
	year = year_input;
}

/* Accessor */
double Mortgage::get_payment() const
{
	double term;
	term = pow(1 + rate / 12, 12 * year);

	return (loan*rate*term / (12 * (term - 1)));
}

double Mortgage::get_total_payment() const
{
	return 12 * year*get_payment();
}
