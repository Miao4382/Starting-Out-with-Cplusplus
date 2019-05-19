#include "int_array.h"
#include <iostream>

int main()
{
  Int_array list(10);
  
  for (int i = 0; i < 10; i++)
    list[i] = i + 5;
  
  std::cout << list[5] << "\n";
  
  try 
  {
    std::cout << list[10];
  }
  
  catch (Int_array::OutBoundary)
  {
    std::cout << "Out of boundary!!\n";
  }
  
  return 0;
}