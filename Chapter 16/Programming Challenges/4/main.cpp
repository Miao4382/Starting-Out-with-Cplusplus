#include "template.h"
#include <iostream>

int main()
{
  int v1 = -2, v2 = 5;
  
  std::cout << "The absolute value of " << v1 << " is: " << Abs(v1) << "\n"
  << "The absolute value of " << v2 << " is: " << Abs(v2) << "\n";
  
  return 0;
}