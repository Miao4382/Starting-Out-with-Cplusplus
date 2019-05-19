#include <iostream>
#include "binary_search_tree_template.h"

int main() {
  BinarySearchTree<int> tre;
  
  tre.Add(12);
  tre.Add(7);
  tre.Add(9);
  tre.Add(10);
  tre.Add(22);
  tre.Add(24);
  tre.Add(21);
  
  BinarySearchTree<int> tre2;
  
  tre2 = tre;
  
  std::cout << "tre2.Height(): " << tre2.Height() << "\n";
  std::cout << "tre2.MaxWidth(): " << tre2.MaxWidth() << "\n";
  
  return 0;
}