#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  // define the vector 
  int size;
  std::cout << "How many scores: ";
  std::cin >> size;
  std::vector<double> score(size);
  
  // get data 
  std::vector<double>::iterator iter;
  for (iter = score.begin(); iter != score.end(); iter++)
  {
    std::cout << "Please input score " << iter - score.begin() + 1 << ": ";
    std::cin >> *iter;
  }
  
  // sort 
  std::sort(score.begin(), score.end());
  
  // calculate average score 
  double total = 0;
  for (iter = score.begin(); iter != score.end(); iter++)
    total += *iter;
  
  // display result 
  std::cout << "The sorted score:\n";
  for (iter = score.begin(); iter != score.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n\n";
  
  std::cout << "The average score is: " << total / size << "\n";
  
  return 0;
}