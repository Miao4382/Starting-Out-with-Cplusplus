#include "template.h"
#include <iostream>

int main()
{
  int v1 = 2, v2 = 3;
  
  std::cout << "The bigger integer is: " << Maximum(v1, v2) << "\n";
  
  double v3 = 4.75, v4 = 2.57;
  
  std::cout << "The smaller floating number is: " << Minimum(v3, v4) << "\n";
  
  return 0;
}