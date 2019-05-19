#include "Score.h"

Score::Score() //default constructor, assign score to 0.0
{
	score1 = 0.0;
	score2 = 0.0;
	score3 = 0.0;
}
Score::Score(double s1, double s2, double s3) //constructor-1, assign score to three score variable
{
	score1 = s1;
	score2 = s2;
	score3 = s3;
}

