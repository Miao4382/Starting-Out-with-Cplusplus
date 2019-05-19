#ifndef PASS_FAIL_EXAM_H
#define PASS_FAIL_EXAM_H
#include "pass_fail_activity.h"

class PassFailExam : public PassFailActivity
{
protected:
  int question_num_; // hold the total number of questions in exam 
  int missed_num_; // hold the number of missed question 
public:
  /* Constructor */
  // default constructor
  // assign question and missed number to 0
  PassFailExam() : PassFailActivity()
  {
    question_num_ = 0;
    missed_num_ = 0;
  }
  
  // initialize with question, missed number, as well as the min_passing_score
  // call SetScore to set score (calculate points for each question, then calculate score)
  PassFailExam(int q_n, int m_n, double mps) : PassFailActivity(mps)
  {
    question_num_ = q_n;
    missed_num_ = m_n;
    
    // call SetScore() to set score 
    SetScore();
  }
  
  /* Accessor */
  int question_num() const 
  { return question_num_; }
  int missed_num() const 
  { return missed_num_; }
  
  /* Mutator */
  void SetMissedNum(int m_n)
  {
    missed_num_ = m_n;
    // after modifying missed question number, re-set score 
    SetScore();
  }
  
  /* Function */
  void SetScore();
};


#endif