#include <iostream>
#include "pass_fail_exam.h"

int main()
{
  PassFailExam exam1(20, 3, 60.0);
  
  std::cout << "This exam has " << exam1.question_num() << " questions.\n"
  << "Missed question number: " << exam1.missed_num() << "\n"
  << "Total score: " << exam1.GetScore() << "\n"
  << "Letter grade: " << exam1.GetGrade() << "\n"
  << "Pass/Fail grade: " << exam1.GradedActivity::GetGrade() << "\n";
  
  return 0;
}