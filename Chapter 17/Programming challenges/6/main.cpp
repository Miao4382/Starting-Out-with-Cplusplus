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
  
  int num;
  int position;
  
  std::cout << "Before inserting: ";
  list.DisplayList();
  
  std::cout << "Please input the number and position to be inserted (pay attention, 0 is the first element): ";
  std::cin >> num >> position;
  
  list.InsertNode(num, position);
  
  std::cout << "After inserting: ";
  list.DisplayList();
  
  return 0;
}