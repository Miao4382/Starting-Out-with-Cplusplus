// This program uses an if/else if statement to assign a
// letter grade (A, B, C, D, or F) to a numeric test score.
#include <iostream>
using namespace std;

int main()
{
	double testScore;
	int grade;
	cout << "Enter your test score and I will tell you\n";
	cout << "the letter grade you earned: ";
	cin >> testScore;

	if (testScore < 60 && testScore>=0)
		grade = 1;
	else if (testScore < 70 && testScore >= 0)
		grade = 2;
	else if (testScore < 80 && testScore >= 0)
		grade = 3;
	else if (testScore < 90 && testScore >= 0)
		grade = 4;
	else if (testScore <= 100 && testScore >= 0)
		grade = 5;
	else
		grade = 6;

	switch (grade)
	{
	case 1:
		cout << "Your grade is F.\n";
		break;
	case 2:
		cout << "Your grade is D.\n";
		break;
	case 3:
		cout << "Your grade is C.\n";
		break;
	case 4:
		cout << "Your grade is B.\n";
		break;
	case 5:
		cout << "Your grade is A.\n";
		break;
	default:
		cout << "That score isn't valid\n";
	}

		return 0;
	}