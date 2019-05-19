#include <iostream>
#include "function_templates.h"

int main()
{
  double num1 = 5, num2 = 10;
  std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << "\n"; 
  SwapVars(num1, num2);
  
  std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << "\n";
  
  return 0;
}