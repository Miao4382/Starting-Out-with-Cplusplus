#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include "account.h"

class SavingAccount : public Account
{
protected:
  bool status_; // true: active; false: inactive
  
  /* Function */
  // status update function
  // this function checks the amount of balance_, then set the status of the account 
  // should be called after each function that will modify balance
  // balance_ >= 25, status_ = true 
  // balance_ < 25, status_ = false 
  void UpdateStatus();
  
public:
  /* Constructor */
  // call the constructor of Account class 
  // then call UpdateStatus() to update account status
  SavingAccount(double b, double r);
  
  /* Accessor */
  bool status() const 
  { return status_; }
  
  /* Virtual function */
  virtual void Deposit(double d);
  virtual void Withdraw(double w);
  virtual void MonthlyProc();
  
};


#endif