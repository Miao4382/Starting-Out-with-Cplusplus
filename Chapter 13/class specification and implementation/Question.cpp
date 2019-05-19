#include "Question.h"
#include <string>

Question::Question() //contains all text and correct answer 
{
	question = "N/A";
	ans_1 = "N/A";
	ans_2 = "N/A";
	ans_3 = "N/A";
	ans_4 = "N/A";
	correct = 0;
}

void Question::set_question(std::string q)
{
	question = q;
}
void Question::set_a1(std::string a1)
{
	ans_1 = a1;
}
void Question::set_a2(std::string a2)
{
	ans_2 = a2;
}
void Question::set_a3(std::string a3)
{
	ans_3 = a3;
}
void Question::set_a4(std::string a4)
{
	ans_4 = a4;
}
void Question::set_key(int key)
{
	correct = key;
}