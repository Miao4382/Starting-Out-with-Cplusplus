#include <iostream>
#include <string>

void ReversePrint(std::string str, int print_position = 0)
{
  // base case: print_position is the last character in the string 
  if (print_position == str.size() - 1)
  {
    std::cout << str[print_position];
    return;
  }

  // recursively print 
  ReversePrint(str, print_position + 1);
  std::cout << str[print_position];

}


int main()
{
  std::string str = "Patience, like faith, remove mountains.";

  std::cout << "Original string: " << str << "\n";
  std::cout << "Reversely print: ";
  ReversePrint(str);
  std::cout << "\n";

  return 0;
}