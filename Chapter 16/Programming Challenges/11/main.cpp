#include "sortable_vector.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
const int MIN = 0;
const int MAX = 100;

int main()
{
  SortableVector<int> num;
  
  // seed the rand()
  srand(static_cast<unsigned>(time(0)));
  
  // assign number
  for (int i = 0; i < 100; i++)
  {
    num.push_back((rand() % (MAX - MIN + 1)) + MIN);
  }
  
  // print the list 
  std::cout << "The list is: ";
  for (int i = 0; i < num.size(); i++)
    std::cout << num[i] << " ";
  std::cout << "\n\n\n";
  
  // search 
  int keyword;
  std::cout << "Input a keyword to search: ";
  std::cin >> keyword;
  
  if (num.SortAndSearch(keyword) != -1)
    std::cout << "Match found, it is element " << num.SortAndSearch(keyword) << "\n";
  else 
    std::cout << "No match found.\n";
  
  return 0;
}