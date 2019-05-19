#include <iostream>

int Fibo(int index);

int main()
{
  int index;
  
  std::cout << "Input the index of the number in Fibonacci series: ";
  std::cin >> index;
  
  std::cout << "The number is: " << Fibo(index) << "\n";
  
  return 0;
}

int Fibo(int index)
{
  if (index == 1)
    return 0;
  else if (index == 2)
    return 1;
  else 
    return Fibo(index - 1) + Fibo(index - 2);
}