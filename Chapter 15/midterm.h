#ifndef MIDTERM_H
#define MIDTERM_H
#include "graded_activity.h"

class Midterm : public GradedActivity
{
private:
	int total_question_;
	int missed_question_;
	double points_each_question_;
public:
	// default constructor
	Midterm()
  { 
    total_question_ = 0; 
    missed_question_ = 0; 
    points_each_question_ = 0.0; 
  }
  
	// initialize with total_question and missed_question
	// call SetQuestion() to initialize
	Midterm(int total_question, int missed_question)
  {
    total_question_ = total_question;
    missed_question_ = missed_question;
    points_each_question_ = 100.0 / total_question;
  }
	
	/* Mutator */
	// set the question
	// calculate the points_each_question_ based on total_question_ and 100 score
	// calculate actual score 
	// call SetScore() in its parent class to set score
	void SetQuestion(int total_question, int missed_question);
	
	/* Accessor */
	int GetTotalQuestion() const
  { return total_question_; }
  
	int GetMissedQuestion() const
  { return missed_question_; }
  
	double GetPointEachQuestion() const
  { return points_each_question_; }
  
};

#endif