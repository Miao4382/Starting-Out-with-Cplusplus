#include "account.h"
#include <iostream>

/* Constructor */
// accepts arguments for the balance and interest rate 
// set other member variable to zero
Account::Account(double b, double r)
{
  balance_ = b;
  annual_interest_rate_ = r;
  num_deposit_ = 0;
  num_withdraw_ = 0;
  monthly_service_charge_ = 0.0;
}

/* Virtual function */
void Account::Deposit(double d)
{
  num_deposit_++;
  balance_ += d;
}

void Account::Withdraw(double w)
{
  num_withdraw_++;
  
  if (balance_ < w)
  {    
    /* Notify user insufficient balance, then withdraw all */
    std::cout << "Insufficient balance. You can only withdraw $" << balance_ << "\n";
    std::cout << "$" << balance_ << " has been withdrawn.\n";
    balance_ = 0;
    return;
  }
  
  balance_ -= w;
}

void Account::CalcInt()
{
  double monthly_interest_rate = annual_interest_rate_ / 12;
  
  balance_ *= (1 + monthly_interest_rate);
}

void Account::MonthlyProc()
{
  balance_ -= monthly_service_charge_;
  
  num_deposit_ = 0;
  num_withdraw_ = 0;
  monthly_service_charge_ = 0;
}