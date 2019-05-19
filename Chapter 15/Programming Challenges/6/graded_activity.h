#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
protected:
	double score_; // hold score for a graded activity
public:
	GradedActivity(); // default constructor
	GradedActivity(double s); // initialize with s
  
	/* Accessor */
	double GetScore() const;
	
	/* Mutator */
	void SetScore(double s);
	
	/* Function */
	virtual char GetGrade() const;
};

#endif