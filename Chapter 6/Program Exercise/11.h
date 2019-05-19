//11. lowest Score Drop v1.00
#include <iostream>

void get_score(double &);
void calc_average(double s1, double s2, double s3, double s4, double s5);
double find_lowest(double s1, double s2, double s3, double s4, double s5);
double sum(double s1, double s2, double s3, double s4, double s5);

int main()
{
	double s1, s2, s3, s4, s5;
	get_score(s1);
	get_score(s2);
	get_score(s3);
	get_score(s4);
	get_score(s5);

	calc_average(s1, s2, s3, s4, s5);

	return 0;
}

//get score function
void get_score(double &score)
{
	std::cout << "Please input one of your five scores:\n";
	std::cin >> score;
}

//find lowest function
double find_lowest(double s1, double s2, double s3, double s4, double s5)
{
	double low=s1;
	if (low >= s2)
		low = s2;
	if (low >= s3)
		low = s3;
	if (low >= s4)
		low = s4;
	if (low >= s5)
		low = s5;

	return low;
}

//summation calculation
double sum(double s1, double s2, double s3, double s4, double s5)
{
	return s1 + s2 + s3 + s4 + s5;
}

//average calculation function
void calc_average(double s1, double s2, double s3, double s4, double s5)
{
	double average;
	average = (sum(s1, s2, s3, s4, s5) - find_lowest(s1, s2, s3, s4, s5)) / 4;
	std::cout << "The average of the four highest score is: " << average << "\n";
}

