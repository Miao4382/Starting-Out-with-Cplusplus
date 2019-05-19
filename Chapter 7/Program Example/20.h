//7-20. Average Score
#include<iostream>
//function prototype
void get_score(double score[], int size);
void sum(double score[], int size, double &total);
double low(double score[], int size);

int main()
{
	const int NUM_EXAM = 4;
	double score[NUM_EXAM];

	//get score
	get_score(score, NUM_EXAM);

	//calculate total
	double total=0;
	sum(score, NUM_EXAM, total);

	//find the lowest score
	double lowest;
	lowest = low(score, NUM_EXAM);

	//calculate average
	double average;
	average = (total - lowest) / (NUM_EXAM - 1);

	//print out result
	std::cout << "The adjusted average score is: " << average << std::endl;

	return 0;

}

//get score function
void get_score(double score[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "What is the score for exam " << (i + 1) << ": ";
		std::cin >> score[i];
	}
}

//summation program, to get total score
void sum(double score[], int size, double &total)
{
	total = 0;
	for (int i = 0; i < size; i++)
		total += score[i];
}

//find lowest score
double low(double score[], int size)
{
	double low = score[0];
	for (int i = 1; i < size; i++)
	{
		if (low > score[i])
			low = score[i];
	}

	return low;
}
