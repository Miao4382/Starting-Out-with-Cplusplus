#include "sortable_vector.h"
#include <iostream>
#include <cmath>

int main()
{
  SortableVector<double> num;
  
  // assign value 
  for (int i = 0; i < 100; i++)
    num.push_back(2 * pow(-1, i) + i * pow(-1, i));
  
  // display value 
  std::cout << "Before sorting:\n";
  for (int i = 0; i < 100; i++)
    std::cout << num[i] << " ";
  
  // sort 
  num.SortBubble();
  
  // display value
  std::cout << "\n\nAfter sorting:\n";
  for (int i = 0; i < 100; i++)
    std::cout << num[i] << " ";
  
  std::cout << "\n\n";
  
  return 0;
  
}