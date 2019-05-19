#include <iostream>
#include "number_list_template_2.h"

int main()
{
  NumberList<int> list;
  
  list.PushBack(2);
  list.PushBack(10);
  
  std::cout << "Now the linked list has " << list.NumNodes() << " elements.\n";
  
  return 0;
}