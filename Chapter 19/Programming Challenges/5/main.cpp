#include <iostream>

double Multiply(double num1, double num2)
{
  // base case 
  if (num2 == 1)
    return num1;
  else if (num2 == 0)
    return 0;
  
  // recursively calculate
  return num1 + Multiply(num1, num2 - 1);
}

int main()
{
  double num1, num2;
  
  std::cout << "Input num1 and num2: ";
  std::cin >> num1 >> num2;
  
  std::cout << num1 << " x " << num2 << " = " << Multiply(num1, num2) << "\n";
  
  return 0;
}