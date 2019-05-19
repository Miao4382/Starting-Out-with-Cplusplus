//8. Math Tutor 3.0 (enhanced edition)
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
int main()
{
	//variable definition
	double key, result, time0, time1, time_total = 0, accuracy_rate;
	double num1, num2; //num1, num2 are the random number used in math expression. Refreshed every iteration
	int problem_total = 0, problem_right = 0;
	int choice;
	unsigned seed;
	/*Variable Description:
	key:			right answer to the question
	result:			answer input by the user
	time0:			time when user see the problem on screen. Use this variable to calculate how much time the user cost on one problem
	time1:			time when user input the answer. time1-time0 is the time user spent on the problem
	time_total:		total time user spent on all problems
	accuracy_rate:	percentage of right problem
	num1:			first number in math expression. Random number.
	num2:			second number in math expression. Random number.
	problem_total:	total number of problems.
	problem_right:	total number of corrected problems.
	choice:			user's choice in menue
	seed:			seed number. To generate random number.*/

	//create a file stream operator and determine proper format
	std::ofstream cout;
	cout.open("D:\\8.txt");
	std::cout << std::setprecision(2) << std::fixed;

	//input the maximum and minimum number
	std::cout << "Welcome to Math Tutor 3.0. This program will help you train your math skill.\n";
	std::cout << "Please input the proper range of your exercise.\n\nWhat is the minimum number in your exercise: ";
	int N_min, N_max;
	std::cin >> N_min;
	std::cout << "What is the maximum number in your exercise: ";
	std::cin >> N_max;
	cout << "Math Tutor 3.0 report\n";
	cout << "Minimum number: " << N_min << std::endl;
	cout << "Maximum number: " << N_max << std::endl;


	do
	{
		//Adjust the format
		cout << std::setprecision(2) << std::fixed << std::left;

		//Show menue, input choice and check if the input is valid
		std::cout << "Please select one mode below, press 5 to quit the program.\n";
		std::cout << "1. Do a \"+\" problem.\n";
		std::cout << "2. Do a \"-\" problem.\n";
		std::cout << "3. Do a \"×\" problem.\n";
		std::cout << "4. Do a \"÷\" problem.\n";
		std::cout << "5. Quit.\n";
		std::cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
		{
			std::cout << "Invalid input, please input again: \n";
			std::cin >> choice;
		}

		//Print table head, tail
		if (choice != 5 && problem_total == 0) //at beginning, didn't quit, print a table head
		{
			cout << "\n" << std::setw(13) << "#" << std::setw(20) << "Problem" << std::setw(25) << "User Input Result" << std::setw(10) << "Key" << std::setw(16) << "Correct?" << std::setw(7) << "Time(s)\n";
			cout << "----------------------------------------------------------------------------------------------\n";
		}
		else if (choice == 5 && problem_total > 0) //already finished several problems, selected quit, print a table tail
			cout << "----------------------------------------------------------------------------------------------\n";
		else if (choice == 5 && problem_total == 0) //quit at beginning, print quit to txt file
			cout << "You quited the program before starting\n";
		else; //during an exercise, do nothing

			  //produce random number to be used in the following calculation
		seed = time(0);
		srand(seed);
		num1 = rand() % (N_max - N_min + 1) + N_min;
		num2 = rand() % (N_max - N_min + 1) + N_min;

		//gives the problem and decide correct or incorrect
		switch (choice)
		{
		case 1:
			problem_total++; //update the problem number
			std::cout << "You selected + exercise, press enter to begin.\n";
			std::cin.ignore();
			std::cin.get();
			std::cout << num1 << " + " << num2 << " = ?\n";
			time0 = time(0);
			cout << std::setw(5) << problem_total << std::setw(8) << std::right << num1 << " + " << std::setw(8) << std::left << num2 << std::setw(16) << " = ?";
			std::cin >> result;
			time1 = time(0);
			time_total += (time1 - time0);
			key = num1 + num2;
			cout << std::setw(18) << result << std::setw(13) << key;
			if (key == result)
			{
				problem_right++;
				cout << std::setw(15) << "1" << std::setw(4) << time1 - time0 << std::endl;
				std::cout << "Congratulations! You are correct. You spend " << time1 - time0 << " seconds on this problem.\n";
			}
			else
			{
				cout << std::setw(15) << "0" << std::setw(4) << time1 - time0 << std::endl;
				std::cout << "Sorry, you made a mistake, the correct answer is: " << key << ". You spend " << time1 - time0 << " seconds on this problem.\n";
			}
			std::cout << "\n\nPress enter to assume.\n";
			std::cin.ignore();
			std::cin.get();
			break;
		case 2:
			problem_total++; //update the problem number
			std::cout << "You selected - exercise, press enter to begin.\n";
			std::cin.ignore();
			std::cin.get();
			std::cout << num1 << " - " << num2 << " = ?\n";
			time0 = time(0);
			cout << std::setw(5) << problem_total << std::setw(8) << std::right << num1 << " - " << std::setw(8) << std::left << num2 << std::setw(16) << " = ?";
			std::cin >> result;
			time1 = time(0);
			time_total += (time1 - time0);
			key = num1 - num2;
			cout << std::setw(18) << result << std::setw(13) << key;
			if (key == result)
			{
				problem_right++;
				cout << std::setw(15) << "1" << std::setw(4) << time1 - time0 << std::endl;
				std::cout << "Congratulations! You are correct. You spend " << time1 - time0 << " seconds on this problem.\n";
			}
			else
			{
				cout << std::setw(15) << "0" << std::setw(4) << time1 - time0 << std::endl;
				std::cout << "Sorry, you made a mistake, the correct answer is: " << key << ". You spend " << time1 - time0 << " seconds on this problem.\n";
			}
			std::cout << "\n\nPress enter to assume.\n";
			std::cin.ignore();
			std::cin.get();
			break;
		case 3:
			problem_total++; //update the problem number
			std::cout << "You selected × exercise, press enter to begin.\n";
			std::cin.ignore();
			std::cin.get();
			std::cout << num1 << " × " << num2 << " = ?\n";
			time0 = time(0);
			cout << std::setw(5) << problem_total << std::setw(8) << std::right << num1 << " × " << std::setw(8) << std::left << num2 << std::setw(16) << " = ?";
			std::cin >> result;
			time1 = time(0);
			time_total += (time1 - time0);
			key = num1 * num2;
			cout << std::setw(18) << result << std::setw(13) << key;
			if (key == result)
			{
				problem_right++;
				cout << std::setw(15) << "1" << std::setw(4) << time1 - time0 << std::endl;
				std::cout << "Congratulations! You are correct. You spend " << time1 - time0 << " seconds on this problem.\n";
			}
			else
			{
				cout << std::setw(15) << "0" << std::setw(4) << time1 - time0 << std::endl;
				std::cout << "Sorry, you made a mistake, the correct answer is: " << key << ". You spend " << time1 - time0 << " seconds on this problem.\n";
			}
			std::cout << "\n\nPress enter to assume.\n";
			std::cin.ignore();
			std::cin.get();
			break;
		case 4:
			problem_total++; //update the problem number
			std::cout << "You selected ÷ exercise, press enter to begin.\n";
			std::cin.ignore();
			std::cin.get();
			std::cout << num1 << " ÷ " << num2 << " = ?\n";
			time0 = time(0);
			cout << std::setw(5) << problem_total << std::setw(8) << std::right << num1 << " ÷ " << std::setw(8) << std::left << num2 << std::setw(16) << " = ?";
			std::cin >> result;
			time1 = time(0);
			time_total += (time1 - time0);
			key = num1 / num2;
			cout << std::setw(18) << result << std::setw(13) << key;
			if (key == result)
			{
				problem_right++;
				cout << std::setw(15) << "1" << std::setw(4) << time1 - time0 << std::endl;
				std::cout << "Congratulations! You are correct. You spend " << time1 - time0 << " seconds on this problem.\n";
			}
			else
			{
				cout << std::setw(15) << "0" << std::setw(4) << time1 - time0 << std::endl;
				std::cout << "Sorry, you made a mistake, the correct answer is: " << key << ". You spend " << time1 - time0 << " seconds on this problem.\n";
			}
			std::cout << "\n\nPress enter to assume.\n";
			std::cin.ignore();
			std::cin.get();
			break;
		case 5:
			break;
		}

	} while (choice != 5);


	if (problem_total > 0)
	{
		//calculate accuracy
		accuracy_rate = static_cast<double>(problem_right) / problem_total;

		//print out report
		cout << "\n\nFinal Report:\n";
		cout << "Accuracy: " << accuracy_rate * 100 << "%" << std::endl;
		cout << "Total Time: " << time_total << " seconds.\n";
		cout << "Average Time per Problem: " << time_total / problem_total << " seconds.\n";
		std::cout << "You quited the program.Please check your report!\n";
		return 0;
	}

	cout.close(); //disconnect the link between cout and the file
	return 0;
}