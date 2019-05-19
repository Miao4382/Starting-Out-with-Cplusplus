#include "checking_account.h"
#include <iostream>

/* Virtual function */
void CheckingAccount::Withdraw(double w)
{
  if (balance_ < w)
  {
    std::cout << "Bad Check! Balance is not enough. $15 service fee is charged to your account.\n";
    balance_ -= 15;
    return;
  }
  
  Account::Withdraw(w);
}

void CheckingAccount::MonthlyProc()
{
  monthly_service_charge_ += 5 + 0.1 * num_withdraw_;
  
  Account::MonthlyProc();
}