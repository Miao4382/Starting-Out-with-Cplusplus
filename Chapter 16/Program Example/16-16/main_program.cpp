#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
  int num = 0; // hold number of times of repeat, initialized with 0
  int keyword;
  
  // define a testing vector 
  std::vector<int> list{ 1,1,2,1,1,2,3,4,4,2,1,6,6,3,2,1 };
  
  // input search term
  std::cout << "Please input a keyword to count: ";
  std::cin >> keyword;
  
  // call count 
  num = std::count(list.begin(), list.end(), keyword);
  
  // display result:
  std::cout << "Element " << keyword << " appeared " << num << " times.\n";
  
  return 0;
} 