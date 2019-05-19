// Program 3-6: Calculating average score
#include <iostream>
using namespace std;

int main()
{
	double test1, test2, test3, average;

	cout << "This program can calculate the average score of your test\nPlease enter the score for test 1: ";
	cin >> test1;
	cout << "Please enter the score for test 2: ";
	cin >> test2;
	cout << "Please enter the score for test 3: ";
	cin >> test3;
	average = (test1 + test2 + test3) / 3;
	cout << "The average score is: " << average << endl;
	return 0;
}