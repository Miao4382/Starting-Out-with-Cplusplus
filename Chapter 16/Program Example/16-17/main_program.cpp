#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
  // define a vector container 
  std::vector<int> list{ 5,4,2,1,3,5,7,9,0,-2,-5,10 };
  
  // test max_element()
  std::cout << "The maximum element in the list is: " << *(std::max_element(list.begin(), list.end())) << "\n";
  
  // test min_element()
  std::cout << "The minimum element in the list is: " << *(std::min_element(list.begin(), list.end())) << "\n";
  
  return 0;
}