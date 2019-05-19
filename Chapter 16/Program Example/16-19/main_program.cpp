#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
void increment(T& element)
{
  element = element + 1;
}

int main()
{
  // define vector 
  std::vector<char> list { 'a', 'b', ':', 'Y', '{' };
  
  // print out the vector 
  for (std::vector<char>::iterator iter = list.begin(); iter != list.end(); iter++)
    std::cout << *iter << " ";
  
  // call for_each 
  std::for_each(list.begin(), list.end(), increment);
  
  // print again
  std::cout << "\n\nAfter for_each:\n";
  for (std::vector<char>::iterator iter = list.begin(); iter != list.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";
  
  return 0;
}