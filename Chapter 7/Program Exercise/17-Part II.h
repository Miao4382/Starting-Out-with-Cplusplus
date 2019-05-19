//17. Name Search Part II
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

void load_names(std::vector<std::string> &name_boy, std::vector<std::string> &name_girl);
void check(std::vector<std::string> name_database, std::string name);

int main()
{

	//create two vectors to store the name data base
	std::vector<std::string> name_boy, name_girl;

	//load names into the name database
	load_names(name_boy, name_girl);

	//input a name
	std::string name;
	std::cout << "Please input a name: ";
	std::cin >> name;

	//show menue: choose boy check or girl check
	char choice;
	std::cout << "Please choose one term below: \n";
	std::cout << "1. Boy's name check.\n2. Girl's name check.\n";
	std::cin >> choice;
	while (choice != '1'&&choice != '2')
	{
		std::cout << "Invalid choice, please choose 1 or 2:";
		std::cin >> choice;
	}

	//use check function to check
	switch (choice)
	{
	case '1': check(name_boy, name); break;
	case '2': check(name_girl, name); break;
	}

	return 0;

}

//name database
void load_names(std::vector<std::string> &name_boy, std::vector<std::string> &name_girl)
{
	std::string transfer;

	//file streamer: read
	std::ifstream cin;
	cin.open("D:\\name-boys.txt");

	while (cin >> transfer)
		name_boy.push_back(transfer);

	cin.close();
	cin.open("D:\\name-girls.txt");

	while (cin >> transfer)
		name_girl.push_back(transfer);
	cin.close();
}

//Chekc if name is inside the list
void check(std::vector<std::string> name_database, std::string name)
{
	int flag = true;
	for (int i = 0; i < name_database.size(); i++)
	{
		if (name == name_database[i])
		{
			std::cout << "This name is inside the 200 most popular names! It is ranked " << i + 1 << std::endl;
			flag = false;
			break;
		}
	}
	if (flag)
		std::cout << "This name is not in the 200 most popular names!\n";
}