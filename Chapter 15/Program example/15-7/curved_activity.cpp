#include "curved_activity.h"
#include <iostream>

/* Constructor */
// default constructor
// set raw_score_ to 0.0, no need to call default constructor of GradedActivity (it will be called automatically)
// set percent_ to 0.0
CurvedActivity::CurvedActivity() : GradedActivity()
{
  raw_score_ = 0.0;
  percent_ = 0.0;
}

// constructor with initializations
// initialize with raw_score_ and percentage, GradedActivity constructor is default
CurvedActivity::CurvedActivity(double raw_score, double percent) : GradedActivity()
{
  percent_ = percent;
  SetScore(raw_score); // call SetScore() in CurvedActivity to set the score and store in GradedActivity
}

/* Mutator */
// set raw score, redefine SetScore in GradedActivity class
// accepts r_s, assign to raw_score_
// check if percent_ is 0.0, if it is, notify user
// if percent_ != 0.0, continue:
// pass raw_score_ * percent_ to GradedActivity::SetScore() to set the real score 
void CurvedActivity::SetScore(double r_s)
{
  raw_score_ = r_s;
  
  if (percent_ == 0.0)
    std::cout << "Percent is 0.0, score setting failed.\n";
  else
  {
    GradedActivity::SetScore(raw_score_ * percent_);
  }
}