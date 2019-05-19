//class implementation
#include "Account.h"
#include <string>
#include <iostream>

//constructor 
Account::Account() //default constructor if no names are provided, name will be: N/A
{
	name = "N/A";
	balance = 0.0;
	interest_rate = 0.045;
	interest = 0.0;
	transactions = 0;
}

Account::Account(std::string name_input) //constructor, will initialize name, balance, interest rate, interest and number of transaction
{
	name = name_input;
	balance = 0.0;
	interest_rate = 0.045;
	interest = 0.0;
	transactions = 0;
}


//mutator
void Account::set_interest_rate(double rate_input) //set the interest rate for the account
{
	interest_rate = rate_input;
}

void Account::deposit(double deposit_amount) //deposit to bank account, counted as transaction
{
	balance += deposit_amount;
	transactions++;
}

void Account::withdraw(double withdraw_amount) //withdraw from account, show an error if withdrawal amount is greater than the balance. counted as transaction
{
	if (withdraw_amount > balance)
		std::cout << "Insufficient balance, you only have $" << get_balance() << "\n";
	else
	{
		balance -= withdraw_amount;
		transactions++;
	}

}

void Account::calc_interest(int num_period) //calculate amount of interest after num_period
{
	interest = num_period * interest_rate * balance;
	balance += interest;
}

//accessor
std::string Account::get_name() const //returns the name of the account holder 
{
	return name;
}

double Account::get_interest_rate() const //returns the current interest rate
{
	return interest_rate;
}

double Account::get_balance() const //returns the current balance of the account 
{
	return balance;
}

double Account::get_interest() const //returns the current interest
{
	return interest;
}

int Account::get_transactions() const //returns the current transaction number
{
	return transactions;
}