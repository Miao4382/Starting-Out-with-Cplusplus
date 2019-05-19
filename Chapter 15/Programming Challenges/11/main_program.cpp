#include "course_grades.h"

int main()
{
  CourseGrades miao;
  
  /* Define the four graded activity */
  GradedActivity lab(90.0);
  PassFailExam pfe(10, 1, 70);
  Essay essay(25, 18, 19, 28);
  Midterm midterm(50, 2);
  
  /* Call member function to pass each graded activity to the object */
  miao.SetLab(&lab);
  miao.SetPassFailExam(&pfe);
  miao.SetEssay(&essay);
  miao.SetMidTerm(&midterm);
  
  /* Call print() member function to print score */
  miao.Print();
  
  return 0;
}