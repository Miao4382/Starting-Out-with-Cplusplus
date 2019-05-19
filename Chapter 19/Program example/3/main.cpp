#include <iostream>

int Factorial(int n);

int main()
{
  int num;
  std::cout << "Input a number: ";
  std::cin >> num;
  
  std::cout << num << "! = " << Factorial(num) << "\n";
  
  return 0;
}

int Factorial(int n)
{
  int result = 1;
  if (n == 0)
    return result;
  else 
  {
    result = n * Factorial(n - 1);
    return result;
  }
}