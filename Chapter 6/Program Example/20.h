//20. Local and Global Variable with the same name
#include<iostream>
//global variable definition
int num = 10;
void change_num();
int main()
{
	std::cout << "The num in main function is: " << num << std::endl;
	change_num();
	std::cout << "Back to main, the num is still " << num << std::endl;
	return 0;
}

void change_num()
{
	int num = 30;
	std::cout << "The num in another function is changed into " << num << "\n";
}