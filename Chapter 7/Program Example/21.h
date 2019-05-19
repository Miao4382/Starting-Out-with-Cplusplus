//7-21. use 2D array to input score
#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>

int main()
{
	std::string score[3][4];
	int row = 3, column = 4;

	//get_score(score, 3, 4);
	for (int i = 0; i < row; i++)
	{
		std::cout << "What is the name for student " << (i + 1) << ": ";
		if(i!=0)
			std::cin.ignore();
		getline(std::cin, score[i][0]);
		for (int j = 1; j < column; j++)
		{
			std::cout << "What is the score for exam " << j << ": ";
			std::cin >> score[i][j];
		}
	}

	//file stream object
	std::ofstream cout("D:\\score report.txt");

	//write table head
	cout << "Student        Exam-1         Exam-2         Exam-3\n"
		<< "----------------------------------------------------\n";
	cout << std::left;

	//use a loop to write down result
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << std::setw(16) << score[i][j];
		}
		cout << std::endl;
	}

	//print table tail
	cout << "----------------------------------------------------\n";

	std::cout << "Processing complete...\n";
}

//question: how to pass 2D array into the function> how to define the parameter type?
////score input
//void get_score(std::string score[][], int row, int column)
//{
//	for (int i = 0; i < row; i++)
//	{
//		std::cout << "What is the name for student " << (i + 1) << ": ";
//		std::cin.ignore();
//		getline(std::cin, score[i][0]);
//		for (int j = 1; j < column; j++)
//		{
//			std::cout << "What is the score for exam " << j << ": ";
//			std::cin >> score[i][j];
//		}
//	}
//}