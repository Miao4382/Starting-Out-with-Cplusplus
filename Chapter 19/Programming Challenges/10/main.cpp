#include "number_list_template_2.h"
#include <iostream>

int main()
{
  NumberList<int> list;

  list.PushBack(2);
  list.PushBack(4);
  list.PushBack(1);
  list.PushBack(9);
  list.PushBack(22);
  list.PushBack(3);
  list.PushBack(56);
  list.PushBack(71);
  list.PushBack(32);
  list.PushBack(102);
  list.PushBack(55);

  std::cout << "The max node in the list is: " << list.MaxNode() << "\n";

  return 0;
}