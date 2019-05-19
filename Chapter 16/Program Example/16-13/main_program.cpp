#include <vector>
#include <iostream>

int main()
{
  std::vector<char> list;
  
  std::cout << "After defining, list.size() = " << list.size() << "\n";
  list.push_back('A');
  std::cout << "After running list.push_back('A'), list.operator[](0) = " << list.operator[](0) << ". list.size() = " << list.size() << "\n";
  list.pop_back();
  std::cout << "After running list.pop_back(), list.size() = " << list.size() << "\n";
  
  return 0;
}