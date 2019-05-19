#include <iostream>
#include "Question.h"
#include <fstream>

const int SIZE = 10;

void initialize_text(std::string *q_text, std::string *a1_text, std::string *a2_text, std::string *a3_text, std::string *a4_text, int *correct_index); //initialize all question, answer text and correct index
void play(Question *questions, int &score_1, int &score_2);
void show_question(Question q, int &selection);

int main()
{
	//define containers for question, answer and correct index
	std::string q_text[SIZE];
	std::string a1_text[SIZE];
	std::string a2_text[SIZE];
	std::string a3_text[SIZE];
	std::string a4_text[SIZE];
	int correct_index[SIZE];
	//initialize these container
	initialize_text(q_text, a1_text, a2_text, a3_text, a4_text, correct_index);

	/* Define a Question object array and store value */
	Question questions[SIZE];
	//use a loop to set value in the array (each object)
	for (int i = 0; i < SIZE; i++)
	{
		questions[i].set_question(q_text[i]);
		questions[i].set_a1(a1_text[i]);
		questions[i].set_a2(a2_text[i]);
		questions[i].set_a3(a3_text[i]);
		questions[i].set_a4(a4_text[i]);
		questions[i].set_key(correct_index[i]);
	}

	/* Define player score, pass to play function */
	int score_1 = 0;
	int score_2 = 0;
	play(questions, score_1, score_2);

	/* Analyze result and show winner */
	//display score
	std::cout << "Player 1 got: " << score_1;
	std::cout << (score_1 > 1 ? " scores\n" : " score\n");
	std::cout << "Player 2 got: " << score_2;
	std::cout << (score_2 > 1 ? "scores\n" : " score\n");

	//display result
	if (score_1 == score_2)
		std::cout << "Player 1 and player 2 are draw\n";
	else if (score_1 > score_2)
		std::cout << "Player 1 win!\n";
	else
		std::cout << "Player 2 win!\n";

	return 0;
}

void initialize_text(std::string *q_text, std::string *a1_text, std::string *a2_text, std::string *a3_text, std::string *a4_text, int *correct_index) //initialize all question, answer text and correct index
{
	/* Create a file stream object */
	std::fstream file;
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\q_text.txt", std::ios::in);
	//fill q_text[]
	for (int i = 0; i < SIZE; i++)
		getline(file, q_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\a1_text.txt", std::ios::in);
	//fill a1_text
	for (int i = 0; i < SIZE; i++)
		getline(file, a1_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\a2_text.txt", std::ios::in);
	//fill a2_text
	for (int i = 0; i < SIZE; i++)
		getline(file, a2_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\a3_text.txt", std::ios::in);
	//fill a3_text
	for (int i = 0; i < SIZE; i++)
		getline(file, a3_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\a4_text.txt", std::ios::in);
	//fill a4_text
	for (int i = 0; i < SIZE; i++)
		getline(file, a4_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\correct_index.txt", std::ios::in);
	//fill correct_index
	for (int i = 0; i < SIZE; i++)
		file >> correct_index[i];
	//close file stream object
	file.close();
}

void play(Question *questions, int &score_1, int &score_2)
{
	int selection; //hold selection by different player

	/* Use a loop to go over 10 questions */
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
			std::cout << "Player 1 turn:\n";
		else
			std::cout << "Player 2 turn:\n";

		//show question and get selection
		show_question(questions[i], selection);

		//update score if correct, show correct answer if wrong
		if (selection == questions[i].get_key())
		{
			std::cout << "Correct!\n";

			if (i % 2 == 0)
				score_1++;
			else
				score_2++;
		}
		else
		{
			std::cout << "Wrong! Correct answer: " << static_cast<char>(questions[i].get_key() + 64) << "\n";
		}

		//press enter to continue
		std::cout << "Press enter to continue next turn...";
		std::cin.get();
		std::cout << "\n";
	}
}
//show question and prompt user to input 
void show_question(Question q, int &selection)
{
	char choice;
	std::cout << q.get_question() << "\n"
		<< "A) " << q.get_ans1() << "\n"
		<< "B) " << q.get_ans2() << "\n"
		<< "C) " << q.get_ans3() << "\n"
		<< "D) " << q.get_ans4() << "\n";
	std::cout << "Your choice: ";
	std::cin >> choice;
	while (!((choice >= 65 && choice <= 68) || (choice >= 97 && choice <= 100)))
	{
		std::cout << "Invalid choice, please input A, B, C or D: ";
		std::cin >> choice;
	}
	std::cin.ignore(); //skip '\n'

	switch (choice)
	{
	case 'A':
	case 'a':
		selection = 1; break;
	case 'B':
	case 'b':
		selection = 2; break;
	case 'C':
	case 'c':
		selection = 3; break;
	case 'D':
	case 'd':
		selection = 4; break;
	}
}