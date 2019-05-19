// test driver program
#include "number_list.h"
#include <iostream>

int main()
{
  NumberList list;
  
  // append mode in ascending order
  for (int i = 1; i <= 20; i++)
    list.AppendNode(i * 3.725);
  
  // display the content
  list.DisplayList();
  
  // insert three node
  std::cout << "\n\n";
  list.InsertNode(1.63);
  list.InsertNode(15.77);
  list.InsertNode(55.93);
  
  // display the list again
  std::cout << "After inserting three nodes:\n";
  list.DisplayList();
  
  // delete the node with value of 37.25
  std::cout << "\n\nAfter deleting the node whose value is 37.25:\n";
  list.DeleteNode(37.25);
  list.DisplayList();
  
  // exam descending sorting and inserting 
  NumberList list2;
  
  // append two nodes, in descending order 
  list2.AppendNode(100.7);
  list2.AppendNode(19.4);
  
  // display 
  std::cout << "\n\nNow testing descending inserting. The original order is:\n";
  list2.DisplayList();
  
  // insert multiple values into the list 
  list2.InsertNode(253.78);
  list2.InsertNode(3.4);
  list2.InsertNode(87.14);
  list2.InsertNode(69);
  list2.InsertNode(55);
  list2.InsertNode(88);
  list2.InsertNode(15.69);

  // display the result 
  std::cout << "\nAfter inserting several random nodes:\n";
  list2.DisplayList();
  
  std::cout << "\n";
  return 0;
}