#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main()
{
  std::vector<int> num;
  
  for (int i = 1; i <= 10; i++)
    num.push_back(i);
  
  // define an iterator for vector<int>
  std::vector<int>::iterator iter;
  
  // print out the content of the vector 
  for (iter = num.begin(); iter < num.end(); iter++)
    std::cout << *iter << "\n";
  std::cout << "\n";
  
  // print out the vector, backward
  iter--;
  std::cout << "\nBackward:\n";
  for (iter; iter >= num.begin(); iter--)
  {
    std::cout << *iter << "\n";
    if (iter == num.begin())
      break;
  }
    
  std::cout << "\n";
  
  return 0;
}