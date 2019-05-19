#include <iostream>
#include <vector>
#include <fstream>

//function prototype
void read_data(std::vector<int> &win_lottery);
void search_prize(std::vector<int> win_lottery, std::vector<int> user_lottery, std::vector<int> &match);
void display_result(std::vector<int> match, std::vector<int> user_lottery);
void input_lottery(std::vector<int> &user_lottery);

int main()
{
	//define container
	std::vector<int> win_lottery, match, user_lottery;
	
	//use read_data function to read data and store into win_lottery
	read_data(win_lottery);
	
	//ask user to input lottery
	input_lottery(user_lottery);
	
	//call search prize function to find out if there is any lottery match
	search_prize(win_lottery, user_lottery, match);
	
	//display result
	display_result(match, user_lottery);
	
	return 0;
}

//read data
void read_data(std::vector<int> &win_lottery)
{
	std::ifstream cin;
	cin.open("D:\\8-2 data.txt");
	
	int transfer;
	while(cin >> transfer)
		win_lottery.push_back(transfer);
	
	cin.close();
}

//search winning lottery
void search_prize(std::vector<int> win_lottery, std::vector<int> user_lottery, std::vector<int> &match)
{
	/*
	A binary searching algorithm is used
	*/
	
	for(int i=0;i<user_lottery.size();i++)
	{
		int first = 0, last = win_lottery.size() - 1;
		
		do
		{
			int middle = (first+last)/2;
			if(user_lottery[i] == win_lottery[middle])
			{
				match.push_back(i);
				break;
			}
			else if (win_lottery[middle] > user_lottery[i])
			{
				last = middle - 1;
				continue;
			}
			else
			{
				first = middle + 1;
				continue;
			}
			
		} while (first <= last);
		
	}
	
}

//display result 
void display_result(std::vector<int> match, std::vector<int> user_lottery)
{
	if(match.size() == 0)
		std::cout << "No prizes.\n";
	else
	{
		std::cout << "Congratulations! Your following lotterys are the winning lottery:\n";
		for(int i=0;i<match.size();i++)
			std::cout << user_lottery[match[i]] << std::endl;
	}
}

//ask the user 1) how many lotteries to buy; 2) the number for each lottery
void input_lottery(std::vector<int> &user_lottery)
{
	int num, transfer;
	
	std::cout << "How many lotteries you want to purchase: ";
	std::cin >> num;
	while (num < 1)
	{
		std::cout << "Number should be equal or greater than one, please input again: ";
		std::cin >> num;
	}
	
	for(int i=0; i<num; i++)
	{
		std::cout << "What is the lottery number for lottery " << i+1 << ": ";
		std::cin >> transfer;
		while (transfer < 0)
		{
			std::cout << "Number should be equal or greater than zero, please input again: ";
			std::cin >> transfer;			
		}
		user_lottery.push_back(transfer);
	}
}
