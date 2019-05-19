//11. Exam Grader
#include<iostream>
#include<vector>
#include<fstream>

int main()
{
	//vector to store the key and answer
	std::vector<char> key;
	std::vector<char> answer;
	char transfer;

	//file read streamer
	std::ifstream cin;
	cin.open("D:\\correct answer.txt");

	//read data into key[]
	while (cin >> transfer)
		key.push_back(transfer);
	cin.close();

	//read data into answer[]
	cin.open("D:\\student answer.txt");
	while (cin >> transfer)
		answer.push_back(transfer);
	cin.close();

	//create a vector to store missed question
	std::vector<int> missed_question;

	//grade answer
	for (int i = 0; i < key.size(); i++)
	{
		if (answer[i] != key[i])
			missed_question.push_back(i);
	}

	//print out the question student missed
	std::cout << "Report:\n";
	std::cout << "Missed questions:\n";
	if (missed_question.size() == 0)
		std::cout << "No missed questions, you got them all!\n";
	else
	{
		for (int i = 0; i < missed_question.size(); i++)
		{
			std::cout << "Question " << missed_question[i] + 1 << ". Key: " << key[missed_question[i]] << ". Student answer: " << answer[missed_question[i]] << ".\n";
		}
		std::cout << "\n";
	}

	//print out total number of questions missed:
	std::cout << "Total number of questions missed: " << missed_question.size() << std::endl;

	//print out the percentage
	double percentage;
	percentage = (key.size() - missed_question.size()) / static_cast<double>(key.size()) * 100;
	std::cout << "The correct percentage is: " << percentage << "%\n";

	//show pass or fail
	if (percentage < 70)
		std::cout << "Sorry, ypu failed the exam.\n";
	else
		std::cout << "Congratulations, you passed the exam.\n";

	return 0;
}
