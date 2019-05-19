#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  // define a vector 
  std::vector<int> list{ 1,2,3,4,5,6 };
  
  // define an iterator for vector<int>
  std::vector<int>::iterator iter;
  
  // search 
  iter = std::find(list.begin(), list.end(), 5);
  
  // analyze the result 
  if (iter != list.end())
    std::cout << "Found.\n";
  else 
    std::cout << "Not found.\n";
  
  return 0;
}