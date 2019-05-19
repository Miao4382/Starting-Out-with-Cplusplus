#include <iostream>
#include "template.h"

int main()
{
  double sum;
  
  Total(3, sum);
  
  std::cout << "The sum is: " << sum << "\n";
  
  return 0;
}