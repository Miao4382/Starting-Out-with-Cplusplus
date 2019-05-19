#ifndef SCORE_H
#define SCORE_H

class Score
{
private:
	double score1;
	double score2;
	double score3;

public:
	Score(); //default constructor, assign score to 0.0
	Score(double s1, double s2, double s3); //constructor-1, assign score to three score variable£»


	/* Mutator */
	void set_score1(double s1)
	{
		score1 = s1;
	}
	void set_score2(double s2)
	{
		score2 = s2;
	}
	void set_score3(double s3)
	{
		score3 = s3;
	}
	
	/* Accessor */
	double get_score1() const
	{
		return score1;
	}
	double get_score2() const 
	{
		return score2;
	}
	double get_score3() const 
	{
		return score3;
	}	
	double get_average() const 
	{
		return (score1+score2+score3)/3;
	}
	
};

#endif