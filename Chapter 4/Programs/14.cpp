//Program 4-12: Multiple Nested Decision Structures
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//variable definition
	double score1, score2, score3;
	string name1, name2, name3;
	string grade1, grade2, grade3;

	//Input the score and name for three students
	//1
	cout << "What is the name for the first student: ";
	getline(cin, name1);
	cout << "What is his score: ";
	cin >> score1;
	//2
	cout << "What is the name for the second student: ";
	cin.ignore();
	getline(cin, name2);
	cout << "What is his score: ";
	cin >> score2;
	//3
	cout << "What is the name for the third student: ";
	cin.ignore();
	getline(cin, name3);
	cout << "What is his score: ";
	cin >> score3;

	//decide the grade
	//1
	if (score1 >= 90)
		grade1 = "A";
	else if (score1 >= 80)
		grade1 = "B";
	else if (score1 >= 70)
		grade1 = "C";
	else if (score1 >= 60)
		grade1 = "D";
	else if (score1 >= 0)
		grade1 = "F";
	else
		grade1="Invalid input!";

	//3
	if (score3 >= 90)
		grade3 = "A";
	else if (score3 >= 80)
		grade3 = "B";
	else if (score1 >= 70)
		grade3 = "C";
	else if (score3 >= 60)
		grade3 = "D";
	else if (score3 >= 0)
		grade3 = "F";
	else
		grade3 = "Invalid input!";

	//2
	if (score2 >= 90)
		grade2 = "A";
	else if (score2 >= 80)
		grade2 = "B";
	else if (score2 >= 70)
		grade2 = "C";
	else if (score2 >= 60)
		grade2 = "D";
	else if (score2 >= 0)
		grade2 = "F";
	else
		grade2 = "Invalid input!";


	//Output the grade
	cout << "The grade table is shown below: \n\n";
	cout << left << setw(30) << "Student" << "Grade\n";
	cout << "________________________________________\n";
	cout << setw(30) << name1 << grade1 << endl;
	cout << setw(30) << name2 << grade2 << endl;
	cout << setw(30) << name3 << grade3 << endl;
	cout << "________________________________________\n";

	return 0;

}