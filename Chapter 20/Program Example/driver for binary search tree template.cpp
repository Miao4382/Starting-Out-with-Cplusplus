#include <iostream>
#include "binary_search_tree_template.h"

int main()
{
  BinarySearchTree<int> tree;
  
  tree.Add(10);
  tree.Add(3);
  tree.Add(6);
  tree.Add(12);
  tree.Add(9);
  tree.Add(21);
  
  int key;
  std::cout << "Input a value to search: ";
  std::cin >> key;
  
  if (tree.Search(key))
    std::cout << key << " is in the tree.\n";
  else 
    std::cout << key << " is not in the tree.\n";
  
  std::cout << "Now displaying the tree in order: ";
  tree.Display();
  std::cout << "\nNow displaying the tree in pre-order: ";
  tree.DisplayPreOrder();
  std::cout << "\nNow displaying the tree in post-order: ";
  tree.DisplayPostOrder();
  std::cout << "\n";
  
  // testing copy constructor 
  std::cout << "\n\nNow testing copy constructor: ";
  BinarySearchTree<int> tree2 = tree;
  std::cout << "A copy of tree has been created, now displaying tree2:\n";
  std::cout << "in order: ";
  tree2.Display();
  std::cout << "\npre-order: ";
  tree2.DisplayPreOrder();
  std::cout << "\npost-order: ";
  tree2.DisplayPostOrder();
  std::cout << "\n";
  
  std::cout << "Now delete tree's node, then display tree and tree2 again: ";
  tree.Delete(10);
  tree.Delete(3);
  tree.Delete(6);
  tree.Delete(12);
  tree.Delete(9);
  
  std::cout << "Now displaying the tree in order: ";
  tree.Display();
  std::cout << "\nNow displaying the tree in pre-order: ";
  tree.DisplayPreOrder();
  std::cout << "\nNow displaying the tree in post-order: ";
  tree.DisplayPostOrder();
  std::cout << "\n";

  std::cout << "Now displaying tree2:\n";
  std::cout << "in order: ";
  tree2.Display();
  std::cout << "\npre-order: ";
  tree2.DisplayPreOrder();
  std::cout << "\npost-order: ";
  tree2.DisplayPostOrder();
  std::cout << "\n";  
  
  return 0;
    
}