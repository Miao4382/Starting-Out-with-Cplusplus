//12. Star Search
#include <iostream>

void get_judge_data(double &score);
void calc_score(double s1, double s2, double s3, double s4, double s5);
double find_high(double s1, double s2, double s3, double s4, double s5);
double find_low(double s1, double s2, double s3, double s4, double s5);

int main()
{
	double s1, s2, s3, s4, s5;
	get_judge_data(s1);
	get_judge_data(s2);
	get_judge_data(s3);
	get_judge_data(s4);
	get_judge_data(s5);

	calc_score(s1, s2, s3, s4, s5);

	return 0;
}

//score input function
void get_judge_data(double &score)
{
	std::cout << "Please enter a score:\n";
	std::cin >> score;
	while (score < 0 || score>10)
	{
		std::cout << "Invalid input, please input a score between 0 ~ 10.\n";
		std::cin >> score;
	}
}

void calc_score(double s1, double s2, double s3, double s4, double s5)
{
	double average;
	average = (s1 + s2 + s3 + s4 + s5 - find_high(s1, s2, s3, s4, s5) - find_low(s1, s2, s3, s4, s5)) / 3;
	std::cout << "After dropping the highest and lowest score, the average score is: " << average << std:: endl;

}

//find highest score
double find_high(double s1, double s2, double s3, double s4, double s5)
{
	double high = s1;
	if (high < s2)
		high = s2;
	if (high < s3)
		high = s3;
	if (high = s4)
		high = s4;
	if (high < s5)
		high = s5;

	return high;
}

//find lowest score
double find_low(double s1, double s2, double s3, double s4, double s5)
{
	double low = s1;
	if (low > s2)
		low = s2;
	if (low > s3)
		low = s3;
	if (low > s4)
		low = s4;
	if (low > s5)
		low = s5;

	return low;
}