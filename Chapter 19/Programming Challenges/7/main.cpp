#include <iostream>

int Sum(int num)
{
  // base case 
  if (num == 1)
    return 1;
  
  // recursively calculate
  return num + Sum(num - 1);
}

int main()
{
  std::cout << Sum(100) << "\n";
  
  return 0;
}