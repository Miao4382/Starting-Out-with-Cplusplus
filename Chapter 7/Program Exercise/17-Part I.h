//17. Name Search-Part I to get name list
#include <fstream>
#include <iostream>
#include <vector>
#include<string>

int main()
{
	//file streamer: read
	std::ifstream cin;
	cin.open("D:\\names.txt");

	//create a transfer
	std::string transfer;

	//create two vectors to store the name, the third is to remove extra characters
	std::vector<std::string> name_boy, name_girl, container;

	while (cin >> transfer)
	{
		//cin.ignore();
		//cin >> transfer;
		//name_boy.push_back(transfer);

		//cin.ignore();
		//cin >> transfer;
		//cin.ignore();
		//cin >> transfer;
		//cin.ignore();
		//cin >> transfer;

		//name_girl.push_back(transfer);

		//cin.ignore();
		//cin >> transfer;
		//cin.ignore();
		//cin >> transfer;
		cin.ignore();
		cin >> transfer;
		name_boy.push_back(transfer);
		cin.ignore(12);
		cin >> transfer;
		name_girl.push_back(transfer);
		cin.ignore(11);
	}
	cin.close();

	//file streamer: print
	std::ofstream cout;
	cout.open("D:\\name-boys.txt");

	//write names
	for (int i = 0; i < name_boy.size(); i++)
		cout << name_boy[i] << std::endl;
	cout.close();
	cout.open("D:\\name-girls.txt");
	for (int i = 0; i < name_girl.size(); i++)
		cout << name_girl[i] << std::endl;
	cout.close();

	return 0;
}
