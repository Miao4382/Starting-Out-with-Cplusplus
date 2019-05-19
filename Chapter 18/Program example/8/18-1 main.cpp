#include "queue_template.h"
#include <iostream>
#include <string>

int main()
{
  StaticQueue<std::string> list(5);
  
  std::string temp;
  std::cout << "Please input five virtues you wish you have: \n";
  
  for (int i = 0; i < list.Capacity(); i++)
  {
    std::cout << i + 1 << ": ";
    getline(std::cin, temp);
    list.Push(temp);
  }
  
  // display all inputed data 
  std::cout << "Here is what you inputed:\n";
  while (!list.Empty())
  {
    temp = list.Front();
    std::cout << temp << "\n";
    
    list.Pop();
  }
  
  return 0;
}