//Program 4-2: Test score check
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//define variable
	double score1, score2, score3, score4, score5;
	double average;
	const double good = 95;

	//input test score
	cout << "Please input your score for the last 5 exams:\n";
	cin >> score1 >> score2 >> score3 >> score4 >> score5;

	//calculation
	average = (score1 + score2 + score3 + score4 + score5) / 5;

	//output
	cout << setprecision(2) << fixed;
	cout << "Your average score is: " << average << ".\n";
	if (average >= good)
		cout << "Congratulates! You've worked very hard!\n";
	else if (average <= 60)
		cout << "You've failed the last 5 test.You should spend more effort.\n";

	return 0;
}
