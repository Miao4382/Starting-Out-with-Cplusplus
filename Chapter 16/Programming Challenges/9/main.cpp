#include "searchable_vector.h"
#include <iostream>

int main()
{
  SearchableVector<int> num;
  
  for (int i = 0; i < 10; i++)
    num.push_back(i * 2);
  
  int keyword;
  std::cout << "Please input a keyword to search: ";
  std::cin >> keyword;
  
  if (num.Find(keyword) != -1)
    std::cout << "Match found, it's element " << num.Find(keyword) << "\n";
  else 
    std::cout << "No match found.\n";
  
  return 0;
}