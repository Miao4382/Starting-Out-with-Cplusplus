#include "graded_activity.h"

GradedActivity::GradedActivity() // default constructor
{
	score_ = 0.0;
}

GradedActivity::GradedActivity(double s) // initialize with s
{
	score_ = s;
}

/* Accessor */
double GradedActivity::GetScore() const
{
	return score_;
}

/* Mutator */
void GradedActivity::SetScore(double s)
{
	score_ = s;
}

/* Function */
char GradedActivity::GetGrade() const
{
	if (score_ > 89)
		return 'A';
	if (score_ > 79)
		return 'B';
	if (score_ > 69)
		return 'C';
	if (score_ > 59)
		return 'D';
	return 'F';
}