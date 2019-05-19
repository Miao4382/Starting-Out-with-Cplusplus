//Exercise 3-27: Golf Score
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double score1, score2, score3, average;
	cout << "Please input your score for three games, separate by a space: \n";
	cin >> score1 >> score2 >> score3;
	average = (score1 + score2 + score3) / 3;
	cout << "The average score is: " << setprecision(2) << fixed << average << endl;
	return 0;
}