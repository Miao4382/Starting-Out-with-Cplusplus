//24. Word Game
#include <iostream>
#include <string>

using namespace std;
int main()
{
	//variable definition
	string name, age, city, college, profession, animal, name_pet;

	//input
	cout << "Please input your name, age, city, college, profession, animal, name_pet.\n";
	getline(cin, name);
	getline(cin, age);
	getline(cin, city);
	getline(cin, college);
	getline(cin, profession);
	getline(cin, animal);
	getline(cin, name_pet);

	//output
	cout << "There once was a person named " << name << " who lived in " << city << ". At the age of \n";
	cout << age << ", " << name << " went to college at " << college << ". " << name << " graduated and went to work\n";
	cout << "as a " << profession << ". Then, " << name << " adopted a " << animal << " named " << name_pet << ". They\n";
	cout << "both lived happily ever after!\n";

	return 0;
}