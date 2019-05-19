#include "math_stack_template.h"
#include <iostream>

int main()
{
  MathStack<int> mstack(5);
  mstack.Push(1);
  mstack.Push(2);
  mstack.Push(3);

  mstack.Add();
  int temp;
  mstack.Pop(temp);
  std::cout << "After Add(), the above value is: " << temp << "\n";

  mstack.Push(temp);
  mstack.Sub();
  mstack.Pop(temp);
  std::cout << "After Sub(), the above value is: " << temp << "\nCurrent usage: ";
  mstack.DisplayUsage();

  return 0;
}