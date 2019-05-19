#ifndef CURVED_ACTIVITY_H
#define CURVED_ACTIVITY_H
#include "graded_activity.h"

class CurvedActivity : public GradedActivity
{
protected:
  double raw_score_;
  double percent_; // hold the percent of curved activity
public:
  /* Constructor */
  // default constructor
  // set raw_score_ to 0.0, no need to call default constructor of GradedActivity (it will be called automatically)
  // set percent_ to 0.0
  CurvedActivity();
  
  // constructor with initializations
  // initialize with raw_score_ and percentage, GradedActivity constructor is default
  CurvedActivity(double raw_score, double percent);
  
  /* Mutator */
  // set raw score, redefine SetScore in GradedActivity class
  // accepts r_s, assign to raw_score_
  // check if percent_ is 0.0, if it is, notify user
  // if percent_ != 0.0, continue:
  // pass raw_score_ * percent_ to GradedActivity::SetScore() to set the real score 
  void SetScore(double r_s);
  
  // set percent_ 
  void SetPercent(double p)
  { percent_ = p; }
  
  /* Accessor */
  double raw_score() const 
  { return raw_score_; }
  double percent() const 
  { return percent_; }
};

#endif