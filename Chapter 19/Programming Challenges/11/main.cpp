#include <string>
#include <iostream>

bool CheckPalindrome(std::string str, int start_index = 0)
{
  // base case
  // when size is even number, compare str[size / 2 - 1] and str[size / 2]
  // if equal, return true, otherwise, return false 
  // when size is odd, return true 
  if (start_index == (str.size() - 1) / 2)
  {
    if (str.size() % 2 == 0)
    {
      if (str[start_index] == str[start_index + 1])
        return true;
      else 
        return false;
    }
    
    return true;
  }
  
  // recursively solve the problem
  if ((str[start_index] == str[str.size() - start_index - 1]) && CheckPalindrome(str, start_index + 1))
    return true;
  else 
    return false;
  
}

int main()
{
  std::string str;
  
  std::cout << "Input a string: ";
  getline(std::cin, str);
  
  if (CheckPalindrome(str))
    std::cout << "It is a palindrome\n";
  else 
    std::cout << "It is not a palindrome.\n";
}