//8-3. Case Study: product searching program
#include <iostream>
#include <string>
#include <fstream>

int find_product(int product_number[], int num);
void initiate(std::string product_title[], std::string product_description[], int product_number[], double product_price[]);

int main()
{
	/*
	This function will enable the proper running of other functions
	1. To initiate data base, including four arrays to store:
	a) product title
	b) product description
	c) product number
	d) unit price
	2. ask the user to input a product number
	3. search if the number exist
	Yes) Print out the corresponding product title, description, number and price
	No) notice the user the product doesn't exist
	4. Repeat 2, 3 as long as the user wants (use a do/while loop to control this)
	*/

	//variable and array definition
	std::string product_title[9]; //store product title
	std::string product_description[9]; //store product description
	int product_number[9]; //store product number, this is the tag user searches
	double product_price[9]; //store product price
	char choice; //used to store the choice of user
	int num; //used to hold user's demanding number
	int result; //to hold the searching result. If its -1, no match, otherwise it will contain
				// the subscript of the product

				//initialize the database
	initiate(product_title, product_description, product_number, product_price);
	std::cout << product_description[1] << "\n";
	//start searching
	do
	{
		//ask user to enter a product number
		std::cout << "Please input a product number to search: ";
		std::cin >> num;

		//call find_product() function to find the index (subscript) of the product
		result = find_product(product_number, num);

		//check result, display result if the matche is found, or notice the user if no match
		//is found.
		if (result != -1)
		{
			std::cout << "Search result:\n"
				<< "Product Number: " << product_number[result] << std::endl
				<< "Product Title: " << product_title[result] << std::endl
				<< "Product Description: " << product_description[result] << std::endl
				<< "Product Price: $" << product_price[result] << std::endl;
		}
		else
			std::cout << "No matches found for product number " << num << std::endl;

		//ask if user wants another search
		std::cout << "Would you want to do another search? (Y/N) ";
		std::cin >> choice;

	} while (choice == 'Y' || choice == 'y');

	//notice the user he or she quitted
	std::cout << "You quitted.\n";

	return 0;

}

//initialize function, fill the database array
void initiate(std::string product_title[], std::string product_description[], int product_number[], double product_price[])
{
	/*
	This function will initialize the content in the data base. The content will be read from
	a txt file.
	*/

	//create a file streamer: read
	std::ifstream cin;
	cin.open("D:\\data_base.txt");

	//the data stored in the file is structured data, use a loop to read them to the array
	for (int i = 0; i<9; i++)
	{
		getline(cin, product_title[i]); //read product title
		getline(cin, product_description[i]); //read product description
		cin >> product_number[i]; //read product number
		cin >> product_price[i]; //read product price
		cin.ignore();
	}

	//after this step, all data should be stored into the array, close file
	cin.close();


}

//search function
int find_product(int product_number[], int num)
{
	/*
	This function will search the product_number array and try to find the product with a
	product number of num.
	Yes, found match: return the subscript of the product
	No match: return -1
	Binary search strategy is used for searching
	*/

	int first = 0, last = 8; //define searching section restrictor
	int middle = (first + last) / 2; //define the searching position

	do
	{
		if (product_number[middle] == num)
			return middle;
		else if (product_number[middle] > num)
		{
			last = middle - 1;
			middle = (first + last) / 2;
		}
		else
		{
			first = middle + 1;
			middle = (first + last) / 2;
		}
	} while (first <= last);

	return -1;

}
