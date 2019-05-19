#include <iostream>
#include "binary_search_tree_template.h"

int main()
{
  BinarySearchTree<int> tre;
  
  tre.Add(12);
  tre.Add(7);
  tre.Add(9);
  tre.Add(10);
  tre.Add(22);
  tre.Add(24);
  tre.Add(30);
  tre.Add(18);
  tre.Add(3);
  tre.Add(14);
  tre.Add(20);
  
  std::cout << "tre.Height(): " << tre.Height() << "\n";
  
  return 0;
}