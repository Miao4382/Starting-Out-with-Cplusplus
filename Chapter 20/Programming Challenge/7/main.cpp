#include <iostream>
#include "binary_search_tree_template.h"
#include "dynamic_queue_template.h"

int main()
{
  // create a tree 
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

  // create a queue 
  DynamicQueue<int> que;
  
  // convert the tree to queue 
  tre.ConvertQueue(que);
  
  // display the que 
  std::cout << "The tree is converted into a queue: ";
  
  int temp; // temporary variable that hold the value popped out from queue
  while (!que.Empty())
  {
    que.Pop(temp);
    std::cout << temp << " ";
  }
  std::cout << "\n";
  
  return 0;
  
}