//3. Test Average
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double test1, test2, test3, test4, test5, average;
	cout << "Please input the test score for five tests, separate them by space: \n";
	cin >> test1 >> test2 >> test3 >> test4 >> test5;
	average = (test1 + test2 + test3 + test4 + test5) / 5;
	cout << setprecision(1) << fixed;
	cout << "The average test score is: " << average << endl;
	return 0;
}