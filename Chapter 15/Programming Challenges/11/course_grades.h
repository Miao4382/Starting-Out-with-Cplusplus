#ifndef COURSE_GRADES_H
#define COURSE_GRADES_H
#include "graded_activity.h"
#include "pass_fail_exam.h"
#include "essay.h"
#include "midterm.h"


class CourseGrades
{
protected:
  GradedActivity* grades[4];
public:
  /* Constructor */
  
  /* Function */
  // mutator function
  void SetLab(GradedActivity* lab)
  { grades[0] = lab; }
  
  void SetPassFailExam(PassFailExam* pfexam)
  { grades[1] = pfexam; }
  
  void SetEssay(Essay* essay)
  { grades[2] = essay; }
  
  void SetMidTerm(Midterm* mid)
  { grades[3] = mid; }
  
  // print the numeric scores and grades for each element in grades[] 
  void Print() const;
  
};


#endif