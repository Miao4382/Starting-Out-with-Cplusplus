#include <iostream>
#include "curved_activity.h"

int main()
{
  CurvedActivity quiz_1(70.0, 1.2);
  
  std::cout << "The raw score is " << quiz_1.raw_score() << "\n"
  << "The percentage: " << quiz_1.percent() << "\n"
  << "The final grade: " << quiz_1.GetGrade() << "\n";
  
  return 0;
}