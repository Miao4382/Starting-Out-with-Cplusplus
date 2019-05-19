//10. Driver's License Exam
#include<iostream>
#include<vector>

int main()
{
	char key[] = { 'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','C','C','A','D','B' };
	char answer[20];

	//input answer
	std::cout << "Please input user's 20 answers: \n";
	for (int i = 0; i < 20; i++)
	{
		std::cout << i + 1 << ": ";
		std::cin >> answer[i];
		while (answer[i] != 'A'&&answer[i] != 'B'&&answer[i] != 'C'&&answer[i] != 'D')
		{
			std::cout << "Please input A, B, C or D: ";
			std::cin >> answer[i];
		}
	}

	//check answer
	int right = 0;
	std::vector<int> wrong_question; //for storing wrong questions
	for (int i = 0; i < 20; i++)
	{
		if (answer[i] == key[i])
		{
			right++;
		}
		else
			wrong_question.push_back(i + 1);
	}

	//grade and show result analysis
	if (right >= 15)
		std::cout << "Congratulations! You passed the exam.\n";
	else
		std::cout << "Sorry, you failed the exam.\n";
	std::cout << "Total number of correct questions: " << right << std::endl;
	std::cout << "Total number of incorrect questions: " << 20 - right << std::endl;
	std::cout << "List of incorrect questions:\n";
	for (int i = 0; i < wrong_question.size(); i++)
		std::cout << wrong_question[i] << std::endl;

	return 0;

}