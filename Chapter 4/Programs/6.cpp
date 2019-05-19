//Program 4-6: If-block statements
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//variable definition
	const double good_score = 95;
	double score1, score2, score3;
	double average;

	//input
	cout << "Please input your score for three tests: \n";
	cin >> score1 >> score2 >> score3;

	//calculation
	average = (score1 + score2 + score3)/3;

	//Display average score
	cout << setprecision(2) << fixed;
	cout << "Your average score is: " << average << endl;

	//additional information if the score is high
	if (average >= good_score)
	{
		cout << "Congratulations!\n";
		cout << "That's a high score!\n";
		cout << "You deserve a pat on the back!\n";
	}
}

