#ifndef ESSAY_H
#define ESSAY_H
#include "graded_activity.h"

const double GRAMMER = 30.0;
const double SPELLING = 20.0;
const double LENGTH = 20.0;
const double CONTENT = 30.0;

class Essay : public GradedActivity
{
private:
  double grammer_;
  double spelling_;
  double length_;
  double content_;
public:
  /* Constructor */
  // default constructor
  // call default constructor for GradedActivity()
  // set each score to 0
  Essay();
  // constructor 
  // call default constructor for GradedActivity()
  // set each score to the value passed in
  // if the passed in value exceeds maximum, set score to maximum
  // call GradeEssay() to save score to score_
  Essay(double g, double s, double l, double c);
  
  /* Function */
  // grade the essay
  // calculate the final score
  // save the final score to score_ (protected member variable)
  void GradeEssay();
};


#endif