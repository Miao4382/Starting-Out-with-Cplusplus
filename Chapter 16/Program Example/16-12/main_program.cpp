#include "searchable_vector.h"
#include <iostream>

int main()
{
  SearchableVector<char> char_list(50);
  
  for (int i = 65; i < char_list.size() + 65; i++)
    char_list[i - 65] = i;
  
  std::cout << "The character list is: ";
  for (int i = 0; i < char_list.size(); i++)
    std::cout << char_list[i] << " ";
  std::cout << "\n";
  
  int index;
  char keyword = 'c';
  index = char_list.Find(keyword);
  
  if (index == -1)
    std::cout << "Keyword " << keyword << " is not found in the list.\n";
  else 
    std::cout << "Keyword " << keyword << " is found in the list, the index is: " << index << "\n";
  
  return 0;
}