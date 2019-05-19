//Program 5-14: test averaging program
#include <iostream>
using namespace std;
int main()
{
	//variable definition
	int N_student, N_test;
	double score, average, total=0, num_student, num_test;
	
	//ask how many students and how many tests
	cout << "How many students: ";
	cin >> N_student;
	cout << "How many tests are going to be averaged: ";
	cin >> N_test;

	for (num_student = 1; num_student <= N_student; num_student++)
	{
		for (num_test = 1; num_test <= N_test; num_test++)
		{
			cout << "What is the score of test " << num_test << " for student " << num_student << endl;
			cin >> score;
			total += score;
		}
		average = total / N_test;
		total = 0;
		cout << "The average score for student " << num_student << " is " << average << endl << endl;
	}

	cout << "That is the all the students and scores\n\n";
	return 0;
}