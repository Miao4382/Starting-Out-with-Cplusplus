#include "number_list_template.h"
#include "feet_inch.h"
#include <iostream>

int main()
{
  NumberList<FeetInch> sizes;
  
  // store some values, in descending order 
  sizes.AppendNode(12.8);
  sizes.AppendNode(11.7);
  
  sizes.InsertNode(25.7);
  sizes.InsertNode(11.2);
  sizes.InsertNode(65.6);
  sizes.InsertNode(12.3);
  sizes.InsertNode(87.4);
  sizes.InsertNode(4.6);
  sizes.InsertNode(1.2);
  sizes.InsertNode(44.3);
  sizes.InsertNode(56.1);
  
  // display
  sizes.DisplayList();
  
  // delete 
  sizes.DeleteNode(25.7);
  sizes.DeleteNode(87.4);
  
  // display 
  std::cout << "After deleting 25.7 feet and 87.4 feet:\n";
  sizes.DisplayList();
  
  
  return 0;
}