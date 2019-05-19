#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "account.h"

class CheckingAccount : public Account
{
public:
  /* Virtual function */
  virtual void Withdraw(double w);
  virtual void MonthlyProc();  
}


#endif