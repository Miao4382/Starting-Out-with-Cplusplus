#include "saving_account.h"
#include <iostream>

/* Function */
// status update function
// this function checks the amount of balance_, then set the status of the account 
// should be called after each function that will modify balance
// balance_ >= 25, status_ = true 
// balance_ < 25, status_ = false 
void SavingAccount::UpdateStatus()
{
  if (balance_ >= 25)
    status_ = true;
  else 
    status_ = false;
}

/* Constructor */
// call the constructor of Account class 
// then call UpdateStatus() to update account status
SavingAccount::SavingAccount(double b, double r) : Account(b, r)
{ UpdateStatus(); }


/* Virtual function */
void SavingAccount::Deposit(double d)
{
  if (balance_ + d >= 25)
  {
    Account::Deposit(d);
    UpdateStatus();
  }
  
  else 
  {
    std::cout << "Your deposit is not enough to re-activate your account.\n";
  }
}

void SavingAccount::Withdraw(double w)
{
  if (status_)
  {
    Account::Withdraw(w);
    UpdateStatus();
  }
  
  else 
    std::cout << "Your account is in-active, withdraw failed\n";
}

void SavingAccount::MonthlyProc()
{
  if (num_withdraw_ > 4)
    monthly_service_charge_ += (num_withdraw_ - 4) * 1;
  
  Account::MonthlyProc();
  
  UpdateStatus();
}