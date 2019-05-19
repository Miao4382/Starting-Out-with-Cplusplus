#include <iostream>

double Power(double base, unsigned exponent)
{
  // base case 
  if (exponent == 0)
    return 1;
  else if (exponent == 1)
    return base;
  
  // recursive calculation
  return base * Power(base, exponent - 1);
}

int main()
{
  double base = 2.5;
  int exponent = 2;
  
  std::cout << base << "^" << exponent << " = " << Power(base, exponent) << "\n";
  
  return 0;
}