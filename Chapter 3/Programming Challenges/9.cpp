//9. How Many Calories
#include <iostream>
using namespace std;
int main()
{
	const int cookie_inbag = 30, cookie_per_serving = 3, calorie_per_serving = 300;
	double calorie_per_cookie;
	calorie_per_cookie = calorie_per_serving / cookie_per_serving;
	double cookie_ate;
	cout << "How many cookies you ate?\n";
	cin >> cookie_ate;
	cout << "You consumed " << cookie_ate*calorie_per_cookie << " calories.\n";
	return 0;
}