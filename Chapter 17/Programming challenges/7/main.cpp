#include "number_list_template_2.h"
#include <iostream>

int main()
{
  NumberList<int> list;
  
  list.AppendNode(2);
  list.AppendNode(4);
  list.InsertNode(3);
  list.InsertNode(7);
  list.InsertNode(1);
  
  int position;
  
  std::cout << "Before inserting: ";
  list.DisplayList();
  
  std::cout << "Please input the position of element to be erased (0 is the first element): ";
  std::cin >> position;
  
  list.Erase(position);
  
  std::cout << "After deleting: ";
  list.DisplayList();
  
  return 0;
}