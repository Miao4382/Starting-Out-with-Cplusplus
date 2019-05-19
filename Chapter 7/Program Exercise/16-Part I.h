//16-1. World Series Champions-extract all team name
#include<fstream>
#include<vector>
#include<string>
#include<iostream>

int main()
{
	//file streamer: read
	std::ifstream cin;
	cin.open("D:\\WorldSeriesWinners.txt");

	//vector to store name
	std::vector<std::string> team;
	
	//define a transfer variable
	std::string transfer;

	//read data in vector
	while (cin >> transfer)
	{
		cin.ignore(); //to ignore the blank between year number and team name
		bool flag = false; //flag is used to determine repeated input
		getline(cin, transfer);

		//checking if there is any repitition or blank or null
		for (int i = 0; i < team.size(); i++)
		{
			if (transfer == team[i]||transfer==" "||transfer=="")
			{
				flag = true;
				break;
			}

		}
		if (flag)
			continue;
		team.push_back(transfer);
	}
	cin.close();

	//write into a file
	std::ofstream cout;
	cout.open("D:\\Teams.txt");
	for (int i = 0; i < team.size(); i++)
		cout << team[i] << std::endl;
	cout.close();

	//user notification
	std::cout << "Process complete. The team name file has been created.\n";
	return 0;
}
