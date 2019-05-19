//8-1. Linear Search+ (search scores that are less than a certain value, then return all matches)
#include <iostream>
#include <vector>

void search_list(double score[], int score_num, double value, std::vector<int> &matches);

int main()
{
	//initialize a score list
	double score[] = { 59.6, 81.5, 61, 44.5, 85, 91, 81.3, 71.6, 54 };

	//create a vector to store the subscript of records that matches
	std::vector<int> matches;

	//call search_list function, to find all scores below 60. After this step, subscripts will be stored in matches vector
	search_list(score, 9, 60, matches);

	//print out all value that apply
	if (matches.size() != 0)
	{
		std::cout << "Exam ";
		for (int i = 0; i < matches.size(); i++)
			std::cout << matches[i] + 1 << " " ;
		std::cout << " has a score lower than 60.\n";
	}

}

void search_list(double score[], int score_num, double value, std::vector<int> &matches)
{
	for (int i = 0; i < score_num; i++)
	{
		if (score[i] < value)
			matches.push_back(i);
	}
}