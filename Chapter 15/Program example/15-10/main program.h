#include "midterm.h"
#include "pass_fail_activity.h"
#include <iostream>

void DisplayGrade(const GradedActivity& activity);

int main()
{
  GradedActivity ga(89.9);
  Midterm m(100, 21);
  PassFailActivity pfa(60.0);
  pfa.SetScore(71.0); // set the score for a PassFailActivity object
  
  // display score
  DisplayGrade(ga);
  std::cout << std::endl;
  DisplayGrade(m);
  std::cout << std::endl;
  DisplayGrade(pfa);
  
  return 0;
}

void DisplayGrade(const GradedActivity& activity)
{
  using namespace std;
  
  cout << "The activity's numeric score is: " << activity.GetScore() << endl
  << "The activity's letter grade is: " << activity.GetGrade() << endl;  
  
}