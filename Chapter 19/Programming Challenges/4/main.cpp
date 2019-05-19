#include <iostream>

int Sum(int num[], int size)
{
  // base case 
  if (size == 1)
    return num[size - 1];
  
  // calculate sum recursively
  return num[size - 1] + Sum(num, size - 1);
}

int main()
{
  int num[] = { 1,2,3,4,5,6,7,8,9,10 };
  
  std::cout << "The result is: " << Sum(num, 10) << "\n";
  
  return 0;
}