#include "number_stack_template.h"
#include <iostream>

int main()
{
  NumberStack<int> stack(5);
  stack.Push(2);
  stack.Push(9);
  stack.Push(1);

  // display usage
  std::cout << "Current usage:\n";
  stack.DisplayUsage();

  // withdraw each element 
  std::cout << "The values stored in the stack are:\n";
  int temp;
  while (!stack.IsEmpty())
  {
    stack.Pop(temp);
    std::cout << temp << " ";
  }

  // display usage again
  std::cout << "\nCurrent usage after withdrawing all element:\n";
  stack.DisplayUsage();

  return 0;


}