#include <iostream>
#include "saving_account.h"

void ShowMenu(char& choice);
void Deposit(SavingAccount& sa);
void Withdraw(SavingAccount& sa);
void Summary(SavingAccount& sa, double beginning_balance);

int main()
{
  SavingAccount a1(2000, 0.05);
  double beginning_balance = a1.balance();
  
  char choice; // hold user's choice
  
  do 
  {
    ShowMenu(choice);
    
    switch(choice)
    {
    case 'a':
      Deposit(a1); break;
    case 'b':
      Withdraw(a1); break;
    case 'c':
      break;
    }    
    
  } while (choice != 'c');
  
  a1.CalcInt();
  
  Summary(a1, beginning_balance);
  
  return 0;
  
}

void ShowMenu(char& choice)
{
  std::cout << "\n***** Bank Account Manage System *****\n"
  << "Please select one term below:\n"
  << "a. Make a deposit\n"
  << "b. Make a withdrawal\n"
  << "c. End month cycle and show summary for this month\n ";

  std::cin >> choice;
  while (choice != 'a' && choice != 'b' && choice != 'c')
  {
    std::cout << "Invalid code, please select a, b, or c: ";
    std::cin >> choice;
  }
}

void Deposit(SavingAccount& sa)
{
  double d;
  std::cout << "Please enter the amount of deposit: ";
  std::cin >> d;
  while (d <= 0)
  {
    std::cout << "Deposit number should be greater than zero. Please re-input: ";
    std::cin >> d;
  }
  
  sa.Deposit(d);  
  
}

void Withdraw(SavingAccount& sa)
{
  double w;
  std::cout << "Please enter the amount of withdrawal: ";
  std::cin >> w;
  while (w <= 0)
  {
    std::cout << "Withdrawal number should be greater than zero. Please re-input: ";
    std::cin >> w;
  }
  
  sa.Withdraw(w);
}

void Summary(SavingAccount& sa, double beginning_balance)
{
  std::cout << "\n\nMonthly summary:\n";
  std::cout << "Beginning balance: $" << beginning_balance << "\n"
  << "Total number of deposits: " << sa.num_deposit() << "\n"
  << "Total number of withdrawal: " << sa.num_withdraw() << "\n";
  
  double balance_before_charged_service = sa.balance();
  sa.MonthlyProc();
  double balance_after_charged_service = sa.balance();
  
  std::cout << "Service charges: $" << balance_before_charged_service - balance_after_charged_service << "\n";
  std::cout << "Ending balance: $" << sa.balance() << "\n";
  
}