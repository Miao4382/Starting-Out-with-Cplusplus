/* Chapter 10 */

/*********************/
/***Program Example***/
/*********************/



10-1. Demonstrating basic usage of character-testing functions
{

Code
{

#include <iostream>
#include <cctype>

int main()
{
	//prompt user to enter a character
	std::cout << "To enter a character, this program will analyze it: ";
	char letter;
	std::cin.get(letter);
	letter = 1;
	if(isprint(letter))
	{
		if(isalnum(letter))
		{
			if(isalpha(letter))
			{
				if(islower(letter))
					std::cout << "This is a lower case letter.\n";
				else
					std::cout << "This is a upper case letter.\n";
			}
			else
			{
				if(isdigit(letter))
					std::cout << "This is a digit.\n";
				else
					std::cout << "This is nothing!\n";
			}			
		}
		else
		{
			if(isspace(letter))
				std::cout << "This is a whitespace character.\n";
			else
			{
				if(ispunct(letter))
					std::cout << "This is a punctuation!\n";
				else
					std::cout << "This is nothing!\n";
			}
		}
	}
	else
	{
		if(isspace(letter))
			std::cout << "This is a whitespace character.\n";
		else
			std::cout << "This is a non-printable character\n";
	}
	
	return 0;
}

}

}

10-2. Determine the input format using character testing function
{

1) problem analysis
Write a program that can finish following tasks:
> ask user to enter a seven char employee number. Notify the format: LLLnnnn (L-upper case letter, N-numbers)
> check if the user enters the right number:
	> check if user entered seven character, less than seven and more than seven is illegal
	> check if the first three characters are upper case letter
	> check if the last four characters are digits
> notify the user if she entered the right format

2) gadget tweak
2-1) char array input trial. write a function that can ask the user input one line character and then store them into a vector.
Code:
{

#include <iostream>
#include <vector>

int main()
{
	std::vector<char> letters;

	std::cout << "Please input several letters: ";
	char letter;

	while (std::cin.get(letter) && letter != '\n') //only cin.get() function can get '\n'
		letters.push_back(letter);

	//print out letters
	for (int i = 0; i < letters.size(); i++)
		std::cout << letters[i] << std::endl;

	return 0;
}

}

3) Code
{

#include <iostream>
#include <vector>
#include <cctype>

void get_data(std::vector<char> &letters);

int main()
{
	//define a vector and call a function to receive input
	std::vector<char> letters;
	get_data(letters);
	
	//print the result (get_data function already filtered the illegal input)
	std::cout << "Your empoyee number: ";
	for (int i=0; i<letters.size(); i++)
		std::cout << letters[i];
	std::cout << " is valid.\n";
	
	return 0;

}

void get_data(std::vector<char> &letters)
{
	std::cout << "Please input your employee number (The employee number should start with three uppercase letters and followed by four digits.)\n";
	
	char letter;

	//define a flag
	bool illegal;	
	
	do
	{
		illegal = false;
		//input the letter
		while (std::cin.get(letter) && letter != '\n')
			letters.push_back(letter);
		
		if (letters.size() != 7)
		{
			letters.clear();
			std::cout << "The employee number should have 7 characters, please re-input: ";
			illegal = true;
			continue;
		}
		
		//check first three letters
		if (!(isupper(letters[0])&&isupper(letters[1])&&isupper(letters[2])))
		{
			letters.clear();
			std::cout << "The first three characters in employee number should be upper case letter. Please re-input: ";
			illegal = true;
			continue;
		}
		
		//check the remaining digits
		for (int i=3; i<letters.size(); i++)
			if (!(isdigit(letters[i])))
			{
				letters.clear();
				std::cout << "The last four characters should be digits, please re-input: ";
				illegal = true;
				break;
			}
	} while (illegal);

}


}


}

10-3. Use of toupper or tolower function
{

1) problem analysis
Design a circle area calculation program. After calculating, ask the user if he wants to continue or not. Use toupper function to transform the input.

2) Code
{

#include <iostream>
#include <cctype>

int main()
{
	const double PI = 3.1415926;
	double radius; //define radius
	char choice; //define a variable to store user's choice
	
	do
	{
		std::cout << "What is the radius of the circle: ";
		std::cin >> radius;
		std::cout << "The area is: " << PI*radius*radius << "\n";
		std::cout << "Would you want to do another calculation? (Y/N)";
		std::cin >> choice;
		while (toupper(choice)!='Y' && toupper(choice)!='N')
		{
			std::cout << "Please input Y or N: ";
			std::cin >> choice;
		}
	} while (toupper(choice) == 'Y');
	
	std::cout << "You quitted.\n";
	
	return 0;
}

}


}

10-4. Print string literal on the screen
{

Code
{

#include <iostream>
int main()
{
	std::cout << "Patience and hope.\n";
	return 0;
}

}

}

10-5. Use std::cin.getline() member function to input a C-string, store in a char array and then display the content (till the null terminator)
{

1) Usage of getline member function
char letters[20];
std::cin.getline(letters, 20);

2) Code
{

#include <iostream>

int main()
{
	const int SIZE = 50;
	char sentence[SIZE];

	//prompt the user to input
	std::cout << "Please input sencences, the total character number should not exceed " << SIZE - 1 << ".\nOtherwise, your sentence will be cut at the tail.\n";
	std::cin.getline(sentence, 20);

	//print out the inputted data
	int counter = 0;
	while (sentence[counter] != '\0')
		std::cout << sentence[counter++];
	std::cout << "\n";

	return 0;
}

}

}

/* Concatenate function */
/* strcat2 */
//The original concatenate function is not working, I wrote another one to achieve the similar function
Code:
{

#include <iostream>

void strcat2(char *string1, const char *string2);

int main()
{
	char sentence1[100] = "abcde";
	char sentence2[50] = " efgfasdsjd asd";

	strcat2(sentence1, sentence2);

	int i = 0;
	while (sentence1[i] != '\0')
		std::cout << sentence1[i++];
	std::cout << "\n";

	return 0;
}

void strcat2(char *string1, const char *string2)
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

}

/* Copy function */
/* strcpy2 */
//The original copy function is not working, I wrote another one to achieve the similar function
Code:
{

#include <iostream>

void strcpy2(char *destination, const char *source);

int main()
{
	char string1[10] = "ABCDEFG";
	char string2[10] = "avcd";

	std::cout << "Before copying: " << string1 << "\n";

	strcpy2(string1, string2);

	std::cout << "After copying: " << string1 << std::endl;

	return 0;
}

void strcpy2(char *destination, const char *source)
{
	//first, clear what ever is inside the destination array
	//int i = 0;
	//while (destination[i] != '\0')
		//destination[i++] = '\0';
	/* Pay attention, this code may cause stack-based buffer overrun! I had this problem when I write the case study!! It will display: stack around the variable 'salutation' was corrupted. */

	//second, copy content from source to destination
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}

}

/* Safe Concatenate Function */
/* strncat */
//safer version of concatenate function, it has third argument specifying maximum characters being operated (not including the last null character)
Code:
{

#include <iostream>
#include <cstring>

void strncat2(char *string1, const char *string2, int num);

int main()
{
	char sentence1[9] = "abcde";
	char sentence2[50] = " efgfasdsjd asd";

	int max_char = sizeof(sentence1) - (strlen(sentence1) + 1);
	strncat2(sentence1, sentence2, max_char);

	int i = 0;
	while (sentence1[i] != '\0')
		std::cout << sentence1[i++];
	std::cout << "\n";
	return 0;
}

void strncat2(char *string1, const char *string2, int num)
{
	/* This function mimic the function of strcat, it can concatenate two strings. The first string is the container, the second string will be added to the end of the first string */

	//define a counter to find out the position where string1 ends (the '\0')
	int counter = 0;
	while (string1[counter] != '\0')
		counter++;
	//at this point, string1[counter] = '\0'

	int i = 0; //another counter to copy string2 to string 1
	while (string2[i] != '\0' && i < num)
		string1[counter + i] = string2[i++];

	string1[counter + i] = '\0'; //add a null character at the end of the array

}

}

/* Safe Copy Function */
/* strncpy */
//safer version 
 copy function, it has third argument specifying maximum characters being operated (not including the last null character)
Code:
{

#include <iostream>

void strncpy2(char *destination, const char *source, int num);

int main()
{
	char string1[10] = "ABCDEFG";
	char string2[11] = "avcdsdsswqw";

	std::cout << "Before copying: " << string1 << "\n";

	strncpy2(string1, string2, 3);

	std::cout << "After copying: " << string1 << std::endl;

	return 0;
}

void strncpy2(char *destination, const char *source, int num)
{
	//first, clear what ever is inside the destination array
	int i = 0;
	while (destination[i] != '\0')
		destination[i++] = '\0';

	//second, copy content from source to destination
	i = 0;
	while (source[i] != '\0' && i < num)
		destination[i] = source[i++];
	destination[i] = '\0';
}


}

/* String Search Function */
/* strstr */
//My Visual Studio seems compatible with this function, here I just want to treat it as an exercise
Code:
{

#include <iostream>

char *strstr2(char *array, char *keyword);
using namespace std;

int main()
{
	char arr[] = "Four score and seven years ago";
	char *strPtr = nullptr;
	cout << arr << endl;
	strPtr = strstr2(arr, "our"); // search for "seven"
	if (strPtr != nullptr)
		cout << strPtr << endl;
	else
		cout << "Not found!\n";
	return 0;
}

char *strstr2(char *array, char *keyword)
{
	//count of the number of character in keyword and array
	int size_keyword = 0, size_array = 0;
	while (keyword[size_keyword++] != '\0');
	while (array[size_array++] != '\0');
	size_array--;
	size_keyword--; //the null character should not be included in the string.
	//now the size of keyword and array is known
	for (int i = 0; i<(size_array - size_keyword + 1); i++)
	{
		int j;
		for (j = 0; j<size_keyword; j++)
			if (!(array[i + j] == keyword[j]))
				break;
		if (j == size_keyword)
			return &array[i];
	}
	//after the outter for loop, no match can be found, return nullptr
	return nullptr;

}

}


10-6. Use strstr function to search keywords
{

1) problem analysis
make a product data base so the user can search for the production information, only by typing the product name, and the description will come upper
The product data base has following structure. It is a (m x n) matrix, m is the number of product, n is the length of characters in each product description. The definition of product data base is:
const int NUM_PRODS = 5, LENGTH = 30;
char products[NUM_PRODS][LENGTH] = { "TV327 31-inch TV", 
									   "CD257 CD Player", 
									   "TA677 Ansering Machine",
									   "CS109 Car Stereo", 
									   "PC955 Personal Computer" };
When searching the array, strstr function will be used. The target searching array is the product database, while the keyword is a C-string input by user (the member function of cin : cin.getline() will be used to input the data).
The starting address of the keyword (if there is any) is returned

2) Code
{

#include <iostream>
#include <cstring>

char *strstr2(char *array, char *keyword);

int main()
{
	//create a product data base 
	const int NUM_PRODS = 5, LENGTH = 30;
	char products[NUM_PRODS][LENGTH] = { "TV327 31-inch TV",
		"CD257 CD Player",
		"TA677 Ansering Machine",
		"CS109 Car Stereo",
		"PC955 Personal Computer" };
	//ask user to input a keyword to search
	char keyword[LENGTH];
	std::cout << "Please input a keyword to search:\n";
	std::cin.getline(keyword, LENGTH);

	//use the string search function to search for record
	char *record = nullptr; //define a char pointer to store the result of searching
		//use a loop to go over all the rows of product database
	for (int i = 0; i < NUM_PRODS; i++)
	{
		record = strstr2(products[i], keyword); //although products is defined as a 2D array, here only uses its first dimension index
		if (record != nullptr)
			break;
	}

	//print out result
	if (record != nullptr)
		std::cout << record << std::endl;
	else
		std::cout << "No records found!\n";

	return 0;
}

//test my string searching function
char *strstr2(char *array, char *keyword)
{
	//count of the number of character in keyword and array
	int size_keyword = 0, size_array = 0;
	while (keyword[size_keyword++] != '\0');
	while (array[size_array++] != '\0');
	size_array--;
	size_keyword--; //the null character should not be included in the string.
					//now the size of keyword and array is known
	for (int i = 0; i<(size_array - size_keyword); i++)
	{
		int j;
		for (j = 0; j<size_keyword; j++)
			if (!(array[i + j] == keyword[j]))
				break;
		if (j == size_keyword)
			return &array[i];
	}
	//after the outter for loop, no match can be found, return nullptr
	return nullptr;
}

}


}

/* String Compare Function */
/* strcmp */
//My Visual Studio seems compatible with this function, here I just want to treat it as an exercise
Code:
{

#include <iostream>

int strcmp2(char *string1, char *string2);

int main()
{
	char string1[10] = "abac", string2[10] = "aba";
	std::cout << strcmp2(string1, string2) << std::endl;
	return 0;
}

//the string compare function
int strcmp2(char *string1, char *string2)
{
	int i = 0;
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] > string2[i])
			return 1;
		else if (string1[i] < string2[i])
			return -1;
		else
			i++;
	}

	//after the while loop, one of the string come to end,check the final result
	if (string1[i] == string2[i])
		return 0;
	else if (string1[i] > string2[i])
		return 1;
	else
		return -1;
}

}

/* String Compare Function (case insensitive) */
/* stricmp2 */
//try to work out the case insensitive version of string compare function
//since the toupper and tolower function is included in cctype header file, I have to write them first so user don't have to include cctype header file
Code:
{

#include <iostream>

int stricmp2(char *string1, char *string2);

int main()
{
	char string1[100], string2[100];
	//prompt the user to input string
	std::cout << "Please input first string: ";
	std::cin.getline(string1, 100);
	std::cout << "Please input the second string: ";
	std::cin.getline(string2, 100);
	
	//call the strcmp2 function to compare these two strings
	int result; //to hold the result
	result = stricmp2(string1, string2);
	
	//print result according to the feedback
	if(result == 0)
		std::cout << "Two strings are the same.\n";
	else if (result > 0)
		std::cout << "First string comes after the second string.\n";
	else
		std::cout << "First string comes before the second string.\n";
	
	return 0;
}

//the string compare function (case insensitive)
int stricmp2(char *string1, char *string2)
{
	//first, copy string1 and string2, then transform any upper case letter to lower case letter before comparing. Using copy so the original string won't be altered.
		//calculate the size of string1 and string2
	int size1 = 0, size2 = 0;
	while (string1[size1++] != '\0');
	while (string2[size2++] != '\0');
	
		//request two memory spaces to hold string1 and string2
	char *string1_copy = new char [size1];
	char *string2_copy = new char [size2];
		//copy string1 and string2, during the copy check if the specific character is upper case letter, if so, copy the equivalent lower case character in the copied string
	for(int i=0; i<size1; i++)
	{
		if (string1[i] >= 65 && string1[i] <= 90)
			string1_copy[i] = string1[i] + 32;
		else
			string1_copy[i] = string1[i];
	}

	for(int i=0; i<size2; i++)
	{
		if (string2[i] >= 65 && string2[i] <= 90)
			string2_copy[i] = string2[i] + 32;
		else
			string2_copy[i] = string2[i];		
	}
	
	//compare the transformed copy string
	int i = 0;
	while (string1_copy[i] != '\0' && string2_copy[i] != '\0')
	{
		if (string1_copy[i] > string2_copy[i])
			return 1;
		else if (string1_copy[i] < string2_copy[i])
			return -1;
		else
			i++;
	}

	//after the while loop, one of the string come to end,check the final result
	if (string1_copy[i] == string2_copy[i])
		return 0;
	else if (string1_copy[i] > string2_copy[i])
		return 1;
	else
		return -1;
	
	//after the task, free the dynamically allocated memory to avoid memory leak
	delete[] string1_copy;
	delete[] string2_copy;
	
}

}


10-7. Use strcmp function to test string equality
{

1) Problem analysis
first, ask the user to input two strings, and then use strcmp function to compare the equality of the two string

2) Code:
{

#include <iostream>

int strcmp2(char *string1, char *string2);

int main()
{
	char string1[100], string2[100];
	//prompt the user to input string
	std::cout << "Please input first string: ";
	std::cin.getline(string1, 100);
	std::cout << "Please input the second string: ";
	std::cin.getline(string2, 100);
	
	//call the strcmp2 function to compare these two strings
	int result; //to hold the result
	result = strcmp2(string1, string2);
	
	//print result according to the feedback
	if(result == 0)
		std::cout << "Two strings are the same.\n";
	else if (result > 0)
		std::cout << "First string comes after the second string.\n";
	else
		std::cout << "First string comes before the second string.\n";
	
	return 0;
}

//the string compare function
int strcmp2(char *string1, char *string2)
{
	int i = 0;
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] > string2[i])
			return 1;
		else if (string1[i] < string2[i])
			return -1;
		else
			i++;
	}

	//after the while loop, one of the string come to end,check the final result
	if (string1[i] == string2[i])
		return 0;
	else if (string1[i] > string2[i])
		return 1;
	else
		return -1;
}

}

}

10-8. Price lookup system
{

1) problem analysis
make a price lookup system, the user will input the part number, the function will show the price of the part. It is like search by full name, not like the strstr example (in that example, you can input "partially" keyword, the program will show you the search result that matches the keyword). In this program, result is shown only if the user enters the right part name.

	a) how to arrange the data base?
	I'll first create two corresponding array to store data base info, first array is to store the part number, second array is to store the price
	
2) Code
{

#include <iostream>

int stricmp2(char *string1, char *string2);

int main()
{
	//initialize a data base
	const int PRO_NUM = 5, NAME_NUM = 20;
	char part_name[PRO_NUM][NAME_NUM] = {"PT-1", "PT-2", "PT-3", "PT-4", "PT-5"};
	char part_price[PRO_NUM][NAME_NUM] = {"$ 15", "$ 20", "$ 25", "$ 30", "$ 35"};
	
	//prompt the user to input info
	std::cout << "Please input the part name: ";
	char keyword[NAME_NUM];
	std::cin.getline(keyword, NAME_NUM);
	
	//go over the array to search
	int found = 0;
	for(int i=0; i<PRO_NUM; i++)
	{
		if(stricmp2(part_name[i], keyword) == 0)
		{
			std::cout << "The price is " << part_price[i] << std::endl;
			found = 1;
			break;
		}					
	}
	
	//print out the result
	if(found == 0)
		std::cout << "No matches found!\n";
	
	return 0;
}

//the string compare function (case insensitive)
int stricmp2(char *string1, char *string2)
{
	//first, copy string1 and string2, then transform any upper case letter to lower case letter before comparing. Using copy so the original string won't be altered.
		//calculate the size of string1 and string2
	int size1 = 0, size2 = 0;
	while (string1[size1++] != '\0');
	while (string2[size2++] != '\0');
	
		//request two memory spaces to hold string1 and string2
	char *string1_copy = new char [size1];
	char *string2_copy = new char [size2];
		//copy string1 and string2, during the copy check if the specific character is upper case letter, if so, copy the equivalent lower case character in the copied string
	for(int i=0; i<size1; i++)
	{
		if (string1[i] >= 65 && string1[i] <= 90)
			string1_copy[i] = string1[i] + 32;
		else
			string1_copy[i] = string1[i];
	}

	for(int i=0; i<size2; i++)
	{
		if (string2[i] >= 65 && string2[i] <= 90)
			string2_copy[i] = string2[i] + 32;
		else
			string2_copy[i] = string2[i];		
	}
	
	//compare the transformed copy string
	int i = 0;
	while (string1_copy[i] != '\0' && string2_copy[i] != '\0')
	{
		if (string1_copy[i] > string2_copy[i])
			return 1;
		else if (string1_copy[i] < string2_copy[i])
			return -1;
		else
			i++;
	}

	//after the while loop, one of the string come to end,check the final result
	if (string1_copy[i] == string2_copy[i])
		return 0;
	else if (string1_copy[i] > string2_copy[i])
		return 1;
	else
		return -1;
	
	//after the task, free the dynamically allocated memory to avoid memory leak
	delete[] string1_copy;
	delete[] string2_copy;
	
}

}

}

10-9. Sort names
{

1) problem analysis
	> read names from a txt file and store in a char array.
	> sort the names in alphabetical order, use the selection sorting and stricmp function (as the relational operator)
	> store the sorted array in another file
	
2) Code
{

#include <iostream>
#include <fstream>

int stricmp2(char *string1, char *string2);
char **load_name();
void selection_sort(char **names);

int main()
{
	//call a function to load in data to a char array
	char **names = nullptr; //define an array of pointer to hold the address of name array 
	names = load_name(); //each row is one name, each column is the characters in each name. If you print names[i], the name on i-th row will be printed, if you print *names[i], this will just print out the content stored in address names[i] (the first address in each row, thus the first letter in each row)

						 //call a function to sort the names
	selection_sort(names);

	//write the sorted array into another txt file
	std::ofstream cout;
	cout.open("D:\\names-sorted.txt");
	for (int i = 0; i<20; i++)
		cout << names[i] << std::endl;
	cout.close();

	//notify completion
	std::cout << "The operation completed.\n";

	return 0;
}

//the string compare function (case insensitive)
int stricmp2(char *string1, char *string2)
{
	//first, copy string1 and string2, then transform any upper case letter to lower case letter before comparing. Using copy so the original string won't be altered.
	//calculate the size of string1 and string2
	int size1 = 0, size2 = 0;
	while (string1[size1++] != '\0');
	while (string2[size2++] != '\0');

	//request two memory spaces to hold string1 and string2
	char *string1_copy = new char[size1];
	char *string2_copy = new char[size2];
	//copy string1 and string2, during the copy check if the specific character is upper case letter, if so, copy the equivalent lower case character in the copied string
	for (int i = 0; i<size1; i++)
	{
		if (string1[i] >= 65 && string1[i] <= 90)
			string1_copy[i] = string1[i] + 32;
		else
			string1_copy[i] = string1[i];
	}

	for (int i = 0; i<size2; i++)
	{
		if (string2[i] >= 65 && string2[i] <= 90)
			string2_copy[i] = string2[i] + 32;
		else
			string2_copy[i] = string2[i];
	}

	//compare the transformed copy string
	int i = 0;
	while (string1_copy[i] != '\0' && string2_copy[i] != '\0')
	{
		if (string1_copy[i] > string2_copy[i])
			return 1;
		else if (string1_copy[i] < string2_copy[i])
			return -1;
		else
			i++;
	}

	//after the while loop, one of the string come to end,check the final result
	if (string1_copy[i] == string2_copy[i])
		return 0;
	else if (string1_copy[i] > string2_copy[i])
		return 1;
	else
		return -1;

	//after the task, free the dynamically allocated memory to avoid memory leak
	delete[] string1_copy;
	delete[] string2_copy;

}

//load name function
char **load_name()
{
	//create a file streamer: read and link to the names.txt file
	std::ifstream cin;
	cin.open("D:\\names.txt");

	//count the number of names in the txt file
	int size = 0;
	char name[100]; //this array is used to temporarily hold names read from file when counting the size of names.txt, names are not likely more than 100 characters
	while (cin.getline(name, 100))
		size++;
	cin.close();
	cin.open("D:\\names.txt"); //to re-initialize the read position

							   //the size of the total names are acquired, now request memory space to make a new 2D array so that the names can be read and stored from file
	char **name_ptr = new char *[size]; //define an array of pointers, each pointer is one row in the vitual array. You have to use a loop to define the 
	for (int i = 0; i<size; i++)
	{
		name_ptr[i] = new char[100]; //for each row, request a memory address to hold the name stored in that row
		cin.getline(name_ptr[i], 100); //to store names in the array
	}

	//after the for loop, names are loaded into the array of pointer, return the address
	return name_ptr;

}

//selection sorting function
void selection_sort(char **names)
{
	//first, decide the size
	int size = 0;
	std::ifstream cin("D:\\names.txt");
	char name[100];
	while (cin.getline(name, 100))
		size++;
	cin.close();

	//use selection sorting to sort the array
	int start_scan = 0;
	do
	{
		char *min_ptr = names[start_scan];
		int min_index = start_scan;

		for (int i = start_scan; i<size; i++)
			if (stricmp2(min_ptr, names[i]) == 1)
			{
				min_index = i;
				min_ptr = names[i];
			}

		//exchange
		names[min_index] = names[start_scan];
		names[start_scan] = min_ptr;

		//update the start_scan location
		start_scan++;
	} while (start_scan < size - 1);

	//after this, the names array (pointer array) has been sorted


}

}

}

10-10. (Checkpoint: use of strstr)
{

1) problem analysis
search for the string "Windy" in the array place. If match found, the program display "Windy found", otherwise it will display "Windy not found";

2) Code
{

#include <iostream>
#include <cstring>

int main()
{
	char place[] = "The Windy City";
	char *result = nullptr;
	result = strstr(place, "Windy");
	
	if(result == nullptr)
		std::cout << "Windy not found.\n";
	else
		std::cout << "Windy found.\n";
	
	return 0;
}

}

}

/* string to integer function */
/* atoi2 */
/* My compiler can work with this, Write this for practice */
/* Function:
	1) "22234" -> 22234
	2) "221a23* -> 221, only numbers before the letter will be transferred. 
	3) "ahg221" -> 0. If first character is not number, return 0. */
Code:
{

#include <iostream>

int atoi2(char *string);

int main()
{
	std::cout << atoi2("s") << std::endl;
	return 0;
}

//the letter to integer function
int atoi2(char *string)
{
	//decide how many digit in the string
	int counter = 0;
	while (string[counter] <= 57 && string[counter] >= 48 && string[counter] != '\0')
		counter++;
	//after the loop, the counter records the number of digit in the string
	//now transfer the character to digit
	int transfer = 0;
	for (int i = 0; i<counter; i++)
	{
		transfer *= 10;
		transfer += string[i] - 48;
	}

	//after the loop, the transfer has been transformed to digit
	return transfer;
}

}

/* string to long function */
/* atol2 */
/* My compiler can work with this, Write this for practice */

Code:
{

#include <iostream>

long atoi2(char *string);

int main()
{
	std::cout << atoi2("s") << std::endl;
	return 0;
}

//the letter to integer function
long atoi2(char *string)
{
	//decide how many digit in the string
	int counter = 0;
	while (string[counter] <= 57 && string[counter] >= 48 && string[counter] != '\0')
		counter++;
	//after the loop, the counter records the number of digit in the string
	//now transfer the character to digit
	long transfer = 0;
	for (int i = 0; i<counter; i++)
	{
		transfer *= 10;
		transfer += string[i] - 48;
	}

	//after the loop, the transfer has been transformed to digit
	return transfer;
}

}

/* string to double function */
/* atof2 */
/* My compiler can work with this, Write this for practice */
/* Function:
	1) "22234" -> 22234
	2) "221a23* -> 221, only numbers before the letter will be transferred. 
	3) "ahg221" -> 0. If first character is not number, return 0. */
Code:
{

#include <iostream>

double atof2(char *string);

int main()
{
	char number[] = "12.542s.03.54ss";
	std::cout << atof2(number) << std::endl;

	return 0;
}

//alphabet to double numbers
double atof2(char *string)
{
	//count the number of digit before '.' or anyother symbol
	int counter_1 = 0, counter_2 = 0;
	while (*(string + counter_1) >= 48 && *(string + counter_1) <= 57 && *(string + counter_1) != '\0')
		counter_1++;
	//at this point, the counter_1 is the number of digit before other character, check the very first character after digit, if it is '.', continue counting digit after '.', if it's not '.', finish counting
	if (string[counter_1] == '.') //when there is dot
	{
		while (string[counter_1 + 1 + counter_2] >= 48 && string[counter_1 + 1 + counter_2] <= 57 && string[counter_1 + 1 + counter_2] != '\0')
			counter_2++;
		//after the loop, counter_2 is the number of digits after the dot (fractional part), now go over the string and calculate the actual number
		double num1 = 0, num2 = 0; //num1 is for number before dot, num2 is after
								   //calculate num1
		for (int i = 0; i<counter_1; i++)
		{
			num1 *= 10;
			num1 += string[i] - 48;
		}
		//calculate num2
		for (int i = counter_2 - 1; i >= 0; i--)
		{
			num2 /= 10;
			num2 += (string[counter_1 + 1 + i] - 48) / 10.0;
		}
		//calculate the final number and return
		return num1 + num2;
	}

	else //no fraction part, return 
	{
		double num = 0;
		for (int i = 0; i<counter_1; i++)
		{
			num *= 10;
			num += string[i] - 48;
		}
		return num;
	}

}


}

/* number to string function */
/* to_string2 */
/* Make an alternative version of to_string function, it will transfer numeric numbers to C-string */
Code (for 9 overload function)
{

1) accepts unsigned int //can't handle numbers that the last digit is zero (can be divided by 10), check 4) for the updated version
Code:
{

#include <iostream>

char *to_c_string(unsigned num);

int main()
{
	std::cout << to_c_string(1234) << "\n";
	return 0;
}

//int version of to_c_string function
char *to_c_string(unsigned num)
{
	//when num == 0
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}
	
	//figure out how long is the number
	unsigned num_copy = num;
	int size = 0;
	while (num_copy % 10 != 0)
	{
		num_copy /= 10;
		size++;
	}
	size -= 1;

	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)
	//now, you need to request a memory space to store the string. The size should be size+2.
	char *string = new char[size + 2];

	//to get the divide digit
	int digit = 1;
	for (int i = 0; i<size; i++)
		digit *= 10;
	//to transform the number to string
	int i = 0;
	for ( i = 0; i <= size; i++)
	{
		string[i] = num / digit + 48;
		num %= digit;
		digit /= 10;
	}
	string[i] = '\0';
	//return address of the string
	return string;

}
 
}

2) accepts unsigned long value //can't handle numbers that the last digit is zero (can be divided by 10), check 4) for the updated version
Code:
{

#include <iostream>

char *to_c_string(unsigned long num);

int main()
{
	std::cout << to_c_string(1234) << "\n";
	return 0;
}

//int version of to_c_string function
char *to_c_string(unsigned long num)
{
	//when num == 0
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}
	
	//figure out how long is the number
	unsigned long num_copy = num;
	int size = 0;
	while (num_copy % 10 != 0)
	{
		num_copy /= 10;
		size++;
	}
	size -= 1;

	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)
	//now, you need to request a memory space to store the string. The size should be size+2.
	char *string = new char[size + 2];

	//to get the divide digit
	int digit = 1;
	for (int i = 0; i<size; i++)
		digit *= 10;
	//to transform the number to string
	int i = 0;
	for ( i = 0; i <= size; i++)
	{
		string[i] = num / digit + 48;
		num %= digit;
		digit /= 10;
	}
	string[i] = '\0';
	//return address of the string
	return string;

}

}

3) accepts unsigned long long value //can't handle numbers that the last digit is zero (can be divided by 10), check 4) for the updated version
Code:
{

#include <iostream>

char *to_c_string(unsigned long long num);

int main()
{
	std::cout << to_c_string(1234) << "\n";
	return 0;
}

//int version of to_c_string function
char *to_c_string(unsigned long long num)
{
	//when num == 0
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}
	
	//figure out how long is the number
	unsigned long long num_copy = num;
	int size = 0;
	while (num_copy % 10 != 0)
	{
		num_copy /= 10;
		size++;
	}
	size -= 1;

	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)
	//now, you need to request a memory space to store the string. The size should be size+2.
	char *string = new char[size + 2];

	//to get the divide digit
	int digit = 1;
	for (int i = 0; i<size; i++)
		digit *= 10;
	//to transform the number to string
	int i = 0;
	for ( i = 0; i <= size; i++)
	{
		string[i] = num / digit + 48;
		num %= digit;
		digit /= 10;
	}
	string[i] = '\0';
	//return address of the string
	return string;

}

}

4) accepts int //this version can handle, focus on the part that counts the size of the number
Code:
{

#include <iostream>

char *to_c_string(int num);

int main()
{
	std::cout << to_c_string(0) << "\n";
	return 0;
}

//int version of to_c_string function
char *to_c_string(int num)
{
	//when num == 0
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}

	//if the number is not zero
	//figure out how long is the number
	int num_copy;
	if (num < 0)
		num_copy = -num; //if number is negative, first calculate the absolute value.
	else
		num_copy = num;

	int size = 0;
	
	if (num_copy % 10 == 0 && num_copy >= 10) //to prevent cases like 10, 20, 12320 (the last digit is zero)
		num_copy++; //add one to the num_copy, so following algorithm can be used to calculate the number of digits
	
	while (num_copy % 10 != 0)
	{
		num_copy /= 10;
		size++;
	}
	size -= 1;

	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)
	//now, you need to request a memory space to store the string. The size should be size+2.
	int additional_lot;
	if (num < 0)
		additional_lot = 3;
	else
		additional_lot = 2;

	char *string = new char[size + additional_lot];

	//to get the divide digit
	int digit = 1;
	for (int i = 0; i<size; i++)
		digit *= 10;

	//to transform the number to string
	int i;
	num_copy = num;
	if (num < 0)
	{
		for (i = 1; i <= size + 1; i++)
		{
			string[i] = -num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[0] = '-'; //place the negative sign in front of the string 
		string[i] = '\0';
		//return address of the string
		return string;
	}
	else
	{
		for (i = 0; i <= size; i++)
		{
			string[i] = num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[i] = '\0';
		//return address of the string
		return string;
	}


}

}

5) accepts long //can't handle numbers that the last digit is zero (can be divided by 10), check 4) for the updated version
Code:
{

#include <iostream>

char *to_c_string(long num);

int main()
{
	std::cout << to_c_string(-32234) << "\n";
	return 0;
}

//int version of to_c_string function
char *to_c_string(long num)
{
	//when num == 0
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}
	//figure out how long is the number
	long num_copy;
	if (num < 0)
		num_copy = -num; //if number is negative, first calculate the absolute value.
	else
		num_copy = num;

	int size = 0;
	while (num_copy % 10 != 0)
	{
		num_copy /= 10;
		size++;
	}
	size -= 1;

	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)
	//now, you need to request a memory space to store the string. The size should be size+2.
	int additional_lot;
	if (num < 0)
		additional_lot = 3;
	else
		additional_lot = 2;

	char *string = new char[size + additional_lot];

	//to get the divide digit
	int digit = 1;
	for (int i = 0; i<size; i++)
		digit *= 10;

	//to transform the number to string
	int i;
	num_copy = num;
	if (num < 0)
	{
		for (i = 1; i <= size + 1; i++)
		{
			string[i] = -num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[0] = '-'; //place the negative sign in front of the string 
		string[i] = '\0';
		//return address of the string
		return string;
	}
	else
	{
		for (i = 0; i <= size; i++)
		{
			string[i] = num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[i] = '\0';
		//return address of the string
		return string;
	}


}

}

6) accepts long long //can't handle numbers that the last digit is zero (can be divided by 10), check 4) for the updated version
Code:
{

#include <iostream>

char *to_c_string(long long num);

int main()
{
	std::cout << to_c_string(-32234) << "\n";
	return 0;
}

//int version of to_c_string function
char *to_c_string(long long num)
{
	//when num == 0
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}
	
	//figure out how long long is the number
	long long num_copy;
	if (num < 0)
		num_copy = -num; //if number is negative, first calculate the absolute value.
	else
		num_copy = num;

	int size = 0;
	while (num_copy % 10 != 0)
	{
		num_copy /= 10;
		size++;
	}
	size -= 1;

	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)
	//now, you need to request a memory space to store the string. The size should be size+2.
	int additional_lot;
	if (num < 0)
		additional_lot = 3;
	else
		additional_lot = 2;

	char *string = new char[size + additional_lot];

	//to get the divide digit
	int digit = 1;
	for (int i = 0; i<size; i++)
		digit *= 10;

	//to transform the number to string
	int i;
	num_copy = num;
	if (num < 0)
	{
		for (i = 1; i <= size + 1; i++)
		{
			string[i] = -num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[0] = '-'; //place the negative sign in front of the string 
		string[i] = '\0';
		//return address of the string
		return string;
	}
	else
	{
		for (i = 0; i <= size; i++)
		{
			string[i] = num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[i] = '\0';
		//return address of the string
		return string;
	}


}

}

7) accepts double //I had a very serious problem when trying to count the number of digits in the double number. Since the data of double type is not accurately stored in the computer, you can't use the algorithm presented in this code, thus the loop will continue forever, unable to get the result
Code:
{

#include <iostream>

char *to_c_string(double num);

int main()
{
	std::cout << to_c_string(1.1234) << "\n";
	return 0;
}

//double version of to_c_string function
char *to_c_string(double num)
{
	//when num == 0, just make an array with '0' and '\0'
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}

	//figure out how long is the number
	//int part
	int num_copy_int;
	if (num < 0)
		num_copy_int = -num; //if number is negative, first calculate the absolute value.
	else
		num_copy_int = num;

	int size_int = 0;
	while (num_copy_int % 10 != 0)
	{
		num_copy_int /= 10;
		size_int++;
	}
	if (size_int > 0)
		size_int -= 1;
	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)

	//decimal part
	double num_copy_double;
	if (num < 0)
		num_copy_double = -(num - static_cast<int>(num));
	else
		num_copy_double = num - static_cast<int>(num);

	int size_double = 0;
	while (num_copy_double != (static_cast<int>(num_copy_double * 10) / 10))
	{
		size_double++;
		num_copy_double *= 10;
		std::cout << size_double << "\n";
	}
	//after the while loop, size_double is the number of digits that are in the decimal part

	//now, you need to request a memory space to store the string. The size should be the size of integer part + size of decimal part + negative sign (if any) + the ending '\0' + the dot
	int additional_lot;
	if (num < 0)
		additional_lot = 3; // corresponds to '-', '.' and '\0'
	else
		additional_lot = 2; //corresponds to '.' and '\0'

	int size = (size_int + 1) + size_double + additional_lot;
	char *string = new char[size];

	//to get the divide digit (for integer transformation)
	int digit = 1;
	for (int i = 0; i<size_int; i++)
		digit *= 10;

	//to transform the number to string
	//int part
	int i;

	if (num < 0)
	{
		//initialize the number_copy
		num_copy_int = -static_cast<int>(num);
		num_copy_double = -(num - static_cast<int>(num));

		for (i = 1; i <= size_int + 1; i++)
		{
			string[i] = num_copy_int / digit + 48;
			num_copy_int %= digit;
			digit /= 10;
		}
		string[0] = '-'; //place the negative sign in front of the string

		if (num_copy_double != 0) //if the decimal part is not zero
		{
			//decimal part
			string[i] = '.'; //place the dot after the last digit of integer
			for (i = i + 1; i<size - 1; i++)
			{
				num_copy_double *= 10;
				string[i] = static_cast<int>(num_copy_double) + 48;
				num_copy_double -= static_cast<int>(num_copy_double);
			}
			//last null character
			string[i] = '\0';
			return string;
		}
		else //if the decimal part is zero, just return it
		{
			string[i] = '\0';
			return string;
		}

	}

	else //if the number is greater than zero
	{
		//initialize the number_copy
		num_copy_int = static_cast<int>(num);
		num_copy_double = num - static_cast<int>(num);

		for (i = 0; i <= size_int; i++)
		{
			string[i] = num_copy_int / digit + 48;
			num_copy_int %= digit;
			digit /= 10;
		}

		if (num_copy_double != 0) //if the decimal part is not zero
		{
			//decimal part
			string[i] = '.'; //place the dot after the last digit of integer
			for (i = i + 1; i<size - 1; i++)
			{
				num_copy_double *= 10;
				string[i] = static_cast<int>(num_copy_double) + 48;
				num_copy_double -= static_cast<int>(num_copy_double);
			}
			//last null character
			string[i] = '\0';
			return string;
		}
		else //if the decimal part is zero, just return it
		{
			string[i] = '\0';
			return string;
		}


	}


}

}

8) 9) : Unable to work out a proper way to count the number of digits in the double data type

}


10-10. Practice (using string to number conversion function, atoi; also the string compare function strcmp)
{

1) problem analysis
Ask the user to input a series of numbers, the user can input Q or q to quit. After the user choses to quit, print out the average of the numbers

2) Code:
{

#include <iostream>
#include <cstdlib>
#include <cctype>

int main()
{
	const int DIGIT = 6;
	char input[DIGIT]; //to hold user's input
	int total = 0, num = 0;

	//ask for the first input
	std::cout << "Please input the first number: ";
	std::cin.getline(input, DIGIT);
	//check if the input is valid (number)
	while (strcmp(input, "00000") < 0 || strcmp(input, "99999") > 0)
	{
		std::cout << "Invalid input, please input numbers: ";
		std::cin.getline(input, DIGIT);
	}
	total += atoi(input);
	num++;

	//use a loop to repeat until user choose to quit (input Q or q)
	do
	{
		std::cout << "Please input number " << num + 1 << "\n";
		std::cin.getline(input, DIGIT);
		if (tolower(input[0]) == 'q')
			break;
		//continue if the first characteristic letter is not Q or q
		while (strcmp(input, "00000") < 0 || strcmp(input, "99999") > 0)
		{
			std::cout << "Please input numbers: ";
			std::cin.getline(input, DIGIT);
		}
		total += atoi(input);
		num++;
	} while (tolower(input[0]) != 'q');

	std::cout << "The average is: " << static_cast<double>(total) / num << "\n";

	return 0;


}

}

}

10-11. Demonstrate how the cin.getline function can be used to accept any input of the program. 
{

This can prevent the "new line error", that if you input some data by cin, and then you input data by cin.getline (or getline), the second input won't be successful because the object will encounter the new line character, thus stops reading. You can bypass this by:
1) use cin.ignore() to skip the new line character
2) use getline function (or subfunction) to input data, and transform the data into the data type you want

Code:
{

#include <iostream>
#include <cstdlib>

int main()
{
	int num;
	char name[20];


	std::cout << "Input the ID number.\n";
	std::cin.getline(name, 20);
	num = atoi(name);

	std::cout << "Input the name: \n";
	std::cin.getline(name, 20);

	std::cout << "Number: " << num << "\n";
	std::cout << "Name: " << name << std::endl;

	return 0;
}


}


}

10-12. Write a string copy function (already did that)

10-13. name_slice function.
{

1) problem analysis
User is asked to input name, in the following format:
First_name Last_name
The program will search the inputted data for a space, and replace it with '\0', so the name is "sliced" in middle

2) Code
{

#include <iostream>

void name_slice(char *name);

int main()
{
	const int NAME_SIZE = 100;
	char name[NAME_SIZE];
	
	std::cout << "Please input your full name: ";
	std::cin.getline(name, NAME_SIZE);
	
	std::cout << "Your name is: " << name << std::endl;
	name_slice(name);
	std::cout << "Your sliced name is: " << name << std::endl;
	
	return 0;
}

void name_slice(char *name)
{
	int counter = 0;
	while (name[counter] != ' ' && name[counter++] != '\0');
	name[counter] = '\0';
}

}


}

10-14. count_string function
{

1) problem analysis
write a function which receives the address of a C-string, and a string, it searches the number of times this string repeats in the target string, and then return the value.

This is similar with the strstr function, that function will search a string in another string, and return the address of the first match. Here, however, this function should return the total number of matches.

2) Code:
{

#include <iostream>

int count_string(char *string, char *keyword);

int main()
{
	char string[] = "abcabacab82ahbabababa8bab";
	char keyword[] = "ab";
	int num_repeat = count_string(string, keyword);

	std::cout << "Number of repeats: " << num_repeat << std::endl;
	return 0;
}

int count_string(char *string, char *keyword)
{
	int num_repeat = 0;

	//count the length of the string
	int size_string = 0;
	while (string[size_string] != '\0')
		size_string++;
	//count the length of the keyword
	int size_key = 0;
	while (keyword[size_key] != '\0')
		size_key++;

	int start_scan = 0;
	while (start_scan <= size_string - size_key)
	{
		int i;
		for (i = 0; i<size_key; i++)
			if (string[start_scan + i] != keyword[i])
				break;
		if (i == size_key) //if i == size_key, there is a match
		{
			num_repeat++; //increase match counter
			start_scan += i; //update the start scan position
			continue; //begin a new search
		}
		start_scan++; //update the start_scan position
	}

	return num_repeat;
}

}

}

Case Study: String Manipulation (word warp and fixed line length printing)
{

1) problem analysis
write a letter print program. It can change some slots in the letter and ask user to input the content they want to add in those slots.

2) code:
{

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



}

}

10-15. Demonstrate C++ string class (definition and print on screen)
{

#include <iostream>
#include <string>

int main()
{
	std::string str("this is a C++ string");
	std::cout << str << "\n";

	return 0;
}

}

10-16. Use cin object to input a string
{

#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;
	std::cout << str << "\n";

	return 0;
}

}

10-17. Use == operator to compare different strings
{

#include <iostream>
#include <string>

int main()
{
	std::string str1, str2("12345");
	std::cin >> str1;
	if (str1 == str2)
		std::cout << "Yes! You're correct!" << "\n";
	else
		std::cout << "No! You're wrong.\n";

	return 0;
}

}

10-18. Use relational operators to sort strings
{

#include <iostream>
#include <string>

int main()
{
	std::string str1, str2;
	std::cout << "Input two strings and I will sort it in alphabetical order. "
		<< "\nInput string 1: ";
	getline(std::cin, str1);
	std::cout << "Input string 2: ";
	getline(std::cin, str2);
	if (str1 >= str2)
		std::cout << "The sorted strings are: \n" << str2 << "\n" << str1 << "\n" ;
	else
		std::cout << "The sorted strings are: \n" << str1 << "\n" << str2 << "\n";


	return 0;
}

}

10-19. Initialize a string
{

std::string str("abcde"); //define a string str, its content is abcde
std::string str(str1); //define a string str, its content is str1 (copy str1 to str)
std::string str(str1, 5); //define a string str, its content is the first five characters in str1
std::string str(str1, a, b); //define a string str, its content is the a-th to (a+b)-th character in str1. a is the starting reading position, and b is the length of the copy
std::string str('5', 10); //define a string str, its content is 10 '5'


}

10-20. Show some string operators
{

string operators are >>, <<, =, +=, + and [] //pay attention, no minus operator!

}

10-21. Demonstrate string length member function
{

#include <iostream>
#include <string>

int main()
{
	std::string full_name("Yu Miao");
	std::string first_name(full_name, 3, 3);
	full_name = full_name + first_name;
	std::cout << full_name << "\n";
	std::cout << full_name.length() << "\n"; //pay attention that the length function is slightly different from the vector size function. vecter.size() is the total number of slots, while string.length() is the total number of characters (not including the null character)
	//also, string object has a size member function, string.size(), although it looks like vector size() function, it works the same as length(), which will return the length of the string


	return 0;
}

}

10-22. Demonstrate string size() member function
{

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string full_name("Yu Miao");
	std::string first_name(full_name, 3, 3);
	full_name = full_name + first_name + first_name;
	std::cout << full_name << "\n";
	std::cout << full_name.size() << "\n";


	return 0;
}

} 

10-23. Case study: develop a function named dollar_format that inserts commas and a $ sign at the appropriate locations in a string object containing an unformatted dollar amount.
{

1) problem analysis
The function should accept a reference to a string object, so it can change it directly.

2) Code
{

#include <iostream>
#include <string>

void dollar_format(std::string &dollar);

int main()
{
	std::string dollar = "12345678.235";
	std::cout << "Before formatting: " << dollar << std::endl;
	dollar_format(dollar);
	std::cout << "After formatting: " << dollar << std::endl;
}

//format function
void dollar_format(std::string &dollar)
{
	//first, find out the number of characters stored in the dollar string
	int size = dollar.size();

	//find out the digit right after the dot (searching backward)
	int position = 0;
	while (dollar[size - 1 - position] != '.')
		position++;
	//when the above loop ends, dollar[size-1-position] == '.'
	int digit_counter = 0; //use to count number of jumping, every three times of jumping, insert a comma
	while (size - 1 - position >= 0)
	{
		if (digit_counter == 3)
		{
			dollar.insert(size - 1 - position, ",");
			digit_counter = 0; //reset the digit counter
		}

		position++;
		digit_counter++;
	}
	//after the above loop, comma is in position, and position = size, insert a '$' at dollar[size-position]
	dollar.insert(size - position, "$");

}


}

3) modified code: using more string member functions, also considering situation that there is no dot.
{

#include <iostream>
#include <string>

void dollar_format(std::string &dollar);

int main()
{
	std::string dollar = "12345678.235";
	std::cout << "Before formatting: " << dollar << std::endl;
	dollar_format(dollar);
	std::cout << "After formatting: " << dollar << std::endl;
}

//format function
void dollar_format(std::string &dollar)
{
	int dot_position = dollar.find("."); //find out the subscript for the dot
	
	if (dot_position == -1)
		dot_position = dollar.size(); //if there is no dot, pretend the dot is after the last digit
	
	//insert the comma
	for (int i=dot_position-3; i>0; i -= 3)
		dollar.insert(i, ",");
	
	//insert the '$' at the beginning
	dollar.insert(0, "$");		

}


}


}


/****************************/
/***Programming Challenges***/
/****************************/

1. String length
{

#include <iostream>

int strlen2(char *string);

int main()
{
	char array[20] = "12345";
	std::cout << strlen2(array);
	return 0;	
}

//string length function
int strlen2(char *string)
{
	int counter = 0;
	while (string[counter++] != '\0'); //after this loop, counter will go beyond '\0', the increment operator will effect even the expression is false
	return counter-1;
}

}

2. Backward string
{

#include <iostream>
#include <cstring>

void str_back_print(char *string);

int main()
{
	char array[20] = "12345";
	str_back_print(array);
	return 0;	
}

//backward print function
void str_back_print(char *string)
{
	for (int i = strlen(string)-1; i>=0; i--)
		std::cout << string[i];
	std::cout << std::endl;
	
}



}

3. Word Counter
{

1) problem analysis
before counting the number of words, the array should be dealt with:
	a) no double spaces should occur
	b) the first slot should not be space
	c) the last slot should not be space
	d) only one space is between two words
Copy the array to do these stuff

2) Code
{

#include <iostream>
#include <string>

int word_counter(char *sentence);
int word_counter(std::string array);

int main()
{
	char sentence[100] = "Arnold H. Glasgow, an American humorist, once said, \"The key to everything is patience. You get the chicken by hatching the egg, not by smashing it.\"";
	std::cout << "The sentence:\n" << sentence << "\nThe sentence contains: " << word_counter(sentence) << " words.\n";
	
	return 0;
}

//char array version
int word_counter(char *sentence)
{
	//copy a string to do some pre-work
	std::string array = sentence;
	
	//delete all repeated spaces
	for (int i=0; i<array.size(); i++)
	{
		if (array[i] == ' ' && array[i+1] == ' ')
		{
			array.erase(i, 1); //delete i-th spaces
			i--; //after deleting the i-th slot, the content after i-th will move forward 1 length, to fill the i-th slot, so you have to push back the reading position, so you won't miss any repeated spaces. Also, pay attention that the array size is dynamically changing
		}

	}
	
	//check if the first and last element in the string is space
	if (array[0] == ' ')
		array.erase(0, 1); //erase the first space
	if (array[array.size()-1] == ' ')
		array.erase(array.size()-1, 1); //erase the last space
	
	//now the array is ready for counting number of words. Assume every two words are separated by a space, the first and last element is word, so the number of words is number of space + 1
	int num = 0;
	for (int i=0; i<array.size(); i++)
		if (array[i] == ' ')
			num++;
	
	return num+1;
		
}

//string class object version
int word_counter(std::string array)
{	
	//here the string is only passed by value, so you don't have to copy the string
	//delete all repeated spaces
	for (int i=0; i<array.size(); i++)
	{
		if (array[i] == ' ' && array[i+1] == ' ')
		{
			array.erase(i, 1); //delete i-th spaces
			i--; //after deleting the i-th slot, the content after i-th will move forward 1 length, to fill the i-th slot, so you have to push back the reading position, so you won't miss any repeated spaces. Also, pay attention that the array size is dynamically changing
		}

	}
	
	//check if the first and last element in the string is space
	if (array[0] == ' ')
		array.erase(0, 1); //erase the first space
	if (array[array.size()-1] == ' ')
		array.erase(array.size()-1, 1); //erase the last space
	
	//now the array is ready for counting number of words. Assume every two words are separated by a space, the first and last element is word, so the number of words is number of space + 1
	int num = 0;
	for (int i=0; i<array.size(); i++)
		if (array[i] == ' ')
			num++;
	
	return num+1;	
}

}


}

4. Modify 3, also shows the average number of a word
{

1) problem analysis
You have to calculate the number of letters in the sentence, which means you have to pick up only letter. Use character testing function to finish this. Calculate the number of letters first, then divided by the total number of words, you'll get average number of letters per word.

2) Code
{

#include <iostream>
#include <string>
#include <cctype>

int word_counter(char *sentence);
int word_counter(std::string array);

int main()
{
	char sentence[200] = "   Arnold H. Glasgow, an      American humorist,      once said, \"The key to everything      is patience. You get the chicken by hatching the egg, not by smashing it.\"";
	std::cout << "The sentence:\n" << sentence << "\nThe sentence contains: " << word_counter(sentence) << " words.\n";

	return 0;
}

//char array version
int word_counter(char *sentence)
{
	//copy a string to do some pre-work
	std::string array = sentence;

	//delete all repeated spaces
	for (int i = 0; i<array.size(); i++)
	{
		if (array[i] == ' ' && array[i + 1] == ' ')
		{
			array.erase(i, 1); //delete i-th spaces
			i--; //after deleting the i-th slot, the content after i-th will move forward 1 length, to fill the i-th slot, so you have to push back the reading position, so you won't miss any repeated spaces. Also, pay attention that the array size is dynamically changing
		}

	}

	//check if the first and last element in the string is space
	if (array[0] == ' ')
		array.erase(0, 1); //erase the first space
	if (array[array.size() - 1] == ' ')
		array.erase(array.size() - 1, 1); //erase the last space

	//now the array is ready for counting number of words. Assume every two words are separated by a space, the first and last element is word, so the number of words is number of space + 1
	int num = 0;
	for (int i = 0; i<array.size(); i++)
		if (array[i] == ' ')
			num++;
	
	//calculate the number of symbols other than letter
	int num_letter = 0;
	for (int i=0; i<array.size(); i++)
	{
		if (isalpha(array[i]))
			num_letter++;
	}
	
	//calculate the average number of letters in each word
	double ave_letter = static_cast<double>(num_letter)/(num+1); //num+1 is the number of words
	std::cout << "\nAverage letters in one word: " << ave_letter << "\n";
	
	return num+1;

}

//string class object version
int word_counter(std::string array)
{
	//here the string is only passed by value, so you don't have to copy the string
	//delete all repeated spaces
	for (int i = 0; i<array.size(); i++)
	{
		if (array[i] == ' ' && array[i + 1] == ' ')
		{
			array.erase(i, 1); //delete i-th spaces
			i--; //after deleting the i-th slot, the content after i-th will move forward 1 length, to fill the i-th slot, so you have to push back the reading position, so you won't miss any repeated spaces. Also, pay attention that the array size is dynamically changing
		}

	}

	//check if the first and last element in the string is space
	if (array[0] == ' ')
		array.erase(0, 1); //erase the first space
	if (array[array.size() - 1] == ' ')
		array.erase(array.size() - 1, 1); //erase the last space

	//now the array is ready for counting number of words. Assume every two words are separated by a space, the first and last element is word, so the number of words is number of space + 1
	int num = 0;
	for (int i = 0; i<array.size(); i++)
		if (array[i] == ' ')
			num++;
	
		//calculate the number of symbols other than letter
	int num_letter = 0;
	for (int i=0; i<array.size(); i++)
	{
		if (isalpha(array[i]))
			num_letter++;
	}
	
	//calculate the average number of letters in each word
	double ave_letter = static_cast<double>(num_letter)/(num+1); //num+1 is the number of words
	std::cout << "\nAverage letters in one word: " << ave_letter << "\n";
	
	return num+1;
}

}



}

5. Sentence capitalizer
{

1) problem analysis
Write a function that accepts a pointer to a C-string as an argument. It capitalizes the first character in each sentence. Also write an overloaded function that accepts a string class object as its argument.

	a) Search from the beginning, capitalize the first letter appears.
	b) Search every '.' or '!' or '?', then capitalize the first letter after these symbols.
	c) Continue searching till the end of the string
	
2) Code: //pay attention that there is a period at the end of the sentence. The algorithm that finding the first letter after period may stuck in an infinite loop after the last character.
{

#include <iostream>
#include <string>
#include <cstring>

void sentence_capitalizer(char *sentence);
void sentence_capitalizer(std::string &sentence);

int main()
{
	std::string sentence = "hello, my name is Yu. what is your name? wait a second. let me guess.you are...a ha!\n";
	sentence_capitalizer(sentence);
	std::cout << sentence << "\n";

	return 0;
}

void sentence_capitalizer(char *sentence)
{
	int position = 0;

	//capitalize the first letter
	while (isalpha(sentence[position]) == 0)
		position++;
	//after the loop, sentence[position] is the first letter in the string
	sentence[position] = toupper(sentence[position]);

	//capitalize the very first letter after the sentence end marker
	while (position < strlen(sentence))
	{
		//if position is where sentence ends
		if (sentence[position] == '.' || sentence[position] == '?' || sentence[position] == '!')
		{
			while (isalpha(sentence[position]) == 0 && position < strlen(sentence))
				position++;
			if (position >= strlen(sentence))
				break;
			sentence[position] = toupper(sentence[position]);
			position++; //move on to next slot
		}

		//if position is in middle of the sentence, update
		position++;
	}

}

//overloaded function: accepts string class object as the argument
void sentence_capitalizer(std::string &sentence)
{
	int position = 0;

	//capitalize the first letter
	while (isalpha(sentence[position]) == 0)
		position++;
	//after the loop, sentence[position] is the first letter in the string
	sentence[position] = toupper(sentence[position]);

	//capitalize the very first letter after the sentence end marker
	while (position < sentence.size())
	{
		//if position is where sentence ends
		if (sentence[position] == '.' || sentence[position] == '?' || sentence[position] == '!')
		{
			while (isalpha(sentence[position]) == 0 && position < sentence.size())
				position++;
			if (position >= sentence.size())
				break;
			sentence[position] = toupper(sentence[position]);
			position++; //move on to next slot
		}

		//if position is in middle of the sentence, update
		position++;
	}

}

}


}

6. Vowels and Consonants
{

1) problem analysis
	a) write two functions. They accept a char data as the argument, they will determine whether the character is vowel (consonant) or not. This function is used in vowel (consonant) counting function
	b) display menu and make choice, use switch and do-while loop to achieve that
	
2) Code
{

#include <iostream>
#include <cstring>
#include <cctype>

int check_vowel(char letter);
int check_consonant(char letter);
int count_vowel(char *string);
int count_consonant(char *string);
void menu_input(char &choice);

//constant
const int N = 500;

int main()
{
	char choice;
	char string[N];

	//input string
	std::cout << "Please enter a string: ";
	std::cin.getline(string, N);

	//menu input
	menu_input(choice);

	if (tolower(choice) != 'e')
	{
		do
		{
			switch (tolower(choice))
			{
			case 'a': count_vowel(string); break;
			case 'b': count_consonant(string); break;
			case 'c': count_vowel(string); count_consonant(string); break;
			case 'd':
				std::cout << "Enter another string: ";
				std::cin.ignore(); //skip the '\n'
				std::cin.getline(string, N);
				break;
			case 'e': break; //this e is inputted inside the loop
			}

			if (tolower(choice) != 'e')
				menu_input(choice); //to show the menu again and input again, as long as the user didn't input e.

		} while (tolower(choice) != 'e');
	}

	std::cout << "\n\nYou quitted.\n";

	return 0;

}

//check one character is vowel or not. Called by count_vowel function
int check_vowel(char letter)
{
	if (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u')
		return 1;
	else
		return 0;
}

//check one character is consonant or not. Called by count_vowel function
int check_consonant(char letter)
{
	if (isalpha(letter) && !(tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u'))
		return 1;
	else
		return 0;
}

//count vowel
int count_vowel(char *string)
{
	int num = 0;
	for (int i = 0; i<strlen(string); i++)
		if (check_vowel(string[i]))
			num++;

	std::cout << "\nThe number of vowels in string is: " << num << "\n";
	return num;
}

//count consonant
int count_consonant(char *string)
{
	int num = 0;
	for (int i = 0; i<strlen(string); i++)
		if (check_consonant(string[i]))
			num++;
	std::cout << "\nThe number of consonants in string is: " << num << "\n";
	return num;
}

//ask for input
void menu_input(char &choice)
{


	std::cout << "\n\nA) Count the number of vowels in the string\n"
		<< "B) Count the number of consonants in the string\n"
		<< "C) Count both the number of consonants and vowels in the string\n"
		<< "D) Enter another string\n"
		<< "E) Exit the program\nPlease make a choice: ";

	std::cin >> choice;
}


}


}

7. Name arranger
{

//three array version, use three arrays to store first name, middle name and last name
Code:
{

#include <iostream>
#include <cstring>

const int NAME = 50; //define the size of a single name segment: 49+1

void get_name(char *first_name, char *middle_name, char *last_name);
void display_name(char *first_name, char *middle_name, char *last_name);
void strcat2(char *string1, const char *string2); //to replace the strcat function, which is not working in my compiler
void strcpy2(char *destination, const char *source); //to replace the strcpy function

int main()
{
	char first_name[NAME], middle_name[NAME], last_name[NAME]; //three containers for storing names
	get_name(first_name, middle_name, last_name);
	display_name(first_name, middle_name, last_name);

	return 0;
}

//get name function.
//ask for names and store in different arrays
void get_name(char *first_name, char *middle_name, char *last_name)
{
	char transfer[NAME*3];
	int i = 0, counter = 0;
	std::cout << "Please input your full name: ";
	std::cin.getline(transfer, NAME*3);

	//record first name
	while (transfer[i] != ' ')
	{
		first_name[counter] = transfer[i];
		i++;
		counter++;
	}
	first_name[counter] = '\0';
	while (transfer[i] == ' ')
		i++; //skip the space

	//record middle name
	counter = 0;
	while (transfer[i] != ' ')
	{
		middle_name[counter] = transfer[i];
		i++;
		counter++;
	}
	middle_name[counter] = '\0';

	while (transfer[i] == ' ')
		i++; //skip the space

	//record last name
	counter = 0;
	while (transfer[i] != '\0')
	{
		last_name[counter] = transfer[i];
		i++;
		counter++;
	}
	last_name[counter] = '\0';

	std::cout << first_name << "\n" << middle_name << "\n" << last_name << "\n";

}

//display name function
//allocate a new memory to hold the final array
void display_name(char *first_name, char *middle_name, char *last_name)
{
	int size = strlen(first_name) + strlen(middle_name) + strlen(last_name) + 4; //4 is to add the space for one comma and two spaces, and one null terminator

	char *name = new char[size]; //request a new memory to hold the full name

	int position = 0; //record the write position in name array

	//write in the last name, use strcpy function
	strcpy2(name, last_name);

	//write in comma and space
	strcat2(name, ", ");

	//write in first name 
	strcat2(name, first_name);
	strcat2(name, " ");

	//write in middle name
	strcat2(name, middle_name);

	//display name
	std::cout << "The formated name is: " << name << std::endl;

	//release the memory space
	delete [] name;

}

//strcat2 function
void strcat2(char *string1, const char *string2)
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

//strcpy function
void strcpy2(char *destination, const char *source)
{
	//copy content from source to destination
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}



}

//two array version, only use two arrays: one is to store last name, one is to store the remaining names
Code:
{

#include <iostream>
#include <cstring>

const int NAME = 50;

void get_name(char *last_name, char *first_name);
void display_name(char *last_name, char *first_name);
void strcpy2(char *destination, const char *source);
void strcat2(char *string1, const char *string2);

int main()
{
	char last_name[NAME], first_name[NAME];
	get_name(last_name, first_name);
	display_name(last_name, first_name);

	return 0;
}

//get name function
//ask user to input names, store the last segment of name in last_name, store the rest of name in first_name
void get_name(char *last_name, char *first_name)
{
	char *name = new char[NAME * 2];
	std::cout << "Please input your name: ";
	std::cin.getline(name, NAME * 2);

	//find out the location of the last name
	int position = strlen(name);
	while (name[position] != ' ')
		position--;
	int first_name_endpoint = position; //will be used when saving first name
	position++; //now position is where the last name begins

				//store last name into the array
	int counter = 0;
	while (name[position] != '\0')
	{
		last_name[counter] = name[position];
		position++;
		counter++;
	}
	last_name[counter] = '\0'; //put the null terminator at the end

	//store first name into the array
	int i;
	for (i = 0; i<first_name_endpoint; i++)
		first_name[i] = name[i];
	first_name[i] = '\0';

	//delete the name memory space
	delete[] name;
}

//display name function
//allocate a new memory space to store the formated name, and display
void display_name(char *last_name, char *first_name)
{
	int size = strlen(last_name) + strlen(first_name) + 4;
	char *name = new char[size];

	//copy last name to the first
	strcpy2(name, last_name);

	//append comma and space
	strcat2(name, ", ");

	//append rest name to it
	strcat2(name, first_name);

	//display
	std::cout << "Formated name: " << name << "\n";

	//free memory
	delete[] name;

}

//strcopy2
void strcpy2(char *destination, const char *source)
{
	//first, clear what ever is inside the destination array
	//int i = 0;
	//while (destination[i] != '\0')
	//destination[i++] = '\0';
	/* Pay attention, this code may cause stack-based buffer overrun! I had this problem when I write the case study!! It will display: stack around the variable 'salutation' was corrupted. */

	//second, copy content from source to destination
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}


//strcat2
void strcat2(char *string1, const char *string2)
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





}



}

8. Sum of digits in a string
{

#include <string>
#include <iostream>
#include <cstring>

void get_num(std::string &num);
void calc_sum(std::string num);
void sort_num(std::string num);

int main()
{
	//define string, and call get_num function to get the string
	std::string num;
	get_num(num);

	//call calc_sum function to calculate the summation, and display
	calc_sum(num);

	//call sort_num function to sort the string and display on screen, also, display the highest and lowest element
	sort_num(num);

	return 0;
}

void get_num(std::string &num)
{
	std::cout << "Please input a series of numbers with no separation: ";
	getline(std::cin, num);
}

void calc_sum(std::string num)
{
	int total = 0;
	for (int i = 0; i<num.size(); i++)
		total += num[i] - 48;

	std::cout << "\nTotal: " << total << "\n";
}

void sort_num(std::string num)
{
	int start_position = 0;
	do
	{
		char min = num[start_position];
		int min_index = start_position;

		for (int i = start_position; i<num.size(); i++)
			if (min > num[i])
			{
				min = num[i];
				min_index = i;
			}

		num[min_index] = num[start_position];
		num[start_position] = min;

		start_position++;
	} while (start_position < num.size() - 1);

	std::cout << num << "\n";
	std::cout << "The lowest value: " << num[0] << "\nThe highest value: " << num[num.size() - 1] << "\n";

}


}

9. Most frequent character
{

1) problem analysis
This problem is like the the mode function, but this time you are manipulating strings

2) Code
{

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

void data_analyze(std::string string, std::vector<char> &letter, std::vector<int> &num);
void sort_string(std::string &string);
void print_result(std::vector<char> &letter, std::vector<int> &num);

int main()
{
	std::string sentence = "The keys to patience are acceptance and faith. Accept things as they are, and look realistically at the world around you. Have faith in yourself and in the direction you have chosen.";
	std::cout << "Original txt:\n" << sentence << "\nSorted txt (punctuations and spaces are cleared):\n";
	sort_string(sentence);
	std::cout << sentence << "\n";

	//define two container to hold character and the number of appearance data
	std::vector<char> letter;
	std::vector<int> num;
	//call data_analyze function to find out the appearance time for each character, and sort them to get the frequency
	data_analyze(sentence, letter, num);
	//print result
	print_result(letter, num);

	return 0;
}

void data_analyze(std::string string, std::vector<char> &letter, std::vector<int> &num)
{
	int counter = 1;
	for (int i = 0; i<string.size(); i++)
	{
		if (counter == 1)
			letter.push_back(string[i]); //if this is the first letter, store into letter vector

		if (string[i] == string[i + 1])
			counter++; //update counter if the next letter is the same as this

		else
		{
			num.push_back(counter); //to store the number of repeat times for this letter
			counter = 1;
		}
	}
	//after the for loop, letter[] and num[] should be correlated, now sort them. Use selection sorting
	int start_position = 0;
	do
	{
		int max = num[start_position];
		int max_index = start_position;

		for (int i = start_position; i<num.size(); i++)
			if (max < num[i])
			{
				max = num[i];
				max_index = i;
			}

		//exchange position
		num[max_index] = num[start_position];
		num[start_position] = max;
		char max_letter = letter[max_index];
		letter[max_index] = letter[start_position];
		letter[start_position] = max_letter;
		//update start position
		start_position++;

	} while (start_position < num.size() - 1);

}

//string sorting function (use bubble sorting), also clear the spaces and punctuations
void sort_string(std::string &string)
{
	bool flag; //flag is used to record exchange status
	do
	{
		flag = false;
		for (int i = 0; i<string.size() - 1; i++)
			if (string[i] > string[i + 1])
			{
				char transfer = string[i];
				string[i] = string[i + 1];
				string[i + 1] = transfer;
				flag = true;
			}
	} while (flag == true);
	//loop will end if there is no exchange occured
	//now delete all the characters other than letter and digit
	for (int i = 0; i<string.size(); i++)
		if (!(isalnum(string[i])))
			string.erase(i--, 1);

}

//print out result
void print_result(std::vector<char> &letter, std::vector<int> &num)
{
	//find out how many top frequencies
	int size = 0;
	while (num[size] == num[0])
		size++;

	//print out result
	std::cout << "\nLetter with highest frequencies:\n";
	for (int i = 0; i<size; i++)
		std::cout << letter[i] << "\n";
	std::cout << "\nFrequency: " << num[0] << "\n";

	//print out all the result
	std::cout << "Total results are as follows:\n";
	for (int i = 0; i<num.size(); i++)
	{
		std::cout << letter[i] << "     " << num[i] << "\n";
	}
}


}

}

10. replace_substring Function
{

#include <iostream>
#include <string>

void replace_substring(std::string &str1, std::string str2, std::string str3);

int main()
{
	std::string str1 = "the dog jumped over the fence", str2 = "the", str3 = "that";
	replace_substring(str1, str2, str3);
	std::cout << str1 << "\n";
	
	return 0;
}

//
void replace_substring(std::string &str1, std::string str2, std::string str3)
{
	int position = 0;
	
	do
	{
		//find if there is any match
		position = str1.find(str2, position); //position will be the subscript where str2 match starts
		if (position != -1) //when position == -1, no match found
			str1.replace(position, str2.size(), str3); //replace the substring with string 3, the length of deletion is the same as str2, to make sure delete it all, and insert str3.
		
	} while (position != -1);
	
}

}

11. Case manipulator
{

#include <iostream>
#include <cstring>
#include <cctype>

void upper(char *str);
void lower(char *str);
void reverse(char *str);

int main()
{
	char str1[] = "acBsWgsSw42", str2[] = "acBsWgsSw42", str3[] = "acBsWgsSw42";
	upper(str1);
	lower(str2);
	reverse(str3);
	
	std::cout << str1 << "\n" << str2 << "\n" << str3 << "\n";
	return 0;
}

void upper(char *str)
{
	for (int i=0; i<strlen(str); i++)
	{
		str[i] = toupper(str[i]);
	}
}

void lower(char *str)
{
	for (int i=0; i<strlen(str); i++)
		str[i] = tolower(str[i]);
}

void reverse(char *str)
{
	for(int i=0; i<strlen(str); i++)
	{
		if(isupper(str[i]))
			str[i] = tolower(str[i]);
		else if (islower(str[i]))
			str[i] = toupper(str[i]);
	}
}

}

12. Password verifier
{

#include <iostream>
#include <string>
#include <cctype>

int verify(std::string password);

int main()
{
	//asf for user input
	std::cout << "Please input the password: ";
	std::string password;
	getline(std::cin, password);
	
	int result = verify(password);
	if (result)
		std::cout << "Your password is valid.\n";
	else
		std::cout << "Your password is not valid.\n";
	
	return 0;
	
}

//verification function
int verify(std::string password)
{
	if (password.size() < 6)
	{
		std::cout << "Your password should be at leaset 6 characters long.\n";
		return 0;
	}
	
	//go over the string to find out if there is at lease one upper case letter
	int upper = 0;
	for (int i=0; i<password.size(); i++)
		if (isupper(password[i]))
		{
			upper = 1;
			break;
		}
	
	//go over the string to find out if there is at lease one lower case letter
	int lower = 0;
	for (int i=0; i<password.size(); i++)
		if (islower(password[i]))
		{
			lower = 1;
			break;
		}
	
	if (!(upper && lower))
	{
		std::cout << "Your password should have at least one upper letter and one lower letter.\n";
		return 0;
	}
	
	//go over the password to find out if there is any digits
	int digit = 0;
	for (int i=0; i<password.size(); i++)
		if (isdigit(password[i]))
			digit = 1;
	if (digit == 0)
	{
		std::cout << "Your password should have at lease one digit.\n";
		return 0;
	}
	
	//after all check, return 1
	return 1;
}

}

13. Date printer
{

#include <iostream>
#include <string>
#include <cctype>

int data_format(std::string input, std::string &output);

int main()
{
	//create two containers, also the choice variable
	std::string input, output;
	char choice;
	int counter = 0;

	do
	{
		choice = 'N';
		std::cout << "Please input date in the format of mm/dd/yyyy: ";
		if (counter != 0)
			std::cin.ignore();
		getline(std::cin, input);
		int result;
		result = data_format(input, output);

		if (result)
			std::cout << output << "\n";

		//ask for repeat
		std::cout << "\nDo you want to test another date (Y/N): ";
		std::cin >> choice;
		counter++;
	} while (tolower(choice) == 'y');

	std::cout << "You quitted.\n";

	return 0;
}

//transform the data format
int data_format(std::string input, std::string &output)
{
	//section O: check the general format of input string: num num / num num / num num num num
	if (!(isdigit(input[0]) && isdigit(input[1]) && input[2] == '/' && isdigit(input[3]) && isdigit(input[4]) && input[5] == '/' && isdigit(input[6]) && isdigit(input[7]) && isdigit(input[8]) && isdigit(input[9])))
	{
		std::cout << "Invalid input, format should be mm/dd/yyyy.\n";
		return 0;
	}

	//section I: copy month info into output string
	if (input[0] == '0')
	{
		switch (input[1])
		{
		case '1': output = "January "; break;
		case '2': output = "Feburary "; break;
		case '3': output = "March "; break;
		case '4': output = "April "; break;
		case '5': output = "May "; break;
		case '6': output = "June "; break;
		case '7': output = "July "; break;
		case '8': output = "August "; break;
		case '9': output = "September "; break;
		default: std::cout << "Invalid input! Months should be numbers.\n"; return 0;
		}
	}

	else if (input[0] == '1')
	{
		switch (input[1])
		{
		case '0': output = "October "; break;
		case '1': output = "November "; break;
		case '2': output = "December "; break;
		default: std::cout << "Invalid input! Months should be numbers betweem 01 to 12.\n"; return 0;
		}
	}

	else
	{
		std::cout << "Invalid input! Months should be numbers betweem 01 to 12.\n";
		return 0;
	}

	//Section II: copy dats and years info into output string;
	//check big month days (01 to 31)
	std::string month(input, 0, 2); //create a string named month to store the month digit
	std::string day(input, 3, 2); //create a string named day to store the day digit
	std::string YEAR(input, 6, 4); //create a string named year to store the year digit
	int year = atoi(YEAR.c_str()); //transfer number of year into integer. This makes calculating leap year easier. atoi 

								   //big month check
	if (month == "01" || month == "03" || month == "05" || month == "07" || month == "08" || month == "10" || month == "12")
	{
		if (day < "01" || day > "31")
		{
			std::cout << "Invalid input! Big month should have day number between 01 and 31.\n";
			return 0;
		}
	}
	//small month check
	if (month == "04" || month == "06" || month == "09" || month == "11")
	{
		if (day < "01" || day > "30")
		{
			std::cout << "Invalid input! Small month should have day number between 01 and 30.\n";
			return 0;
		}
	}
	//leap month check
	int leap_year = 0;
	if (month == "02")
	{
		//if month is 02, we need to check whether the year is a leap year so we can decide the number of days accepted. leap_year is a flag to record the status of the year.
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			leap_year = 1;

		switch (leap_year)
		{
		case 0: if (day < "01" || day > "28")
		{
			std::cout << "Invalid input! In non-leap year, leap month should have day number between 01 and 28.\n";
			return 0;
		}

		case 1: if (day < "01" || day > "29")
		{
			std::cout << "Invalid input! Leap month should have day number between 01 and 29.\n";
			return 0;
		}
		}

	}

	//if program continues here, it means it passes the month check. It can append days and year info in the output	
	output.append(day); //append day number to the output string
	output.append(", "); //append comma and space to the output string
	output.append(YEAR); //append years to the output string

	return 1; //shows date format transformation complete

}


}

14. Word separator
{

#include <string>
#include <iostream>
#include <cctype>

void word_separator(std::string &str);

int main()
{
	std::string str = "WheverYouGoThereYouAre.";
	std::cout << "Before formatting: " << str << "\n";
	word_separator(str);
	std::cout << "After formatting: " << str << "\n";	
	
	return 0;
}

void word_separator(std::string &str)
{
	for (int i=1; i<str.size(); i++)
	{
		if (isupper(str[i])) //two things must be done: 1) lower the letter; 2) insert a space here
		{
			str[i] = tolower(str[i]);
			str.insert(i, " ");
		}
	}
}

}

15. Character analysis
{

#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <iostream>


void text_generator(int num);
void analyze();

int main()
{
	//call text_generator to create a random txt file
	text_generator(1000);

	//call analyze function to analyze the file, and print out the result
	analyze();

	return 0;
}

//text generator: generate a txt randomly from ASCII table, it accepts an integer showing the length of the txt. It will save file to D:\random_text.txt
void text_generator(int num)
{

	//initialize random number
	int N_min = 32, N_max = 122; //minimum and maximum number of the output range, this is the range in the ASCII table
	int seed = time(0);
	srand(seed);

	//create the file streamer: write
	std::ofstream cout;
	cout.open("D:\\random_text.txt");

	//start writing (get rid of undesired character)
	int index;
	for (int i = 0; i<num; i++)
	{
		index = rand() % (N_max - N_min + 1) + N_min;
		if ((index >= 35 && index <= 45) || (index >= 60 && index <= 62) || (index == 64) || (index >= 91 && index <= 96))
		{
			i--;
			continue; //these are undesired character
		}

		if (i % (i - 13) == 0 || index % 13 == 0) //this is to increase the number of printing space
		{
			cout << " ";
			i++;
		}

		if (index % 55 == 0) //this is to increase the number of printing space
		{
			cout << "\n";
			i++;
		}

		cout << static_cast<char>(index);
	}

	//finish and close
	cout.close();

}

////analyze the result
void analyze()
{
	//create a file streamer: read
	std::ifstream cin;
	cin.open("D:\\random_text.txt");

	//create a string container and read the content in file to the string container
	std::string array, transfer;
	getline(cin, array); //read the first line array	

	while (getline(cin, transfer))
		array.append(transfer); //append the rest string into array
	cin.close(); //after loading content into array, close file


				 //go over to analyze the array
	int num_upper = 0, num_lower = 0, num_digit = 0, num_punct = 0;
	for (int i = 0; i<array.size(); i++)
	{
		if (isupper(array[i]))
			num_upper++;
		else if (islower(array[i]))
			num_lower++;
		else if (isdigit(array[i]))
			num_digit++;
		else if (ispunct(array[i]))
			num_punct++;
	}

	//print out result
	std::cout << "Number of upper letters: " << num_upper << "\n"
		<< "Number of lower letters: " << num_lower << "\n"
		<< "Number of digits: " << num_digit << "\n"
		<< "Number of punctuations: " << num_punct << "\n";

}

}

16. Pig Latin
{

#include <string>
#include <cctype>
#include <iostream>

void transfer(std::string &str);

int main()
{
	std::string str = "Patience and diligence like faith remove mountains";
	std::cout << "Before transform: " << str << "\n";
	transfer(str);
	std::cout << "After transform: " << str << "\n";

	return 0;
}

//pig latin transfer program
void transfer(std::string &str)
{
	int start = 0, end; //start and end position of a word
	while (start < str.size())
	{
		//find out the end of the current word
		end = start;
		while (str[end] != ' ' && (str[end] != '\0' || str[end] == ' '))
			end++; //now end is the subscript of the ' ' or '\0' at end of the word

				   //insert the first letter here
		str.insert(end, 1, tolower(str[start]));
		end++; //ready to insert the last ay
		str.insert(end, "ay");

		//delete the first element in the word
		str.erase(start, 1);

		//update start position
		start = end + 2;
	}
}

}

17. Morse code converter
{

#include <iostream>
#include <string>
#include <cctype>

void convert(std::string input, std::string &morse);
std::string morse(char letter);

int main()
{
	std::string input = "Patience and Diligence, like faith, remove mountains.";
	std::string output;
	convert(input, output);
	std::cout << output << "\n";

	return 0;

}

//convert function
void convert(std::string input, std::string &output)
{
	for (int i = 0; i<input.size(); i++)
	{
		output.append(morse(input[i]));
	}
}

//Morse transfer
//accepts a character, and return a string which contains the Morse code for the character
std::string morse(char letter)
{
	//'|' is used to separate each word
	switch (toupper(letter))
	{
	case ' ': return "   ";
	case ',': return "--..--|";
	case '.': return ".-.-.-| ";
	case '?': return "..--..| ";
	case '0': return "-----| ";
	case '1': return ".----| ";
	case '2': return "..---| ";
	case '3': return "...--| ";
	case '4': return "....-| ";
	case '5': return ".....| ";
	case '6': return "-....| ";
	case '7': return "--...| ";
	case '8': return "---..| ";
	case '9': return "----.| ";
	case 'A': return ".-| ";
	case 'B': return "-...| ";
	case 'C': return "-.-.| ";
	case 'D': return "-..| ";
	case 'E': return ".| ";
	case 'F': return "..-.| ";
	case 'G': return "--.| ";
	case 'H': return "....| ";
	case 'I': return "..| ";
	case 'J': return ".---| ";
	case 'K': return "-.-| ";
	case 'L': return ".-..| ";
	case 'M': return "--| ";
	case 'N': return "-.| ";
	case 'O': return "---| ";
	case 'P': return ".--.| ";
	case 'Q': return "--.-| ";
	case 'R': return ".-.| ";
	case 'S': return "...| ";
	case 'T': return "-| ";
	case 'U': return "..-| ";
	case 'V': return "...-| ";
	case 'W': return ".--| ";
	case 'X': return "-..-| ";
	case 'Y': return "-.--| ";
	case 'Z': return "--..| ";
	default: return ""; //if character is not in Morse table, don't show it

	}
}

}

18. Phone number list
{

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void read_data(std::vector<std::string> &list);
void search(std::vector<std::string> list, std::string keyword);

int main()
{
	//define a vector container to store phone number and call read_data function to load data into vector
	std::vector<std::string> list;
	read_data(list);

	//ask user to input a string
	std::cout << "Please input key word to search: ";
	std::string keyword;
	getline(std::cin, keyword);

	//call search function to search for the whole vector, print out record if any matches found
	search(list, keyword);

	return 0;
}

//read function, this will load phone number list into the vector which stores the data
void read_data(std::vector<std::string> &list)
{
	//create a file streamer: read
	std::ifstream cin;
	cin.open("D:\\phone_numbers.txt");

	//read all data into the vector
	std::string transfer;
	while (getline(cin, transfer))
	{
		list.push_back(transfer);
	}

	//close streamer
	cin.close();

}

//search function
void search(std::vector<std::string> list, std::string keyword)
{
	std::cout << "\nSearch result: \n";
	bool match = false;
	for (int i = 0; i<list.size(); i++)
	{
		if (list[i].find(keyword) != -1) //this means match is found, print out the record
		{
			std::cout << list[i] << "\n";
			match = true;
		}
	}

	//if match is false, print out: nothing is found!
	if (!match)
		std::cout << "No record found matching \"" << keyword << "\"\n";

}


}

19. Check Writer
{

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>

void get_info(std::string &date, std::string &name, std::string &amount);
void transfer(std::string &amount, std::string &amount_spell);
void print(std::string amount_spell, std::string amount, std::string name, std::string date);

int main()
{
	//define three containers to hold date, name and amount. Call get_info function to input the data
	std::string date, name, amount;
	get_info(date, name, amount);

	//define a string object to hold the spelled out dollar amount, call a transfer function to transfer the amount into spelled out amount
	std::string amount_spell;
	transfer(amount, amount_spell);

	//call print function to print out the check
	print(amount_spell, amount, name, date);

	return 0;

}

//get the required information
void get_info(std::string &date, std::string &name, std::string &amount)
{
	std::cout << "Please input payee's name: ";
	getline(std::cin, name);

	std::cout << "Please input the date: ";
	getline(std::cin, date);

	std::cout << "Please input the amount (amount should be greater than zero, but not greater than $10,000): ";
	getline(std::cin, amount);
	//input check
	while (atof(amount.c_str()) < 0.0 || atof(amount.c_str()) > 10000.0)
	{
		std::cout << "The amount should be in 0 ~ 10,000, please re-enter: ";
		getline(std::cin, amount);
	}

}

//transfer the amount into spelled out amount
void transfer(std::string &amount, std::string &amount_spell)
{
	//check if the amount is 10,000, if so, let amount_spell = "ten thousand dollars"
	if (amount == "10000")
	{
		amount_spell = "Ten thousand dollars.";
		return;
	}

	//find out the position before the dot, if no dot is found, the position of the dot is set to the last element
	int position;
	position = amount.find(".");

	//create a string container to hold the content of cents
	std::string cents;
	//adjust position, also transfer cents into a string
	if (position == -1)
		position = amount.size() - 1; //nothing to hold in cents
	else
	{
		cents.append(amount, position + 1); //add the amount of cents into cents string
		position -= 1;
	}
	//modify cents, when user input amount like 1.1, its actually 10 cents, also, truncate cents that are more than 99
	if (cents.size() == 1)
	{
		switch (cents[0])
		{
		case '1': cents = "10"; break;
		case '2': cents = "20"; break;
		case '3': cents = "30"; break;
		case '4': cents = "40"; break;
		case '5': cents = "50"; break;
		case '6': cents = "60"; break;
		case '7': cents = "70"; break;
		case '8': cents = "80"; break;
		case '9': cents = "90"; break;
		}
	}

	else if (cents.size() > 2) //truncate
		cents.erase(2);
	//copy this cents info into amount (to format cents part in amount)
	amount.erase(position + 2); //erase the original cents info
	amount.append(cents); //attach the formated cents info

	//now, whether or not the dot exist, position is the last digit before the dot or at the end of the number stored in amount
	//create a flag to mark whether the amount is one dollar or more than one dollar (dollars)
	bool single = false;
	if (atof(amount.c_str()) < 2.0)
		single = true;

	int order = 1; //to keep track of order of magnitude, 1: one, 2: ten, 3: hundred, 4: thousand
	bool eleven = false; //to record whether the "eleven" notation exists or not
	if (position > 0 && amount[position - 1] == '1')
		eleven = true; //the eleven notation exists, should deal with it other way


	while (position >= 0)
	{
		if (order == 1) //single digit
		{
			if (eleven) //if the eleven case is true, no need to input the ones digit
			{
				order++;
				position--;
				continue;
			}

			switch (amount[position])
			{
			case '1': amount_spell.insert(0, " one"); break;
			case '2': amount_spell.insert(0, " two"); break;
			case '3': amount_spell.insert(0, " three"); break;
			case '4': amount_spell.insert(0, " four"); break;
			case '5': amount_spell.insert(0, " five"); break;
			case '6': amount_spell.insert(0, " six"); break;
			case '7': amount_spell.insert(0, " seven"); break;
			case '8': amount_spell.insert(0, " eight"); break;
			case '9': amount_spell.insert(0, " nine"); break;
			default: amount_spell.insert(0, ""); break;
			}

			order++;
			position--; //update the order and position
		}

		else if (order == 2) //ten-th
		{
			if (eleven)
			{
				switch (amount[position + 1]) //notations are based on different digit on ones position
				{
				case '1': amount_spell.insert(0, " eleven"); break;
				case '2': amount_spell.insert(0, " twelve"); break;
				case '3': amount_spell.insert(0, " thirteen"); break;
				case '4': amount_spell.insert(0, " fourteen"); break;
				case '5': amount_spell.insert(0, " fifteen"); break;
				case '6': amount_spell.insert(0, " sixteen"); break;
				case '7': amount_spell.insert(0, " seventeen"); break;
				case '8': amount_spell.insert(0, " eighteen"); break;
				case '9': amount_spell.insert(0, " nineteen"); break;
				}
			}

			else
			{
				switch (amount[position])
				{
				case '2': amount_spell.insert(0, " twenty"); break;
				case '3': amount_spell.insert(0, " thirty"); break;
				case '4': amount_spell.insert(0, " fourty"); break;
				case '5': amount_spell.insert(0, " fifty"); break;
				case '6': amount_spell.insert(0, " sixty"); break;
				case '7': amount_spell.insert(0, " seventy"); break;
				case '8': amount_spell.insert(0, " eighty"); break;
				case '9': amount_spell.insert(0, " ninety"); break;
				default: amount_spell.insert(0, ""); break;
				}
			}

			order++;
			position--;

		}

		else if (order == 3) //hundreds
		{
			switch (amount[position])
			{
			case '1': amount_spell.insert(0, " one hundred"); break;
			case '2': amount_spell.insert(0, " two hundred"); break;
			case '3': amount_spell.insert(0, " three hundred"); break;
			case '4': amount_spell.insert(0, " four hundred"); break;
			case '5': amount_spell.insert(0, " five hundred"); break;
			case '6': amount_spell.insert(0, " six hundred"); break;
			case '7': amount_spell.insert(0, " seven hundred"); break;
			case '8': amount_spell.insert(0, " eight hundred"); break;
			case '9': amount_spell.insert(0, " nine hundred"); break;
			default: amount_spell.insert(0, ""); break;
			}

			order++;
			position--;
		}

		else if (order == 4) //thousands
		{
			switch (amount[position])
			{
			case '1': amount_spell.insert(0, " one thousand"); break;
			case '2': amount_spell.insert(0, " two thousand"); break;
			case '3': amount_spell.insert(0, " three thousand"); break;
			case '4': amount_spell.insert(0, " four thousand"); break;
			case '5': amount_spell.insert(0, " five thousand"); break;
			case '6': amount_spell.insert(0, " six thousand"); break;
			case '7': amount_spell.insert(0, " seven thousand"); break;
			case '8': amount_spell.insert(0, " eight thousand"); break;
			case '9': amount_spell.insert(0, " nine thousand"); break;
			default: amount_spell.insert(0, ""); break;
			}

			order++;
			position--;
		}


	}

	//finished first half or spelled amount transformation
	//delete the first space, and replace the first letter with its upper case counterpart
	amount_spell.erase(0, 1);
	amount_spell[0] = toupper(amount_spell[0]);
	//append dollars to the end of the spelled amount
	if (single)
		amount_spell.append(" dollar");
	else
		amount_spell.append(" dollars");
	//append cent amount to the end of the spelled amount
	amount_spell.append(" and ");
	amount_spell.append(cents);
	if (cents == "01")
		amount_spell.append(" cent.");
	else if (cents.size() > 0)
		amount_spell.append(" cents.");

}

//call print function to print the check
void print(std::string amount_spell, std::string amount, std::string name, std::string date)
{
	//print out the first line, date
	std::cout << "\n\n\n" <<std::setw(74) << "Date:" << date << "\n\n";

	//create a string container to hold Pay to the Order of + name info
	std::string name_line = "Pay to the Order of: ";
	name_line.append(name);

	//print the name line
	std::cout << std::setw(69) << std::left << name_line;

	//print out the money
	std::cout << "$" << amount << "\n\n";

	//print the spelled amount
	std::cout << amount_spell << "\n\n\n";
}


}

/**********************************************************/
/** Patience and diligence, like faith, remove mountains **/
/**********************************************************/

