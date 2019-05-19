//11. lowest Score Drop v2.00
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

//global variable: score storing path
std::string score_path="0";

void get_score(double &);
void calc_average();
void print_score_txt(double s1, double s2, double s3, double s4, double s5);

int main()
{
	double s1, s2, s3, s4, s5;
	get_score(s1);
	get_score(s2);
	get_score(s3);
	get_score(s4);
	get_score(s5);

	//save score to a txt file
	print_score_txt(s1,s2,s3,s4,s5);

	//calculate and print report
	calc_average();

	return 0;
}

//get score function
void get_score(double &score)
{
	std::cout << "Please input one of your five scores:\n";
	std::cin >> score;
	//input validity check
	while (score > 100 || score < 0)
	{
		std::cout << "Invalid input, please enter score in 0 ~ 100:\n";
		std::cin >> score;
	}
}

//average calculation function
void calc_average()
{
	//variable definition
	double average, total=0, low=100, score;
	int low_number;

	//create a file stream object
	std::ifstream cin;

	//enter storage path, you can either chose the file which is just inputed, or another file
	std::cout << "\nYou just inputed a set of scores, would you want to use them to calculate average score?: Y/N\n";
	char choice;
	std::cin >> choice;
		//input check
	while (choice != 'Y'&&choice != 'y'&&choice != 'n'&&choice != 'N')
	{
		std::cout << "Invalid input, please input Y or N:\n";
		std::cin >> choice;
	}
		//switch statement
	switch (choice)
	{
	case 'Y':
	case 'y':
		cin.open(score_path); break;
	case 'n':
	case 'N':
		std::cout << "Please input another file path:\n";
		std::cin.ignore();
		getline(std::cin, score_path);
		cin.open(score_path);
		while (!(cin >> score)|| !(cin >> score) || !(cin >> score) || !(cin >> score) || !(cin >> score)) //try to read five lines, this is to check whether the file contains less than five lines
		{
			cin.close();
			std::cout << "Unable to read the file, please re-input the file path:\n";
			getline(std::cin, score_path);
			cin.open(score_path);
		}
		cin.close();
		cin.open(score_path); //close and reopen, this is to re-initialize the read position
		break;
	}

	//create a file stream object, ready for inputing score data
	std::ofstream cout;
	cout.open("D:\\11-report.txt");
	cout << std::setprecision(2) << std::fixed;

	//print table head
	cout << "Lowest Score Drop Report\n"
		<< "--------------------------\n\n"
		<< "  Test" << "           Score\n"
		<< "--------------------------\n";
	//read the score, add them together and find the lowest
	for (int i = 1; i <= 5; i++)
	{
		cin >> score;
		total += score;
		if (low > score)
		{
			low = score;
			low_number = i;
		}

		cout << std::setw(5) << i << std::setw(17) << score << std::endl;
	}

	//print table tail
	cout << "--------------------------\n\n";

	//calculate average
	average = (total - low) / 4;

	//write the summary
	cout << "Summary:\n"
		<< "Lowest score is from test " << low_number << ", Score: " << low << std::endl;
	cout << "Average score after dropping the lowest score: " << average << std::endl;

	cout.close();

	std::cout << "Process complete. Please check the corresponding file for report.\n";
}

//write score to txt file function
void print_score_txt(double s1, double s2, double s3, double s4, double s5)
{
	//create a file stream object
	std::ofstream cout;

	//ask for storage path for score
	std::cout << "Enter the path of the file that will store the score:\n";
	std::cin.ignore();
	getline(std::cin, score_path);

	//open file, establish link
	cout.open(score_path);

	//write score in
	cout << s1 << std::endl;
	cout << s2 << std::endl;
	cout << s3 << std::endl;
	cout << s4 << std::endl;
	cout << s5 << std::endl;

	//close file
	cout.close();
}