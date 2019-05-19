#include "number_list_template_2.h"
#include <iostream>

int main()
{
  NumberList<int> list;
  
  for (int i = 1; i <= 10; i++)
    list.AppendNode(i);
  
  std::cout << "Before reversing: ";
  list.DisplayList();
  list.Reverse();
  std::cout << "After reversing: ";
  list.DisplayList();
  
  return 0;
}