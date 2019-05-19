#include <iostream>

int gcd(int num1, int num2);

int main()
{
  int n1, n2;
  
  std::cout << "Input two numbers and the greatest common divisor will be shown: ";
  std::cin >> n1 >> n2;
  
  std::cout << "The greatest common divisor is: " << gcd(n1, n2) << "\n";
  
  return 0;
}

int gcd(int num1, int num2)
{
  if (num1 % num2 == 0)
    return num2;
  else 
    return gcd(num2, num1 % num2);
}