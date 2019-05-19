#include "dynamic_stack_template.h"
#include <iostream>

int main()
{
  DynamicStack<int> stack;
  stack.Push(1);
  stack.Push(2);
  stack.Push(3);
  
  std::cout << "Size of stack: " << stack.Size() << "\n";
  
  int temp;
  
  DynamicStack<int> stack_2 = stack;
  
  while (!stack_2.IsEmpty())
  {
    stack_2.Pop(temp);
    std::cout << temp << " ";
  }
  
  std::cout << "\n";
  
  return 0;
}