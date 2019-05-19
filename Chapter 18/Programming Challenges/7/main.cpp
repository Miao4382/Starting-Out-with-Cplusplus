#include "math_stack_template.h"
#include <iostream>

int main()
{
  // define an object and initialize it 
  MathStack<int> ms(10);
  for (int i = 1; i <= 10; i++)
    ms.Push(i);
  
  // test add all 
  ms.AddAll();
  int temp;
  ms.Pop(temp);
  std::cout << "Addall result: " << temp << "\n";
  
  // assign value 
  for (int i = 1; i <= 5; i++)
    ms.Push(i);
  
  // test MultAll
  ms.MultAll();
  ms.Pop(temp);
  std::cout << "MultAll result: " << temp << "\n";
  
  return 0;
}