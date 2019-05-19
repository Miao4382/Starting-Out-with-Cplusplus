#include "graded_activity.h"
#include "pass_fail_exam.h"
#include "course_grades.h"
#include "essay.h"
#include "midterm.h"
#include <iostream>

// print the numeric scores and grades for each element in grades[] 
void CourseGrades::Print() const
{
  std::cout << "***** Lab *****\n"
  << "Score: " << grades[0] -> GetScore() << "\n"
  << "Grade: " << grades[0] -> GetGrade() << "\n\n";
  
  std::cout << "***** Pass/Fail Exam *****\n"
  << "Score: " << grades[1] -> GetScore() << "\n"
  << "Grade: " << grades[1] -> GetGrade() << "\n\n";  
  
  std::cout << "***** Essay *****\n"
  << "Score: " << grades[2] -> GetScore() << "\n"
  << "Grade: " << grades[2] -> GetGrade() << "\n\n";

  std::cout << "***** Middle Term *****\n"
  << "Score: " << grades[3] -> GetScore() << "\n"
  << "Grade: " << grades[3] -> GetGrade() << "\n\n";
}