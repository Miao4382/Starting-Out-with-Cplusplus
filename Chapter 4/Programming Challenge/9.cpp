//9. Change for a dollar game
#include <iostream>
using namespace std;
int main()
{
	int num_p, num_n, num_d, num_q, total;

	cout << "Please input the number of penny, nickel, dime and quarter:";
	cin >> num_p >> num_n >> num_d >> num_q;
	total = num_p + num_n * 5 + num_d * 10 + num_q * 25;
	if (total != 100)
		cout << (total > 100 ? "More than 1 dollar!\n" : "Less than 1 dollar!\n");
	else
		cout << "You win!\n";
	return 0;
}