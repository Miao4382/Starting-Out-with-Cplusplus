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
  std::cout << "Please input a number to search: ";
  std::cin >> num;
  
  if (list.Search(num) != -1)
  {
    std::cout << "Result found! It's element " << list.Search(num) + 1 << "\n";
  }
  else 
    std::cout << "No match found.\n";
  
  return 0;
}