//16. Running the Race: The switch approach
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//variable definition
	string runner1, runner2, runner3;
	double time1, time2, time3;

	//program input
	cout << "Please input the name of the firt runner: ";
	getline(cin, runner1);
	cout << "Please input the time of the first runner: ";
	cin >> time1;
	cin.ignore();
	cout << "Please input the name of the second runner: ";
	getline(cin, runner2);
	cout << "Please input the time of the second runner: ";
	cin >> time2;
	cin.ignore();
	cout << "Please input the name of the third runner: ";
	getline(cin, runner3);
	cout << "Please input the time of the third runner: ";
	cin >> time3;

	//valid check
	if (time1 > 0 && time2 > 0 && time3 > 0)
	{
		int flag1, flag2, flag3, flag;
		flag1 = time1 < time2 ? 1 : 0;
		flag2 = time1 < time3 ? 3 : 0;
		flag3 = time2 < time3 ? 5 : 0;
		flag = flag1 + flag2 + flag3;
		switch (flag)
		{
		case 9: cout << "First:\t" << runner1 << "\nSecond:\t" << runner2 << "\nThird:\t" << runner3 << endl; break;
		case 4: cout << "First:\t" << runner1 << "\nSecond:\t" << runner3 << "\nThird:\t" << runner2 << endl; break;
		case 8: cout << "First:\t" << runner2 << "\nSecond:\t" << runner1 << "\nThird:\t" << runner3 << endl; break;
		case 5: cout << "First:\t" << runner2 << "\nSecond:\t" << runner3 << "\nThird:\t" << runner1 << endl; break;
		case 1: cout << "First:\t" << runner3 << "\nSecond:\t" << runner1 << "\nThird:\t" << runner2 << endl; break;
		case 0: cout << "First:\t" << runner3 << "\nSecond:\t" << runner2 << "\nThird:\t" << runner1 << endl; break;
		default: cout << "Invalid input!\n";
		}
	}
	else
		cout << "The time of the running should be number that greater than zero.\n";

	return 0;

}









//16. Running the Race: The if/else approach
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//variable definition
	string runner1, runner2, runner3;
	double time1, time2, time3;
	string max_n, mid_n, min_n;
	double max, mid, min;

	//program input
	cout << "Please input the name of the firt runner: ";
	getline(cin, runner1);
	cout << "Please input the time of the first runner: ";
	cin >> time1;
	cin.ignore();
	cout << "Please input the name of the second runner: ";
	getline(cin, runner2);
	cout << "Please input the time of the second runner: ";
	cin >> time2;
	cin.ignore();
	cout << "Please input the name of the third runner: ";
	getline(cin, runner3);
	cout << "Please input the time of the third runner: ";
	cin >> time3;

	//valid check
	if (time1 > 0 && time2 > 0 && time3 > 0)
	{
		//find out the minimum time record
		min = time1;
		min_n = runner1;
		if (min < time2);
		else
		{
			min = time2;
			min_n = runner2;
		}
		if (min < time3);
		else
		{
			min = time3;
			min_n = runner3;
		}

		//find out the maximum time record
		max = time1;
		max_n = runner1;
		if (max > time2);
		else
		{
			max = time2;
			max_n = runner2;
		}
		if (max > time3);
		else
		{
			max = time3;
			max_n = runner3;
		}

		//find out the medium time record
		mid = time1;
		mid_n = runner1;
		if ((mid - max)*(mid - min) < 0);
		else
		{
			mid = time2;
			mid_n = runner2;
		}
		if ((mid - max)*(mid - min) < 0);
		else
		{
			mid = time3;
			mid_n = runner3;
		}

		//Output the result
		cout << "First:\t" << min_n << "\nSecond:\t" << mid_n << "\nThird:\t" << max_n << endl;

	}
	else
		cout << "The time of the running should be number that greater than zero.\n";

	return 0;

}