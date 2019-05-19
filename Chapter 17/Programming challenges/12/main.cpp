#include "number_list_template_2.h"
#include <iostream>

int main()
{
  double array[] = { 1.1, 2.1, 4.5, 9.9, 7.8, 15.4 };
  
  NumberList<double> list;
  for (int i = 0; i < 20; i++)
    list.AppendNode(i);
  
  // display 
  std::cout << "Before merging\nArray: ";
  for (int i = 0; i < 6; i++)
    std::cout << array[i] << " ";
  std::cout << "\nList: ";
  list.DisplayList();
  
  // merge 
  list.MergeArray(array, 6);
  
  // display
  std::cout << "After merging:\nList: ";
  list.DisplayList();
  
  return 0;
}