#include "midterm.h"

void Midterm::SetQuestion(int total_question, int missed_question)
{
    total_question_ = total_question;
    missed_question_ = missed_question;
    points_each_question_ = 100.0 / total_question;
	
	/* Calculate scores */
	double score;
	score = (total_question_ - missed_question_) * points_each_question_;
	
	/* Call SetScore() in its base class */
	SetScore(score);
}