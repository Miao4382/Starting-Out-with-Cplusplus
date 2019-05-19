#include "pass_fail_activity.h"

char PassFailActivity::GetGrade() const
{
  if (score_ >= min_passing_score_)
    return 'P';
  else 
    return 'F';
}