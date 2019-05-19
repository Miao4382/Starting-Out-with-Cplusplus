#include <iostream>
#include "queue_template.h"

int main()
{
  StaticQueue<int> q1(15);
  
  int i = 14;
  
  // add element to the list 
  while (!q1.Full())
    q1.Push(i++);
  
  int temp;
  
  // test copy constructor 
  StaticQueue<int> q2 = q1;
  
  // display each element 
  std::cout << "Element in q1:\n";
  while (!q1.Empty())
  {
    temp = q1.Front();
    std::cout << temp << " ";
    q1.Pop();
  }
  
  std::cout << "Now q1's size is: " << q1.Size() << "/" << q1.Capacity() << "\n";
  
  // display copied queue 
  std::cout << "Element in q2:\n";
  while (!q2.Empty())
  {
    temp = q2.Front();
    std::cout << temp << " ";
    q2.Pop();
  }
  
  std::cout << "Now q2's size is: " << q2.Size() << "/" << q2.Capacity() << "\n";

  return 0;
  
}