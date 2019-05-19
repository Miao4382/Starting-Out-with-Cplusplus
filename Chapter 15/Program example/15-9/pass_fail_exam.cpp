#include "pass_fail_exam.h"

void PassFailExam::SetScore()
{
  // calculate question points and score 
  double point_per_question = 100.0 / question_num_;
  double score = (question_num_ - missed_num_) * point_per_question;
  
  // set score
  GradedActivity::SetScore(score);
}



 