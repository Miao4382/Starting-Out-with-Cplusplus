#include <stack>
#include <iostream>
#include <string>

int main()
{
  // get the string 
  std::string str; 
  std::cout << "Please input a string to test: ";
  getline(std::cin, str);
  
  // check if the parentheses are balanced 
  bool balanced = true;
  
  std::stack<int> check_stack;
  
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '(')
      check_stack.push(1);
    
    if (str[i] == ')')
    {
      // check if the stack is empty 
      if (check_stack.empty())
      {
        balanced = false;
        break;
      }
      
      // the stack is not empty: there is a preceding '(', pop it 
      check_stack.pop();
    }
  }
  
  // if the check_stack is not empty after the above loop, it means the parentheses is not balanced 
  if (!check_stack.empty())
    balanced = false;
  
  // display result 
  if (balanced)
    std::cout << "The parentheses are balanced.\n";
  else 
    std::cout << "The parentheses are not balanced.\n";
  
  return 0;
}