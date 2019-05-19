#include <iostream>

int Factorial(int num)
{
  int result = 1;
  
  for (int i = 1; i <= num; i++)
    result *= i;
  
  return result;
}

int main()
{
  int num;
  std::cout << "Input a number: ";
  std::cin >> num;
  
  std::cout << "The factorial is: " << Factorial(num) << "\n";
  
  return 0;
}