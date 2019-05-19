#include "essay.h"

/* Constructor */
// default constructor
// call default constructor for GradedActivity()
// set each score to 0
Essay::Essay() : GradedActivity()
{
  grammer_ = 0.0;
  spelling_ = 0.0;
  length_ = 0.0;
  content_ = 0.0;
}
// constructor 
// call default constructor for GradedActivity()
// set each score to the value passed in
// if the passed in value exceeds maximum, set score to maximum
// call GradeEssay() to save score to score_
Essay::Essay(double g, double s, double l, double c) : GradedActivity()
{
  g > GRAMMER ? grammer_ = 30.0 : grammer_ = g;
  s > SPELLING ? spelling_ = 20.0 : spelling_ = s;
  l > LENGTH ? length_ = 20.0 : length_ = l;
  c > CONTENT ? content_ = 30.0 : content_ = c;

  GradeEssay();
}

/* Function */
// grade the essay
// calculate the final score
// save the final score to score_ (protected member variable)
void Essay::GradeEssay()
{
  double final_score = grammer_ + spelling_ + length_ + content_;
  score_ = final_score;
}