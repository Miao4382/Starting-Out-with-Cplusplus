#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int main()
{
  std::vector<int> num{ 1,2,3,4,5,6,7 };
  
  // print out the content
  for (std::vector<int>::iterator counter = num.begin(); counter != num.end(); counter++)
    std::cout << *counter << " ";
  std::cout << "\n";
  
  // seed the random generator 
  srand(static_cast<unsigned>(time(0)));
  
  // call random_shuffle 
  std::random_shuffle(num.begin(), num.end());
  
  // print the vector again
  std::cout << "After shuffling:\n";
  for (std::vector<int>::iterator counter = num.begin(); counter != num.end(); counter++)
    std::cout << *counter << " ";
  std::cout << "\n";
  
  // sort the vector 
  std::sort(num.begin(), num.end());
  
  // print the vector 
  std::cout << "After sorting:\n";
  for (std::vector<int>::iterator counter = num.begin(); counter != num.end(); counter++)
    std::cout << *counter << " ";
  std::cout << "\n";  
  
  // binary search 
  std::cout << "Please input an integer to search: ";
  int keyword;
  std::cin >> keyword;
  
  if (std::binary_search(num.begin(), num.end(), keyword))
    std::cout << "The keyword \"" << keyword << "\" is in the vector.\n";
  else 
    std::cout << "The keyword \"" << keyword << "\" is not in the vector.\n"; 
  
  return 0;
}