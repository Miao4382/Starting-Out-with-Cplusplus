#include <iostream>
#include "number_list_template_2.h"

int main()
{
  NumberList<int> list;
  
  for (int i = 1; i <= 100; i++)
    list.PushBack(i);

  std::cout << "Normal order: ";
  list.DisplayList();
  std::cout << "\n\nReverse order: ";
  list.ReverseDisplay();
  std::cout << "\n";

  return 0;
}