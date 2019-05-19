#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question
{
private:
	std::string question;
	std::string ans_1;
	std::string ans_2;
	std::string ans_3;
	std::string ans_4;
	int correct; //store the correct answer
public:
	/* Constructor */
	Question(); //initialize each slot with zero or N/A

	/* Mutator */
	void set_question(std::string q);
	void set_a1(std::string a1);
	void set_a2(std::string a2);
	void set_a3(std::string a3);
	void set_a4(std::string a4);
	void set_key(int key);

	/* Accessor */
	std::string get_question() const
	{
		return question;
	}
	std::string get_ans1() const
	{
		return ans_1;
	}
	std::string get_ans2() const
	{
		return ans_2;
	}
	std::string get_ans3() const
	{
		return ans_3;
	}
	std::string get_ans4() const
	{
		return ans_4;
	}
	int get_key() const
	{
		return correct;
	}
};

#endif