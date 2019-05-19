#include <stack>
#include <iostream>

int main()
{
  // define a stack 
  std::stack<int> stack;
  
  // test empty()
  if (stack.empty())
    std::cout << "The stack is empty.\n";
  else 
    std::cout << "The stack is not empty.\n";
  
  // test push 
  for (int i = 0; i < 100; i++)
    stack.push(i);
  
  // test size 
  std::cout << "The size of the stack is: " << stack.size() << "\n";
  
  // test top() and pop()
  std::cout << "Now retrieving elements from the stack:\n";
  while (!stack.empty())
  {
    std::cout << stack.top() << " ";
    stack.pop();
  }
  std::cout << "\n";
  
  return 0;
}