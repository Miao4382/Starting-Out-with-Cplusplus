//Program 5-13: Sentinel (do-while approach)
#include <iostream>
using namespace std;
int main()
{
	int i=1, score=0, total = 0;
	cout << "Enter the number of points your team has earned\n";
	cout << "so far in the season, then enter -1 when finished.\n\n";

	while (score != -1)
	{
		cout << "Enter the points for game " << i << ": ";
		cin >> score;
		if(score!=-1)
			total += score;
		i++;
	}


	cout << "\n\nThe total points are: " << total << endl;
	return 0;
}




//Program 5-13: Sentinel (for approach)
#include <iostream>
using namespace std;
int main()
{
	int i=1, score=0, total = 0;
	cout << "Enter the number of points your team has earned\n";
	cout << "so far in the season, then enter -1 when finished.\n\n";

	for (i = 1; score != -1; i++)
	{
		cout << "Enter the points for game " << i << ": ";
		cin >> score;
		if (score != -1)
			total += score;
	}


	cout << "\n\nThe total points are: " << total << endl;
	return 0;
}




//Program 5-13: Sentinel (do-while approach)
#include <iostream>
using namespace std;
int main()
{
	int i=1, score=0, total = 0;
	cout << "Enter the number of points your team has earned\n";
	cout << "so far in the season, then enter -1 when finished.\n\n";

	do
	{
		cout << "Enter the points for game " << i << ": ";
		cin >> score;
		if(score!=-1)
			total += score;
		i++;
	} while (score != -1);


	cout << "\n\nThe total points are: " << total << endl;
	return 0;
}