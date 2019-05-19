#include <stack>
#include <iostream>
#include <string>

int main()
{
  // get string 
  std::string str;
  std::cout << "Please input a string to do delimiter balance check: ";
  getline(std::cin, str);
  
  // define a variable to hold result
  // define a stack to hold record of left delimiter 
  // then go over the string to do the check 
  std::stack<char> check_stack;
  bool balanced = true;
  
  for (unsigned i = 0; i < str.size(); i++)
  {
    if (balanced == false)
      break;
    
    switch (str[i])
    {
    case '{':
    case '[':
    case '(':
      // record left delimiter info 
      check_stack.push(str[i]);
      break;
      
    case '}':
      // check if the stack is empty, if so, exit
      if (check_stack.empty())
      {
        balanced = false;
        break;
      }
      // compare with the top element in the stack, which is the last appeared left-delimiter. 
      if (check_stack.top() == '{')
      {
        // the left and right delimiter matches, pop the left delimiter and continue 
        check_stack.pop();
        break;
      }
      else 
      {
        // not match, exit 
        balanced = false;
        break;
      }
      
    case ']':
      // check if the stack is empty, if so, exit
      if (check_stack.empty())
      {
        balanced = false;
        break;
      }
      // compare with the top element in the stack, which is the last appeared left-delimiter. 
      if (check_stack.top() == '[')
      {
        // the left and right delimiter matches, pop the left delimiter and continue 
        check_stack.pop();
        break;
      }
      else 
      {
        // not match, exit 
        balanced = false;
        break;
      }
      
    case ')':
      // check if the stack is empty, if so, exit
      if (check_stack.empty())
      {
        balanced = false;
        break;
      }
      // compare with the top element in the stack, which is the last appeared left-delimiter. 
      if (check_stack.top() == '(')
      {
        // the left and right delimiter matches, pop the left delimiter and continue 
        check_stack.pop();
        break;
      }
      else 
      {
        // not match, exit 
        balanced = false;
        break;
      }
    }
  }
  
  // display result 
  if (balanced)
    std::cout << "{}, [] and () are balanced.\n";
  else 
    std::cout << "{}, [] and () are not balanced. \n";
  
  return 0;
}