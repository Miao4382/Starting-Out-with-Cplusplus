#include "simple_vector.h"
#include <iostream>

int main()
{
  SimpleVector<int> num;
  
  num.push_back(1);
  num.push_back(2);
  
  for(int i = 0; i < num.size(); i++)
    std::cout << "Element " << i + 1 << ": " << num[i] << "\n";
  
  num.pop_back();
  
  std::cout << "The size becomes: " << num.size() << "\n";
  
  return 0;
}