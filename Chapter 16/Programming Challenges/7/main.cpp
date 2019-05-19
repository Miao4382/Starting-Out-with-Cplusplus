#include "test_score.h"
#include <iostream>
#include <cstdlib>

int main()
{
  double score[] = { 71.5, 67.8, 99.2 };
  
  TestScore<double> student1(score, 3);
  
  try 
  {
    std::cout << "The average score is: " << student1.Average() << "\n";
  }
  
  catch (TestScore<double>::InvalidScore obj)
  {
    std::cout << "The " << obj.index() << "th score is invalid.\n";
    exit(0);
  }
  
  return 0;
}