#include <iostream>
#include "binary_search_tree_template.h"

int main()
{
  BinarySearchTree<int> tre;
  
  tre.Add(2);
  tre.Add(3);
  tre.Add(1);
  tre.Add(4);
  tre.Add(5);
  
  std::cout << "tre.NodeCount(): " << tre.NodeCount() << "\n";
  std::cout << "tre.NodeNum(): " << tre.NodeNum() << "\n";
  
  return 0;
}