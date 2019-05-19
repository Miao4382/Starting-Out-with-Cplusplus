#include "number_list_template_2.h"
#include <iostream>

int main()
{
  NumberList<int> list;
  
  for (int i = 1; i <= 10; i++)
    list.AppendNode(i);
  
  // print the original list 
  std::cout << "The original list is:\n ";
  list.DisplayList();
  
  // test copy constructor 
  NumberList<int> list_copy = list;
  
  // printed the copied list 
  std::cout << "The copied list is:\n";
  list.DisplayList();
  
  return 0;
}