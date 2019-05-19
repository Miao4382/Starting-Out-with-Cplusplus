//class specification 
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account
{
private:
	std::string name; //name of account holder
	double balance; //balance of the account
	double interest_rate; //interest rate, will be initialized by constructor: 0.045
	double interest; //current interest earned, will be calculated by calc_interest function
	int transactions; //record the number of transactions done total for this account, withdraw and deposit is considered as transaction, while calc interest is not
public:
	//constructor 
	Account(); //default constructor if no names are provided, name will be: N/A 
	Account(std::string name_input); //constructor, will initialize name, balance, interest rate, interest and number of transaction

									 //mutator
	void set_interest_rate(double rate_input); //set the interest rate for the account
	void deposit(double deposit_amount); //deposit to bank account, counted as transaction
	void withdraw(double withdraw_amount); //withdraw from account, show an error if withdrawal amount is greater than the balance. counted as transaction 
	void calc_interest(int num_period); //calculate amount of interest after num_period

										//accessor
	std::string get_name() const; //returns the name of the account holder 
	double get_interest_rate() const; //returns the current interest rate
	double get_balance() const; //returns the current balance of the account 
	double get_interest() const; //returns the current interest
	int get_transactions() const; //returns the current transaction number
};

#endif
