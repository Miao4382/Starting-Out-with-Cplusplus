#ifndef PASSFAILACTIVITY_H
#define PASSFAILACTIVITY_H
#include "graded_activity.h"

class PassFailActivity : public GradedActivity
{
protected:
  double min_passing_score_; // hold the minimum score of passing (passing criteria)
public:
  /* Constructor */
  // default constructor 
  PassFailActivity() : GradedActivity()
  { min_passing_score_ = 0.0; }
  
  // constructor initialize min_passing_score_
  PassFailActivity(double mps) : GradedActivity()
  { min_passing_score_ = mps; }
  
  /* Accessor */
  double min_passing_score() const 
  { return min_passing_score_; }
  
  /* Mutator */
  void SetMinPassingScore(double mps)
  { min_passing_score_ = mps; }
  
  /* Function */
  char GetGrade() const;
};


#endif