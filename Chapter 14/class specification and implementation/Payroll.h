#ifndef PAYROLL_H
#define PAYROLL_H

class Payroll
{
private:
	double pay_rate;
	int hour;
	double total_pay;
public:
	/* Constructor */
	Payroll()
	{
		pay_rate = 55;
	}
	
	/* Mutator */
	void set_hour(int hour_input); //set work hour and calculate total pay, store to total_pay
	
	/* Accessor */
	double get_total_pay() const;
};

#endif

