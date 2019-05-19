#include <iostream>
#include "function_templates.h"

int main()
{
  int n1 = 1, n2 = 2, n3 = 3;
  
  std::cout << "The sum1: " << Sum(n1, n2) << "\n";
  std::cout << "The sum2: " << Sum(n1, n2, n3) << "\n";
  
  return 0;
}