#include "essay.h"
#include <iostream>

int main()
{
  Essay essay_1(25, 12, 20, 50);
  
  std::cout << "The letter grade for the essay is: " << essay_1.GetGrade() << "\n";
  
  return 0;
}