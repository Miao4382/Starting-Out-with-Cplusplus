#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

//constant part of the letter: they won't change during the printing
//const char part1[] = "Dear ";
//const char part2[] = "Our records show that your account has a"
//" balance of $";
//const char part3[] = "and a past due amount of $";
//const char part4[] = "Your last payment was on ";
//const char part5[] = "Since we haven't heard from you in some"
//" time, would you please take a moment to send"
//" us a check for the past due amount? We value"
//" your business and look forward to serving you"
//" in the future.\n\n";
//const char part6[] = "Sincerely,\n";
//const char part7[] = "The Management\n\n";
//const char part8[] = "P.S. If you've already sent your payment, ignore"
//" this reminder.";

//function prototype
void strcpy2(char *destination, char *source);
void get_salutation(char *string);
void get_info(char *name, char *account_balance, char *past_due, char *date_last_pay);
void strcat2(char *string1, char *string2);
void get_path(char *name, char *account_balance, char *path);
void print_letter(char *path, char *salutation, char *name, char *account_balance, char *past_due, char *date_last_pay);

int main()
{
	//variable definition
	char salutation[5], name[50], date_last_pay[11];
	char account_balance[50], past_due[50];

	char choice; //to hold user's choice, if he wants or not continue

	do
	{
		//call get_salution function to fill the salutation array
		get_salutation(salutation);

		//call get_info function to fill the name, account balance, past due, data last payment
		get_info(name, account_balance, past_due, date_last_pay);

		//call path generator to generate a file path used to store the printed letter (txt)
		//the format of the name of the file should be "lastname, account balance.txt"
		//store the file in D:\lastname, account balance.txt
		char path[200];
		get_path(name, account_balance, path);

		//call print letter function to print a letter into the txt file
		print_letter(path, salutation, name, account_balance, past_due, date_last_pay);

		//ask for the user if he wants another run
		std::cout << "Do you want to print another letter (Y/N)";
		std::cin >> choice;
		while (tolower(choice) != 'y' && tolower(choice) != 'n')
		{
			std::cout << "Please input Y or N: ";
			std::cin >> choice;
		}
		std::cin.ignore(); //to skip the '\n'		

	} while (tolower(choice) == 'y');

	std::cout << "\nYou quitted.\n";

	return 0;


}

//string copy function
void strcpy2(char *destination, char *source)
{
	//copy content from source to destination
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}

//salutation input function
void get_salutation(char *string)
{
	//print menu and input choice
	char choice;
	std::cout << "Salutation:\n" << "\t1) Mr.\n" << "\t2) Ms. \n" << "Select one: ";
	std::cin >> choice;
	while (choice != '1' && choice != '2')
	{
		std::cout << "Invalid input, please select 1 or 2: ";
		std::cin >> choice;
	}

	//write content in salution array, based on the input
	if (choice == '1')
		strcpy2(string, "Mr. ");
	else
		strcpy2(string, "Ms. ");
}

//info input function
void get_info(char *name, char *account_balance, char *past_due, char *date_last_pay)
{
	//print hint
	std::cout << "Last name: ";
	std::cin.ignore(); //to ignore the \n created in the salutation input (using std::cin)
	std::cin.getline(name, 50);

	//account balance
	std::cout << "Account balance: ";
	std::cin.getline(account_balance, 50);

	//past due
	std::cout << "Past due amount: ";
	std::cin.getline(past_due, 50);

	//date_last_pay
	std::cout << "Date of last payment: ";
	std::cin.getline(date_last_pay, 50);

}

//string concatenate function, used to make the saving path of letter file
void strcat2(char *string1, char *string2)
{
	/* This function mimic the function of strcat, it can concatenate two strings. The first string is the container, the second string will be added to the end of the first string */

	//define a counter to find out the position where string1 ends (the '\0')
	int counter = 0;
	while (string1[counter] != '\0')
		counter++;
	//at this point, string1[counter] = '\0'

	int i = 0; //another counter to copy string2 to string 1
	while (string2[i] != '\0')
		string1[counter + i] = string2[i++];

	string1[counter + i] = '\0'; //add a null character at the end of the array

}

//get file path
void get_path(char *name, char *account_balance, char *path)
{
	//file path format: D:\\name, account_balance.txt
	//copy "D:\\" into the path
	strcpy2(path, "D:\\");
	//copy name into the path
	strcat2(path, name);
	//copy the ", "
	strcat2(path, ", ");
	//copy account balance
	strcat2(path, account_balance);
	//copy the ".txt"
	strcat2(path, ".txt");
}

//letter printing function
void print_letter(char *path, char *salutation, char *name, char *account_balance, char *past_due, char *date_last_pay)
{
	//initiate file streamer: write
	std::ofstream cout;
	cout.open(path);

	//define const char arrays
	char part1[] = "Dear ";
	char part2[] = "Our records show that your account has a"
		" balance of $";
	char part3[] = " and a past due amount of $";
	char part4[] = "Your last payment was on ";
	char part5[] = "Since we haven't heard from you in some"
		" time, would you please take a moment to send"
		" us a check for the past due amount? We value"
		" your business and look forward to serving you"
		" in the future.\n\n";
	char part6[] = "Sincerely,\n";
	char part7[] = "The Management\n\n";
	char part8[] = "P.S. If you've already sent your payment, ignore"
		" this reminder.";

	//Gather all the information to a new char array, so they can be printed together, and the process can be controlled
	char letter[1000];
	strcpy2(letter, part1);
	strcat2(letter, salutation);
	strcat2(letter, name);
	strcat2(letter, "\n\n");
	strcat2(letter, part2);
	strcat2(letter, account_balance);
	strcat2(letter, part3);
	strcat2(letter, past_due);
	strcat2(letter, ". ");
	strcat2(letter, part4);
	strcat2(letter, date_last_pay);
	strcat2(letter, ". ");
	strcat2(letter, part5);
	strcat2(letter, part6);
	strcat2(letter, part7);
	strcat2(letter, part8);
	//calculate the size of the letter.
	int size = strlen(letter);

	//start printing. The left and right margins: 10-character, perform word-warp
	int start_position = 0, line_counter = 0;
	while (letter[start_position + line_counter] != '\0')
	{
		if (line_counter == 0)
		{
			cout << "          "; //new line, left margins
			if (letter[start_position] == ' ')
				line_counter++; //If the first element is space, skip that
		}

		if (line_counter > 60 && letter[start_position + line_counter] == ' ')
		{
			cout << "          \n"; //end of a line, right margin
			start_position += line_counter; //update the start_position, this is done every time the function start a new line
			line_counter = 0; //started a new line, the line counter should be reset
			continue;
		}

		else if (letter[start_position + line_counter] == '\n')
		{
			cout << "          " << letter[start_position + line_counter]; //end of a line, right margin
			start_position += line_counter + 1; //the plus one is to bypass the '\n' character, otherwise this is an infinite loop (always stuck in '\n')
			line_counter = 0; //reset line_counter after a new line
			continue;
		}

		else
		{
			cout << letter[start_position + line_counter]; //if no new line, print the character at current position
			line_counter++; //update the line_counter
		}
	}

	//show complete info
	std::cout << "Printing complete. Letter is saved to: " << path << ". ";
	cout.close();

}

