#include "number_list_template_2.h"
#include <iostream>

int main()
{
  NumberList<int> list;
  
  for (int i = 1; i <= 100; i++)
  {
    if (i%3)
      list.PushBack(i);
    else
      list.PushFront(i);
  }
  
  std::cout << "The list is: ";
  list.DisplayList();
  
  list.PopBack();
  list.PopFront();
  
  std::cout << "After pop_back and pop_front:\n";
  list.DisplayList();
  
  return 0;
}