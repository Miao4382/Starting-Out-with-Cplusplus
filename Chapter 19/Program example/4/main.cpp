#include <iostream>
#include <string>

int AppearTime(std::string str, char ch, int subscript = 0);

int main()
{
  std::string str = "aaausyaaussyausa";
  char ch;
  
  std::cout << "Input a character to search how many times it appears in the string: ";
  std::cin >> ch;
  
  std::cout << ch << " appeared " << AppearTime(str, ch) << " times in the string.\n";
  
  return 0;
}

int AppearTime(std::string str, char ch, int subscript)
{
  if (subscript == str.size())
    return 0;
  else 
  {
    if (str[subscript] == ch)
      return 1 + AppearTime(str, ch, subscript + 1);
    else 
      return AppearTime(str, ch, subscript + 1);
  }
}