#include <iostream>
#include <string>
#include "binary_search_tree_template.h"

int main()
{
  // declare a binary search tree to hold string 
  BinarySearchTree<std::string> str_tree;
  
  // add node into tree 
  str_tree.Add("Yssdw");
  str_tree.Add("uywq");
  str_tree.Add("Kisw");
  str_tree.Add("Yu miao");
  str_tree.Add("Oiub");
  str_tree.Add("MMde");
  str_tree.Add("Masw");
  
  // display each node via inorder
  str_tree.Display();
  
  return 0;
}