#include "number_list_template_2.h"
#include <iostream>
// should overload =, +, -, *, /, as well as relational operator
// so the container is more like the array 
int main()
{
  NumberList<int> list;

  for (int i = 0; i < 20; i++)
    list.AppendNode(i);

  std::cout << list[19] << "\n";
  std::cin >> list[19];
  std::cout << list[19] << "\n";

  return 0;
}