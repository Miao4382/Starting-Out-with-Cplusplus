//13. Grade Book-modify
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

//constant data
const int NUM_STUDENT = 5, NUM_COURSE = 4;

//function prototype
void get_data(std::string name[NUM_STUDENT], double score[NUM_STUDENT][NUM_COURSE]);
void average_score(double score[NUM_STUDENT][NUM_COURSE], double average[NUM_STUDENT]);
char give_grade(double num); //pay attention, grade() function does not accept arrays

int main()
{
	//define array, score[][] is a 5x4 matrix, to store score for five students (4 course for each student), row is student number
	std::string name[NUM_STUDENT];
	double score[NUM_STUDENT][NUM_COURSE], average[NUM_STUDENT];
	char grade[NUM_STUDENT];

	//get data
	get_data(name, score);

	//average score
	average_score(score, average);

	//use a loop to find out the grade for each student
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		grade[i] = give_grade(average[i]);
	}

	//print out report
		//file streamer: print
	std::ofstream cout;
	cout.open("D:\\13_Grade Book Report.txt");

		//print table head
	cout << " Student Name        Average Score       Grade\n"
		<< "--------------------------------------------------\n";

		//table content, use a loop to finish
	for (int i = 0; i < NUM_STUDENT; i++)
	{
		cout << std::setw(13) << name[i] << std::setw(19) << average[i] << std::setw(11) << grade[i] << std::endl;
	}

		//table tail	
	cout << "--------------------------------------------------\n";
	cout.close();

	//notification
	std::cout << "Process completed, please check report.\n";
	return 0;
}

//get data function, get student name and their score
void get_data(std::string name[NUM_STUDENT], double score[NUM_STUDENT][NUM_COURSE])
{
	for (int counter_student = 0; counter_student < NUM_STUDENT; counter_student++)
	{
		std::cout << "Please input the name of student " << counter_student + 1 << ": ";
		
		//to get rid of the new line character after the first input
		if (counter_student != 0)
			std::cin.ignore();

		//get student name
		getline(std::cin, name[counter_student]);
		//use a loop to get student score
		for (int counter_course = 0; counter_course < NUM_COURSE; counter_course++)
		{
			std::cout << "Please input " << name[counter_student] << "'s score for exam " << counter_course + 1 << ": ";
			std::cin >> score[counter_student][counter_course];
			while (score[counter_student][counter_course] < 0 || score[counter_student][counter_course]>100)
			{
				std::cout << "Invalid input, please input again: ";
				std::cin >> score[counter_student][counter_course];
			}
		}
	}
}

//calculate average
void average_score(double score[NUM_STUDENT][NUM_COURSE], double average[NUM_STUDENT])
{
	for (int counter_student = 0; counter_student < NUM_STUDENT; counter_student++)
	{
		double total = 0, low=100;
		for (int counter_course = 0; counter_course < NUM_COURSE; counter_course++)
		{
			total += score[counter_student][counter_course];
			if (low > score[counter_student][counter_course])
				low = score[counter_student][counter_course];
		}
		average[counter_student] = (total-low) / (NUM_COURSE-1);
	}
}

//gives a grade according to student's average score
char give_grade(double num)
{
	if (num >= 90)
		return 'A';
	else if (num >= 80)
		return 'B';
	else if (num >= 70)
		return 'C';
	else if (num >= 60)
		return 'D';
	else
		return 'F';
}