//16-2. World Series Champions
#include <iostream>
#include<fstream>
#include<vector>
#include<string>

//function prototype
void load_award_info(std::vector<std::string> &award_database);
void load_team_info(std::vector<std::string> &team_list);
void input_name(std::string &team_name, std::vector<std::string> team_list);
void check_match(std::string team_name, std::vector<std::string> &matches, std::vector<std::string> award_database);

int main()
{
	std::vector<std::string> award_database, team_list, matches;
	std::string team_name; //to hold user inputed team name
	char choice; //to hold the choice user makes

	//load award information into a vector
	load_award_info(award_database);

	//load team information into a vector and display on screen
	load_team_info(team_list);

	do
	{
		//input team name and check
		input_name(team_name, team_list);

		//to check how many times of matching occur
		check_match(team_name, matches, award_database);

		//show number of times of winning and also which year
		std::cout << "This team has won " << matches.size();
		std::cout<< (matches.size() > 1 ? " times " : " time ") << "from " << award_database[0] << " to " << award_database[award_database.size() - 2] << ". The years are:\n";
		for (int i = 0; i < matches.size(); i++)
			std::cout << matches[i] << std::endl;

		//show choice menue
		std::cout << "\nDo you want to check another team? (Y/N) ";
		std::cin >> choice;
	} while (choice != 'N'&&choice != 'n');

	if (choice == 'N' || choice == 'n')
		std::cout << "You quited.\n";

	return 0;

}

//load award information into a vector
void load_award_info(std::vector<std::string> &award_database)
{
	std::string transfer; //used as transfer medium
	
	//file streamer: read
	std::ifstream cin;
	cin.open("D:\\WorldSeriesWinners.txt");

	//read and load information to the vector
	while (cin >> transfer)
	{
		award_database.push_back(transfer); //to store the year information
		cin.ignore(); //to skip blank
		getline(cin, transfer);
		if (transfer == " " || transfer == "")
			award_database.pop_back(); //if there is no team name read (for year 1904, 1994), delete the year inputed
		else
			award_database.push_back(transfer); //record the name if any name is read
	}

	//close file
	cin.close();
}

//load team information into a vector
void load_team_info(std::vector<std::string> &team_list)
{
	std::string transfer;
	
	//file streamer: read
	std::ifstream cin;
	cin.open("D:\\Teams.txt");

	//show hint
	std::cout << "Please pick up a team below and check their achievements!\n\n";

	//read and load team in the vector, also print the name on screen
	while (getline(cin, transfer))
	{
		team_list.push_back(transfer);
		std::cout << transfer << std::endl;
	}
}

//input a team name and check if the name is within the team name list
void input_name(std::string &team_name, std::vector<std::string> team_list)
{
	bool flag = true;
	do
	{
		std::cout << "\n\nPlease input a team name: ";
		//std::cin.ignore();
		getline(std::cin, team_name);

		//use an iteration to check if inputed team name is within the list
		for (int i = 0; i < team_list.size(); i++)
		{
			if (team_name == team_list[i])
			{
				flag = false;
				break;
			}
		}

		//show correct information and continue
		if (flag)
			std::cout << "You should input team name from the above list.\n";

	} while (flag);

}

//check how many times of match
void check_match(std::string team_name, std::vector<std::string> &matches, std::vector<std::string> award_database)
{
	matches.clear();
	for (int i = 0; i < award_database.size(); i++)
	{
		if (team_name == award_database[i])
			matches.push_back(award_database[i - 1]);
	}
}