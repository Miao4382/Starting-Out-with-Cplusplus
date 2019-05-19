#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
  double balance_;
  int num_deposit_;
  int num_withdraw_;
  double annual_interest_rate_;
  double monthly_service_charge_;
public:
  /* Constructor */
  // accepts arguments for the balance and interest rate 
  // set other member variable to zero
  Account(double b, double r);
  
  /* Virtual function */
  virtual void Deposit(double d);
  virtual void Withdraw(double w);
  virtual void CalcInt();
  virtual void MonthlyProc();
  
  /* Accessor */
  double balance() const 
  { return balance_; }
  int num_deposit() const 
  { return num_deposit_; }
  int num_withdraw() const 
  { return num_withdraw_; }
  double annual_interest_rate() const 
  { return annual_interest_rate_; }
  double monthly_service_charge() const 
  { return monthly_service_charge_; }
  
  
};


#endif