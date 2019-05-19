8-1. Linear search program
1) Program description
{
	This program will do following things:
	a) use a random number function to generate 10000 integers (range is 1 ~ 1000), and then 
		store them in an array
	b) ask user input a number (range in 1 ~ 1000, do input check)
	c) use a find_num function to find how many times this number occured in the array, also
		the position of the occurance has to be stored in a vector
	d) report the number of times occur and their position to the user
	e) ask for the user if he or she wants to do another search, if yes, do again; if no, exit
}

2) function
{
const int N=10000;
2-0
int main()
{
	/*
	Define:
	1. An array to store random number;
	2. an integer variable to store the total number of matches;
	3. a vector to store the subscript of specific match
	4. a character variable to ask for user's choice
	*/
	
	int num[N];
	int total_match;
	int number;
	std::vector<int> position;
	char choice;
	
	//call initialize_num() to initialize num[N] with random number
	initialize_num(num, N);
	do
	{
		//initialize
		total_match = 0;
		position.clear();
		
		//ask user to input a number
		std::cout<<"What is the number you looking for: ";
		std::cin >> number;
	
		//use the find_num() to find out time of occurance and store subscript in position
		find_num(num, N, position, total_match, number);
		
		//print out total times of match and the position
		std::cout<<"Total times of match: " <<total_match << std::endl;
		std::cout<<"The positions are: \n";
		for(int i=0;i<position.size();i++)
			std::cout<<position[i]<<std::endl;
		
		//ask for if user wants to repeat or not
		std::cout << "Do you want to test another number? (Y/N): ";
		std::cin >> choice;
		
	} while (choice=='Y'||choice=='y');
	
	std::cout<<"You quitted.\n";
	
	return 0;

}

2-1
void initialize_num(int num[], int total)
{
	//initialize random generator
	int seed;
	seed=time(0);
	srand(seed);
	int N_max = 1000, N_min = 1;
	
	//begin recording
	for(int i=0;i<total;i++)
		num[i]=rand()%(N_max - N_min+1)+N_min;
}

2-2
void find_num(int num[], int array_size, std::vector<int> &position, int &total_match, int number);
}


8-2. Binary Search
Code
{
#include <iostream>

const int SIZE = 12;
int binary_search(int num[], int number);

int main()
{
	//define
	int num[SIZE]={54, 75, 120, 155, 169, 185, 200, 225, 260, 310, 445, 560}; //array to hold the number
	int number; //the search number
	int result;
	
	//ask user to input the number
	std::cout << "Input a number to check if the number is in the array: ";
	std::cin >> number;
	
	//call binary_search() to check if the number is in the array
	result = binary_search(num, size, number);
	
	//print out result
	if(result == -1)
		std::cout << "The number is not in the array.\n";
	else
		std::cout << "The number is in the array, it's the number " << result + 1 << std::endl;
	
	return 0;
}

int binary_search(int num[], int size, int number, int &position)
{
	int first = 0, last = size;
	int middle = (last - first)/2;
	
	do
	{
		if(num[middle]==number)
			return middle;
		else if (num[middle] > number)
		{
			last = middle;
			middle = (last - first)/2;
		}
		else
		{
			first = middle;
			middle = (last - first)/2;
		}
	} while (first!=last);
	
	return -1;

}

}

8-3 Case Study: Product Search System

Objective: 

create a small database so the user can search the detail of products by inputting the 
product number.

1) header file
#include <iostream>
#include <string>
#include <fstream>


2) Program sketch
{
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
	
	//start searching
	do
	{
		//ask user to enter a product number
		std::cout << "Please input a product number to search: ";
		std::cin >> num;
		
		//call find_product() function to find the index (subscript) of the product
		result = find_product(product_number, num);
		
		//check result
		if(result != -1)
		{
			std::cout << "Search result:\n"
					<< "Product Number: " << product_number[result] << std::endl;
					<< "Product Title: " << product_title[result] << std::endl;
					<< "Product Description: " << product_description[result] << std::endl;
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
void initiate(std::string product_title[], std::string product_description[], int &product_number[], double &product_price[])
{
	/*
	This function will initialize the content in the data base. The content will be read from
	a txt file.
	*/
	
	//create a file streamer: read
	std::ifstream cin;
	cin.open("D:\\data_base.txt");
	
	//the data stored in the file is structured data, use a loop to read them to the array
	for(int i=0;i<9;i++)
	{
		getline(cin, product_title[i]); //read product title
		getline(cin, product_description[i]); //read product description
		cin >> product_number[i]; //read product number
		cin >> product_price[i]; //read product price
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
	int middle = (first + last)/2; //define the searching position
	
	do
	{
		if(product_number[middle] == num)
			return middle;
		else if (product_number[middle] > num)
		{
			last = middle - 1;
			middle = (first + last)/2;
		}
		else
		{
			first = middle + 1;
			middle = (first + last)/2;
		}
	} while (first <= last);
	
	return -1;	
	
}

}


8-4. Bubble Sorting
Objective: use bubble sorting technique to sort an array in descending order
{
#include <iostream>

int main()
{
	/*
	This function calls other functions to finish the objective and display result
	*/
	
	//variable definition
	
	//
}

}

8-6. Sales Report
{
	
0. Description
The purpose is to:
	1) Sort the product in sale amount in descending order
	2) Print a report of the product (sales is in descending order) ranking. Including all details
	3) Calculate the total number of all units sold, add to the end of the report
	4) Calculate the total sale, add to the end of the report

1. header file and constant
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

const int NUM = 9;
2. function list

int main()
{
	//define container to store all the information
		1) product_title
		2) product_description
		3) product_number
		4) product_price
		5) product_sale
		6) unit_sale
		7) rank[] /*to hold the ranking of each product. For example, if rank[5] = 3, that
					means the third product is ranked fifth */
	std::string product_title[NUM], product_description[NUM];
	int product_number[NUM], unit_sale[NUM], rank[NUM];
	double product_sale[NUM], product_price[NUM];
	
	//call read_data function to load data into the container
	read_data(product_title, product_description, product_number, product_price, unit_sale);
	
	//call calc_sale function to calculate the sales for each product, sale the amount into
	calc_sale(product_price, unit_sale, product_sale);	
	
	/*
	Call sort_sale function to sort the product sale. during the sorting, rank is created, 
	which stores the ranking information. rank[] array is what we want, we need a copy of product 
	sale to perform the sorting
	*/
		//create a copy of product_sale array
	double product_sale_sort[NUM];
	for(int i=0;i<NUM;i++)
	{
		product_sale_sort[i] = product_sale[i];
	}
		//call sort_sale function to get the rank information
	sort_sale(product_sale_sort, rank);
	
	//call for print function to print the report (also do the calculation to get total number of all units sold, total sales)
	print_report(product_title, product_description, product_number, product_price, unit_sale, rank, product_sale);
		//notify processing complete
	std::cout << "The processing is complete, please check the file for details.\n";
	
	return 0;
}

void read_data(std::string product_title[], std::string product_description[], int product_number[], double product_price[], int unit_sale[])
{
	//creat a file streamer: read
	std::ifstream cin;
	cin.open("D:\\data_base.txt");
	
	//use a for loop to load all the data
	for(int i=0;i<NUM;i++)
	{
		getline(cin, product_title[i]);
		getline(cin, product_description[i]);
		cin >> product_number[i];
		cin >> product_price[i];
		cin >> unit_sale[i];
		cin.ignore(); //the next getline function may input the newline character?
	}
	
	//close file
	cin.close();
}

void calc_sale(double product_price[], int unit_sale[], double product_sale[])
{
	/*
	This function will use a loop to calculate the sale amount for each product
	*/
	
	for(int i=0;i<NUM;i++)
	{
		product_sale[i] = product_price[i]*unit_sale[i];
	}
}

void sort_sale(double product_sale_sort[], int rank[])
{
	int start_scan = 0, max_index;
	double max; //used to store the maximum sale
	
	do
	{
		max = product_sale_sort[start_scan];
		max_index = start_scan;
		
		//find the highest value and the corresponding index
		for(int i=start_scan;i<NUM;i++)
		{
			if(max < product_sale_sort[i])
			{
				max = product_sale_sort[i];
				max_index = i;
			}
		}
		
		/*
		>> This approach is incorrect. When you are sorting the product_sale_sort array, you are 
			also reshaping it. As a result, the max_index is not the same index as the original 
			array! 
		//store the highest index in rank array
		rank[start_scan] = max_index;
		*/
		
		//exchange element
		product_sale_sort[max_index] = product_sale_sort[start_scan];
		product_sale_sort[start_scan] = max;
		
		//after the highest value is put into the start_scan slot, update the start_scan position
		start_scan++;
		
	} while(start_scan < NUM);
	
}

void print_report(std::string product_title[], std::string product_description[], int product_number[], double product_price[], int unit_sale[], int rank[], double product_sale[])
{
	//create a file streamer: write
	std::ofstream cout;
	cout.open("D:\\Sales Report.txt");
	
	//write table header
	cout << "Product Number            Product Title            Product Price($)        Unit Sold         Sales($)\n";
	cout << "------------------------------------------------------------------------------------------------------------\n";
	
	//set the printing format
	cout << std::setprecision(2) << std::fixed;
	
	//use a loop to print out all ranking
	for (int i=0; i<NUM; i++)
	{
		cout << std::setw(10) << product_number[rank[i]] << std::setw(35) << product_title[rank[i]] << std::setw(17) << product_price[rank[i]] << std:setw(21) << unit_sale[rank[i]] << std::setw(20) << product_sale[rank[i]] << std::endl;		
	}
	
	//print the table tail
	cout << "------------------------------------------------------------------------------------------------------------\n\n";
	
	//calculate the total number of units sold (use a loop to go over unit_sale)
	int total_unit = 0;
	for(int i=0; i<NUM; i++)
		total_unit += unit_sale[i];
	
	//calculate the total number of sales (use a loop to go over product_sale)
	int total_sale = 0;
	for(int i=0; i<NUM; i++)
		total_sale += product_sale[i];
	
	//print to the file
	cout << "Total units sold during the past six months: " << total_unit << "\n";
	cout << "Total sales: $" << total_sale << "\n";
	
	//disconnect streamer from file
	cout.close();
}








Product Number            Product Title            Product Price($)        Unit Sold         Sales($)
------------------------------------------------------------------------------------------------------------
       914           Teams Are Made, Not Born            14.95                  888            99999.99


/*
The approach of the book:
In the book, when the product_sale is sorted, the product_number is also sorted, so the sorted 
product_sale can correspond to product_number, which means their subscript is changed at the 
same time. The following program is used to mimic this approach
*/

//mimic the book's approach (bubble algorithm)
#include <iostream>

int main()
{
	/*
	In this program, two arrays will be sorted at the same time, at the same way
	*/
	
	//create two arrays
	int num1[5] = { 4, 1, 3, 5, 2 };
	int num2[5] = { 101, 102, 103, 104, 105 }; //you can think of num2 contains
	//the index, num1 contains the value. Now I want to sort num1 in the descending
	//order, and print out the corresponding index.
	
	//the bubble algorithm approach
	bool exchange; //used to record whether if an exchange happened during sorting
	do
	{
		exchange = false;
		for (int i=0; i<4; i++)
		{
			if (num1[i] < num1[i+1])
			{
				//exchange num1[i] and num1[i+1], also num2[i], num2[i+1]
					//define a variable to transfer
				int transfer;
					//exchange num1[i] and num1[i+1]
				transfer = num1[i];
				num1[i] = num1[i+1];
				num1[i+1] = transfer;
					//exchange num2[i] and num2[i+1]
				transfer = num2[i];
				num2[i] = num2[i+1];
				num2[i+1] = transfer;
				exchange = true;
			}
		}
	} while (exchange);
	
	//if exchange is false, no exchange is made, that means the array is in order
	//print out the array
	for (int i=0; i<5; i++)
		std::cout << num2[i] << "   " << num1[i] << std::endl;
	
	return 0;		
	
}

//mimic the book's approach (selection algorithm)
#include <iostream>

int main()
{
	/*
	In this program, two arrays will be sorted at the same time, at the same way
	*/
	
	//create two arrays
	int num1[5] = { 4, 1, 3, 5, 2 };
	int num2[5] = { 101, 102, 103, 104, 105 }; //you can think of num2 contains
	//the index, num1 contains the value. Now I want to sort num1 in the descending
	//order, and print out the corresponding index.
	
	//selection algorithm
	/*
	In selection algorithm, the position of an element is determined by one iteration. The basic 
	step is:
	1) set the start_scan location as the beginning of the array, set the max or min as the first 
		element
	2) go over from start_scan to the end of the array, find out the max or min, as well as the 
		subscript for max or min element
	3) exchange the max or min element to the start_scan location
	4) increase start_scan location by one, and re-initiate the max or min by the element at 
		the start_scan position, and then do it again
	*/
	
	int start_scan = 0;
	int max = num1[start_scan];
	int max_index = start_scan;
	
	do
	{
		//go over the array, find the maximum
		for (int i=start_scan+1; i<5; i++)
		{
			if(max < num1[i])
			{
				max = num1[i];
				max_index = i;
			}
		}
		
		//exchange to start_scan position
			//exchange num1
		num1[max_index] = num1[start_scan];
		num1[start_scan] = max;
			//exchange num2
		int transfer;
		transfer = num2[start_scan];
		num2[start_scan] = num2[max_index];
		num2[max_index] = transfer;
		
		//update the start_scan location
		start_scan++;
	} while (start_scan < 5);
	
	
	//after the do/while loop, the array is in order
	//print out the array
	for (int i=0; i<5; i++)
		std::cout << num2[i] << "   " << num1[i] << std::endl;
	
	return 0;		
	
}

}

Oct-31 Morning Practice
Repeat the two basic searching and sorting technique.

1. Two basic searching algorithm: linear search and binary search

0) A searching algorithm can find and locate specific term in a collection of data.

1) Linear Search

{
The strategy for linear search is to scan through the array, from the beginning to the end,
 to find out if the term exists in the array. For an array of size N, the typical search 
 time is N/2.
 
 #include <iostream>
 #include <cstdlib>
 #include <ctime>
 #include <vector>
 
 const int SIZE = 100; //the size of the array
 const int N_MAX = 1000; //the maximum of random number
 const int N_MIN = 1; //the minimum of random number
 
 void random_creater(int num[]);
 void linear_search(int num[], std::vector<int> &match_position, int value);
 
 int main()
 {
	//define an array, and call random creater to generate a random array
	int num[SIZE];
	random_creater(num);
	 
	//ask user to input a number
	int value;
	std::cout << "Please input a value to check (range: " << N_MIN << " ~ " << N_MAX <<": ";
	std::cin >> value;

	//call linear searching function to search if value is in the array. Record the position
	//of each match
		//create a vector to store match position
	std::vector<int> match_position;
	linear_search(num, match_position, value);
	
	//display result
	if (match_position.size() == 0)
		std::cout << "No matches.\n";
	else
	{
		std::cout << "Matches found! The positions are:\n";
		for (int i=0; i<match_position.size(); i++)
			std::cout << match_position[i] << std::endl;
	}
	std::cout << endl;
	
	return 0;
 }

 //initiate array with random number
void random_creater(int num[])
{
	int seed;
	seed = time(0);
	srand(seed);
	
	for (int i=0; i<SIZE; i++)
		num[i] = rand()%(N_MAX-N_MIN+1)+N_MIN;
}

//linear search function
 void linear_search(int num[], std::vector<int> &match_position, int value)
 {
	 for (int i=0; i<SIZE; i++)
	 {
		 if (num[i] == value)
			 match_position.push_back(i);
	 }
 }
 
}

2) Binary Search
Binary search is much more efficient than linear search, if the goal is only to find out 
whether the array contains a specific value, and the array is in ascending or descending 
order.

Suppose the array is in ascending order, and we want to find out if value is in the array. 
First, we go to the middle of the entire array. We check if the middle element is equal to 
value. If not, we compare middle element with value. If value is greater than the middle 
element, we know that if there is a match term, it must locate somewhere in the second half 
of the array. Otherwise, if value is smaller than the middle element, the matched term, if 
there is any, should locate in the first half of the array. We shrink the size of searching 
scope by this judge. Then we check if the middle element of the new scope is equal, greater or 
smaller than the value. This process is repeated until we find the matched term, or the lower 
limit exceeds the higher limit (which suggest there is no matched term in this array).

In binary search, you need following variables:
a) two scope limit variable. It controls the range of searching and termination of searching. 
	low_limit, high_limit. Subscript is stored in these variables.
b) middle. It is the middle between low_limit and high_limit. It is where the function judge 
	the value.
c) a variable to store the search value.

Use a do/while loop to control the searching

Pseudocode (suppose the array is in asceding order)
define low_limit and high_limit;
do
{
	calculate middle, middle = (low_limit+high_limit)/2;
	check middle vs value 
		middle == value: matched; return middle! //middle is the subscript of the matched element
		middle > value: high_limit = middle -1; break;
		middle < value: low_limit = middle +1; break;
} while (low_limit <= high_limit);

Code:
{

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

const int SIZE = 300; //the size of the array
const int N_MAX = 10000; //the maximum of random number
const int N_MIN = 1; //the minimum of random number

//function prototype
void random_creater(int num[]);
void print_array(int num[]);
void selection_sort(int num[]);
void binary_search(int num[], int value, std::vector<int> &match);

int main()
{
	//create an array using random_creater
	int num[SIZE];
	random_creater(num);
	
	//call selection sorting function to sort the array in 
	selection_sort(num);
	
	//ask user to input a value to search, repeat as long as the user wish
	char choice;
	do
	{
		std::cout << "Please input a number to search: (range: " << N_MIN << " ~ " << N_MAX << ": ";
		int value;
		std::cin >> value;
		
		//call binary searching function to search
		std::vector<int> match;
		binary_search(num, value, match);
		
		//print out result
		if(match.size() == 0)
			std::cout << "No match!\n";
		else
		{
			std::cout << match.size() << " matches found! They are:\n";
			for (int i=0; i<match.size(); i++)
				std::cout << match[i]+1 << std::endl;
		}
		
		//ask for repeat
		std::cout << "\nWould you want to another search? (Y/N) ";
		std::cin >> choice;
			
	} while (choice == 'Y' || choice == 'y');
	
	//show the user exit information
	std::cout << "You quitted.\n";
	
	return 0;
	

}

//initiate array with random number
void random_creater(int num[])
{
	int seed;
	seed = time(0);
	srand(seed);

	for (int i = 0; i<SIZE; i++)
		num[i] = rand() % (N_MAX - N_MIN + 1) + N_MIN;
}

//print function
void print_array(int num[])
{
	for (int i=0; i<SIZE; i++)
		std::cout << num[i] << std::endl;
}

//Selection sorting function: descending order
void selection_sort(int num[])
{
	int start_scan = 0;

	
	do
	{
		int max = num[start_scan];
		int max_index = start_scan;
		//find maximum
		for (int i=start_scan; i<SIZE; i++)
			if(max < num[i])
			{
				max = num[i];
				max_index = i;
			}
		//exchange
		num[max_index] = num[start_scan];
		num[start_scan] = max;
		//update start_scan position
		start_scan++;
		
	} while (start_scan < SIZE-1);
	
}

//binary search function
void binary_search(int num[], int value, std::vector<int> &match)
{
	int low_limit = 0, high_limit = SIZE-1;
	do
	{
		int middle = (low_limit + high_limit)/2;
		if (num[middle] == value)
		{
			match.push_back(middle);
			low_limit = middle + 1; //this update will lose some information! Linear search is much
									 //more efficient when you want to search multiple repeated element									 
		}
		else if (num[middle] > value)
		{
			low_limit = middle + 1;
		}
		else
			high_limit = middle - 1;
	} while (low_limit <= high_limit);
}

}



2. Two basic sorting algorithm: bubble sorting and selection sorting
 
1) Bubble Sorting
Bubble sorting will go over the array from beginning to the next-to-last element.
Assume the scan position is i, it will compare the element in i and i+1 slot. Suppose 
we are doing a descending sorting (the first element is the largest). If element(i) is 
smaller than element(i+1), they will exchange position, so between the local two variables,
 the larger one is placed before the smaller one. After this operation, the scan position 
will move forward, to compare and manipulate the next pair: element(i+1) and element(i+1+1).
  
During one iteration, as long as the exchange is occured, it means the sorting isn't over. 

In bubble sorting, you need following variables
a) a flag variable to indicate whether exchange is occured during one iteration.
b) a transfer variable to exchange two elements

use a do/while loop to repeat the sorting as long as exchange is occured during the last 
sorting.

Code:
{
	
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

const int SIZE = 300; //the size of the array
const int N_MAX = 10000; //the maximum of random number
const int N_MIN = 1; //the minimum of random number

//function prototype
void random_creater(int num[]);
void print_array(int num[]);
void bubble_sort(int num[]);

int main()
{
	//create an array using random_creater
	int num[SIZE];
	random_creater(num);
	
	//print the array before sorting
	std::cout << "Before sorting: \n";
	print_array(num);
	
	//call bubble sorting function
	bubble_sort(num);
	
	//print again
	std::cout << "After sorting:\n";
	print_array(num);
}

//initiate array with random number
void random_creater(int num[])
{
	int seed;
	seed = time(0);
	srand(seed);

	for (int i = 0; i<SIZE; i++)
		num[i] = rand() % (N_MAX - N_MIN + 1) + N_MIN;
}

//print function
void print_array(int num[])
{
	for (int i=0; i<SIZE; i++)
		std::cout << num[i] << std::endl;
}

//bubble sorting function
void bubble_sort(int num[])
{
	bool exchange;
	do
	{
		exchange = false;
		for (int i=0; i<SIZE-1; i++)
		{
			if(num[i] < num[i+1])
			{
				int transfer;
				transfer = num[i];
				num[i] = num[i+1];
				num[i+1] = transfer;
				exchange = true; //change flag
			}
		}
	} while (exchange);
}



}

2) Selection Sorting
Selection sorting is another way to sort data. Unlike bubble sorting (typically, one element
can only move one step each run), selection sorting can place one element to its final 
destination using one iteration.

Selection algorithm is working like this (assume we are doing a ascending sort). First, 
it scans the entire array, and find out the minimum value and its corresponding subscripte, 
min_index. Then, it will exchange the element stored in the first slot (subscript == 0) with 
the min element (subscript == min_index). Then, it begin another scan, however, this time, 
it will start from the second slot (because first slot has already filled with the smallest
value in the entire array). This is done by updating the start_scan indicator (increment).
This process is repeated until the entire array has been scaned, till the next-to-last element.
(no need to scan the last element because there is only one left, nothing to exchange, and 
this last element must be the biggest because of the last exchanging will exchange the last 
two elements, placing bigger one to the last position). 

In selection sorting, you need the following variables:
a) a start scan position indicator.
b) a min/max variable to hold the minimum or maximum value when scanning through the array
c) a min_index/max_index to hold the subscript of minimum or maximum element
//d) a transfer variable to exchange two elements (we don't need this)

A do/while loop is used to control the end point (when start_scan == SIZE-2)

Pseudocode:
set the start_scan code to 0
do
{
	reset max and max_index to start_scan element
	go over the array, find the minimum or maximum 
	record the subscript of the minimum or maximum element
	exchange the min/max element with the element at start_scan (min_index/max_index is used)
	update the start_scan
} while (start_scan < SIZE-1);


Code:

{
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

const int SIZE = 300; //the size of the array
const int N_MAX = 10000; //the maximum of random number
const int N_MIN = 1; //the minimum of random number

//function prototype
void random_creater(int num[]);
void print_array(int num[]);
void selection_sort(int num[]);

int main()
{
	//create an array using random_creater
	int num[SIZE];
	random_creater(num);
	
	//print the array before sorting
	std::cout << "Before sorting: \n";
	print_array(num);
	
	//call selection sorting function
	selection_sort(num);
	
	//print again
	std::cout << "After sorting:\n";
	print_array(num);
}

//initiate array with random number
void random_creater(int num[])
{
	int seed;
	seed = time(0);
	srand(seed);

	for (int i = 0; i<SIZE; i++)
		num[i] = rand() % (N_MAX - N_MIN + 1) + N_MIN;
}

//print function
void print_array(int num[])
{
	for (int i=0; i<SIZE; i++)
		std::cout << num[i] << std::endl;
}

//Selection sorting function
void selection_sort(int num[])
{
	int start_scan = 0;

	
	do
	{
		int max = num[start_scan];
		int max_index = start_scan;
		//find maximum
		for (int i=start_scan; i<SIZE; i++)
			if(max < num[i])
			{
				max = num[i];
				max_index = i;
			}
		//exchange
		num[max_index] = num[start_scan];
		num[start_scan] = max;
		//update start_scan position
		start_scan++;
		
	} while (start_scan < SIZE-1);
	
}


}


Program 8-7: Use vector to re-write program 8-6
Code:
{
//8-6. Case Study: Sales Ranking Report
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

const int NUM = 9;

//function prototype
void read_data(std::string product_title[], std::string product_description[], int product_number[], double product_price[], int unit_sale[]);
void calc_sale(double product_price[], int unit_sale[], double product_sale[]);
void sort_sale(double product_sale_sort[], double const product_sale[], int rank[]);
void print_report(std::string product_title[], std::string product_description[], int product_number[], double product_price[], int unit_sale[], int rank[], double product_sale[]);

int main()
{
	std::string product_title[NUM], product_description[NUM];
	int product_number[NUM], unit_sale[NUM], rank[NUM];
	double product_sale[NUM], product_price[NUM];

	//call read_data function to load data into the container
	read_data(product_title, product_description, product_number, product_price, unit_sale);

	//call calc_sale function to calculate the sales for each product, sale the amount into
	calc_sale(product_price, unit_sale, product_sale);

	//create a copy of product_sale array, this copy is used to generate sale rank[] array
	double product_sale_sort[NUM];
	for (int i = 0; i<NUM; i++)
	{
		product_sale_sort[i] = product_sale[i];
	}

	//call sort_sale function to get the rank information
	sort_sale(product_sale_sort, product_sale, rank);

	//call for print function to print the report (also do the calculation to get total number of all units sold, total sales)
	print_report(product_title, product_description, product_number, product_price, unit_sale, rank, product_sale);
	//notify processing complete
	std::cout << "The processing is complete, please check the file for details.\n";

	return 0;

}

void read_data(std::string product_title[], std::string product_description[], int product_number[], double product_price[], int unit_sale[])
{
	//creat a file streamer: read
	std::ifstream cin;
	cin.open("D:\\data_base.txt");

	//use a for loop to load all the data
	for (int i = 0; i<NUM; i++)
	{
		getline(cin, product_title[i]);
		getline(cin, product_description[i]);
		cin >> product_number[i];
		cin >> product_price[i];
		cin >> unit_sale[i];
		cin.ignore(); //the next getline function may input the newline character?
	}

	//close file
	cin.close();
}

void calc_sale(double product_price[], int unit_sale[], double product_sale[])
{
	/*
	This function will use a loop to calculate the sale amount for each product
	*/

	for (int i = 0; i<NUM; i++)
	{
		product_sale[i] = product_price[i] * unit_sale[i];
	}
}

void sort_sale(double product_sale_sort[], double const product_sale[], int rank[])
{
	int start_scan = 0, max_index;
	double max; //used to store the maximum sale

	do
	{
		max = product_sale_sort[start_scan];
		max_index = start_scan;

		//find the highest value and the corresponding index
		for (int i = start_scan; i<NUM; i++)
		{
			if (max < product_sale_sort[i])
			{
				max = product_sale_sort[i];
				max_index = i;
			}
		}

		//exchange element
		product_sale_sort[max_index] = product_sale_sort[start_scan];
		product_sale_sort[start_scan] = max;

		//after the highest value is put into the start_scan slot, update the start_scan position
		start_scan++;

	} while (start_scan < NUM);

	//after the do/while loop, product_sale_sort is a descending order array, now try to search for the index
	for (int i = 0; i < NUM; i++)
	{
		//find out the j index when product_sale_sort[i] == product_sale[j], store the value of j into rank[i]
		//linear search approach
		int j; //define a counter
		for (j = 0; j < NUM; j++)
			if (product_sale[j] == product_sale_sort[i])
				break;
		rank[i] = j; //the index is stored in rank[] 
					 //binary search approach is not applicable here because we don't want to know if one specific value
					 //is in the array (we know this for sure!). What we want to know, is the index number of the product-
					 //-sale in the descending order
	}

}

void print_report(std::string product_title[], std::string product_description[], int product_number[], double product_price[], int unit_sale[], int rank[], double product_sale[])
{
	//create a file streamer: write
	std::ofstream cout;
	cout.open("D:\\Sales Report.txt");

	//write table header
	cout << "Product Number            Product Title            Product Price($)        Unit Sold         Sales($)\n";
	cout << "------------------------------------------------------------------------------------------------------------\n";

	//set the printing format
	cout << std::setprecision(2) << std::fixed;

	//use a loop to print out all ranking
	for (int i = 0; i<NUM; i++)
	{
		cout << std::setw(10) << product_number[rank[i]] << std::setw(35) << product_title[rank[i]] << std::setw(17) << product_price[rank[i]] << std::setw(21) << unit_sale[rank[i]] << std::setw(20) << product_sale[rank[i]] << std::endl;
	}

	//print the table tail
	cout << "------------------------------------------------------------------------------------------------------------\n\n";

	//calculate the total number of units sold (use a loop to go over unit_sale)
	int total_unit = 0;
	for (int i = 0; i<NUM; i++)
		total_unit += unit_sale[i];

	//calculate the total number of sales (use a loop to go over product_sale)
	double total_sale = 0;
	for (int i = 0; i<NUM; i++)
		total_sale += product_sale[i];

	//print to the file
	cout << "Total units sold during the past six months: " << total_unit << "\n";
	cout << "Total sales: $" << total_sale << "\n";

	//disconnect streamer from file
	cout.close();
}

}

/**************************/
/**Programming Challenges**/
/**************************/

1. Charge Account Validation
Objective: ask a user to enter a charge account number, then search the data base to see
if the input is valid.

Code
{
#include <iostream>
#include <fstream>
#include <vector>

//function prototype
void read_data(std::vector<int> &account_number);
int linear_search(std::vector<int> account_number, int number);

int main()
{
	//define a container, call read_data function to read data from file
	std::vector<int> account_number;
	read_data(account_number);
	
	//ask user to enter a number to check
	std::cout << "Please input a number to check: ";
	int number;
	std::cin >> number;
	
	//call linear search function to check if the number is in the array
	int result;
	result = linear_search(account_number, number);
	
	//check result
	if(result)
		std::cout << "The number is valid.\n";
	else
		std::cout << "The number is invalid.\n";
	
	return 0;
}

//read_data function
void read_data(std::vector<int> &account_number)
{
	std::ifstream cin;
	cin.open("D:\\8-1 data.txt");
	
	int transfer;
	while(cin >> transfer)
		account_number.push_back(transfer);
	
	cin.close();
}

//search function
int linear_search(std::vector<int> account_number, int number)
{
	for (int i=0; i<account_number.size(); i++)
	{
		if (account_number[i] == number)
			return 1;
	}
	
	return 0;
}


}


2. Lottery Winners-linear search
Objective:
	1) load the winning ticket into a vector
	2) ask the user to input 10 tickets
	3) go over all the numbers the user entered, to see if they are within the winning ticket
	4) display whether or not the user has a winning ticket, if he does, display how many of them

Code:
{
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
	A linear searching algorithm is used
	*/
	
	for (int i=0;i<user_lottery.size();i++)
	{
		for (int j=0;j<win_lottery.size();j++)
		{
			if(user_lottery[i] == win_lottery[j])
			{
				match.push_back(i);
			}
		}
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


}

3. Lottery Winner Modification-binary search
Objective: use binary search instead of linear search to find out the winning lottery

Code:
{
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


}

4. Charge Account Validation Modification
Objective: use a binary searching algorithm to search the number. Before that, use a 
selection algorithm to sort the array.

Code
{
#include <iostream>
#include <fstream>
#include <vector>

//function prototype
void read_data(std::vector<int> &account_number);
void selection_sort(std::vector<int> &account_number);
int linear_search(std::vector<int> account_number, int number);
int binary_search(std::vector<int> account_number, int number);

int main()
{
	//define a container, call read_data function to read data from file, then sort it
	std::vector<int> account_number;
	read_data(account_number);
	selection_sort(account_number);
	
	//ask user to enter a number to check
	std::cout << "Please input a number to check: ";
	int number;
	std::cin >> number;
	
	//call linear search function to check if the number is in the array
	int result;
	result = binary_search(account_number, number);
	
	//check result
	if(result)
		std::cout << "The number is valid.\n";
	else
		std::cout << "The number is invalid.\n";
	
	return 0;
}

//read_data function
void read_data(std::vector<int> &account_number)
{
	std::ifstream cin;
	cin.open("D:\\8-1 data.txt");
	
	int transfer;
	while(cin >> transfer)
		account_number.push_back(transfer);
	
	cin.close();
}

//sorting function. Sort the vector so the binary searching algorithm can be used
void selection_sort(std::vector<int> &account_number)
{
	int start_scan = 0;
	int min, min_index;
	
	do
	{
		//re-set min and min_index
		min = account_number[start_scan];
		min_index = start_scan;
		
		//go over to find out the minimum
		for(int i=start_scan;i<account_number.size();i++)
		{
			if(min > account_number[i])
			{
				min = account_number[i];
				min_index = i;
			}
		}
		
		//exchange
		account_number[min_index] = account_number[start_scan];
		account_number[start_scan] = min;
		
		//update start_scan indicator
		start_scan++;
		
	} while (start_scan < account_number.size());
		
}

//linear search function
int linear_search(std::vector<int> account_number, int number)
{
	for (int i=0; i<account_number.size(); i++)
	{
		if (account_number[i] == number)
			return 1;
	}
	
	return 0;
}

//binary search function
int binary_search(std::vector<int> account_number, int number)
{
	int first = 0, last = account_number.size()-1;
	
	do
	{
		int middle = (first+last)/2;
		
		if (account_number[middle] == number)
			return middle;
		else if (account_number[middle] > number)
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
	
	return 0;
}

}

5. Rainfall Statistics Modification
Objective:
When running the rainfall statistics program, you'll be prompted to input the rainfall 
data for each month in a year. 
Then, you display a table, it shows the month from highest rainfall to lowest fainfall

	1) algorithm
{
Use a copied rainfall array to generate the ranking of rainfall. And then print.
This method is based on selection sorting algorithm. /*Every time the max_index is 
stored into a vector (rank) (this is wrong!)*/. During the iteration, after max is found,
the rain_fall array is went through and the corresponding index is found and stored into 
the rank vector, so the vector rank contains the ranking info (the ranking and the 
corresponding index)

}

	2) Code
{
#include<iostream>
#include<vector>

void total_average(double rain_fall[], int size);
void find_high_low(double rain_fall[], int size);
void get_data(double rain_fall[], int size);
void get_rank(std::vector<int> &rank, double rain_fall_sort[], double rain_fall[]);

//global constant
const int MONTH = 12;
	
int main()
{
	double rain_fall[MONTH];

	//get data
	get_data(rain_fall, MONTH);

	//calculate total rainfall and average
	total_average(rain_fall, MONTH);

	//find highest and lowest rainfall
	find_high_low(rain_fall, MONTH);
	
	//generate a copy of rain_fall array
	double rain_fall_sort[MONTH];
	for(int i=0;i<MONTH;i++)
		rain_fall_sort[i] = rain_fall[i];
	
	//define a ranking container, and use get_rank function to get the ranking info
	std::vector<int> rank;
	get_rank(rank, rain_fall_sort, rain_fall);
	
	//print out the months, in the order of highest rainfall to lowest rainfall
	for(int i=0;i<MONTH;i++)
	{
		std::cout << "Month " << rank[i]+1 << "  Rainfall: " <<rain_fall[rank[i]] << std::endl;
	}
	std::cout << "\n";
	

	return 0;
}

//calculate total and average of the data
void total_average(double rain_fall[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += rain_fall[i];
	}

	//display total and average
	std::cout << "The total rainfall is: " << total << "\n";
	std::cout << "The average rainfall is: " << total / size << "\n";

}

//find highest and lowest
void find_high_low(double rain_fall[], int size)
{
	double high, low;
	int high_month, low_month;
	high = rain_fall[0];
	high_month = 1;
	low = rain_fall[0];
	low_month = 1;

	for (int i = 1; i < size; i++)
	{
		if (high < rain_fall[i])
		{
			high = rain_fall[i];
			high_month = i + 1;
		}

		if (low > rain_fall[i])
		{
			low = rain_fall[i];
			low_month = i + 1;
		}

	}
	
	//display result
	std::cout << "The highest rainfall is in month " << high_month << ", with a rainfall of " << high << "\n";
	std::cout << "The lowest rainfall is in month " << low_month << ", with a rainfall of " << low << "\n";

}

//data input program
void get_data(double rain_fall[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "What is the rainfall for month " << i + 1 << ": ";
		std::cin >> rain_fall[i];
		while (rain_fall[i] < 0)
		{
			std::cout << "Please input rainfall data greater than zero: ";
			std::cin >> rain_fall[i];
		}
	}
}

//generate the rank
void get_rank(std::vector<int> &rank, double rain_fall_sort[], double rain_fall[])
{
	int start_scan = 0;
	do
	{
		double max = rain_fall_sort[start_scan];
		int max_index = start_scan;
		
		//find out the maximum
		for(int i=start_scan;i<MONTH;i++)
		{
			if(max < rain_fall_sort[i])
			{
				max = rain_fall_sort[i];
				max_index = i;
			}
		}
		
		//store max_index in rank
		for(int i=0;i<MONTH;i++)
			if(rain_fall[i] == max)
				rank.push_back(i);
		
		//exchange
		rain_fall_sort[max_index] = rain_fall_sort[start_scan];
		rain_fall_sort[start_scan] = max;
		
		//update start_scan
		start_scan++;
		
	} while (start_scan < MONTH); //rank[] needs to record till the last element, 
								   //so, you can't use start_scan < MONTH-1;
}

}

6. String Selection Sort
Objective
use selection sorting algorithm to sort string

Code
{

#include <iostream>
#include <string>

const int NUM_NAMES = 20;
//function prototype
void print(std::string names[]);
void selection_sort(std::string names[]);

//driver
int main()
{

	std::string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
		"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
		"Taylor, Terri", "Johnson, Jill",
		"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
		"James, Jean", "Weaver, Jim", "Pore, Bob",
		"Rutherford, Greg", "Javens, Renee",
		"Harrison, Rose", "Setzer, Cathy",
		"Pike, Gordon", "Holland, Beth" };
	
	std::cout << "Before sorting:\n";
	print(names);
	
	//call sorting function to sort the string array
	selection_sort(names);
	
	//print the names again
	std::cout << "After sorting:\n";
	print(names);
	
	return 0;
}

void print(std::string names[])
{
	for(int i=0; i<NUM_NAMES;i++)
		std::cout << names[i] <<std::endl;
	std::cout << "\n";
}

//sorting function
void selection_sort(std::string names[])
{
	std::string min;
	int start_scan = 0, min_index;
	
	do
	{
		min = names[start_scan];
		min_index = start_scan;
		
		//go over the array to find out the lowest
		for(int i=start_scan;i<NUM_NAMES;i++)
		{
			if(min > names[i])
			{
				min = names[i];
				min_index = i;
			}
		}
		
		//exchange
		names[min_index] = names[start_scan];
		names[start_scan] = min;
		
		//update start_scan index
		start_scan++;
	} while (start_scan < NUM_NAMES - 1);
}


}


7. Binary String Search
Objective
Apply binary searching algorithm on stringstream

Code
{

#include <iostream>
#include <string>

const int NUM_NAMES = 20;
//function prototype
void print(std::string names[]);
void selection_sort(std::string names[]);
void input_name(std::string &name);
int binary_search(std::string names[], std::string name);

//driver
int main()
{

	std::string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
		"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
		"Taylor, Terri", "Johnson, Jill",
		"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
		"James, Jean", "Weaver, Jim", "Pore, Bob",
		"Rutherford, Greg", "Javens, Renee",
		"Harrison, Rose", "Setzer, Cathy",
		"Pike, Gordon", "Holland, Beth" };	
	
	//call sorting function to sort the string array
	selection_sort(names);
	
	//ask the user to input a name to search
	std::string name;
	input_name(name);
	
	//call binary search function to search for the array, and return result
	int result;
	result = binary_search(names, name);
	
	//print out result
	if(result)
		std::cout << "Your inputted name is in the list.\n";
	else
		std::cout << "You inputted name is not in the list.\n";
	
	return 0;
}

void print(std::string names[])
{
	for(int i=0; i<NUM_NAMES;i++)
		std::cout << names[i] <<std::endl;
	std::cout << "\n";
}

//sorting function
void selection_sort(std::string names[])
{
	std::string min;
	int start_scan = 0, min_index;
	
	do
	{
		min = names[start_scan];
		min_index = start_scan;
		
		//go over the array to find out the lowest
		for(int i=start_scan;i<NUM_NAMES;i++)
		{
			if(min > names[i])
			{
				min = names[i];
				min_index = i;
			}
		}
		
		//exchange
		names[min_index] = names[start_scan];
		names[start_scan] = min;
		
		//update start_scan index
		start_scan++;
	} while (start_scan < NUM_NAMES - 1);
}

//ask user to input a name
void input_name(std::string &name)
{
	std::cout << "Please input a name to search: ";
	getline(std::cin, name);
}

//binary search
int binary_search(std::string names[], std::string name)
{
	int first = 0, last = NUM_NAMES-1;
	do
	{
		int middle = (first+last)/2;
		if(names[middle] == name)
			return 1;
		else if (names[middle] > name)
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
	
	return 0;
}

}

8. Search Benchmarks
> Objective
	perform linear and binary searching on a array containing 1000 integers, record the 
	number of comparisons each algorithm uses, and compare the two benchmark

> Code
{
	
#include <iostream>
#include <ctime>
#include <cstdlib>

const int NUM=100000, N_MIN=1, N_MAX=10000;

void random_creater(int num[]);
int linear_search(int num[], int value);
void selection_sort(int num[]);
int binary_search(int num[], int value);

int main()
{
	//create a random integer array
	int num[NUM];
	random_creater(num);
	
	//input search value
	std::cout << "Input a value to search: ";
	int value;
	std::cin >> value;
	
	//before sorting, use linear search function to search, and record number of comparisons
	int linear_benchmark;
	linear_benchmark = linear_search(num, value);
	
	//sort the array so a binary search can be used. Use a selection sorting technique
	selection_sort(num);
	
	//call binary search function to search, record number of comparisons
	int binary_benchmark;
	binary_benchmark = binary_search(num, value);
	
	//print out the benchmark, if the value is found
	if(linear_benchmark)
	{
		std::cout << "Linear search benchmark: " << linear_benchmark << std::endl
			  << "Binary search benchmark: " << binary_benchmark << std::endl;
	}
	else
		std::cout << "The value is not in the list.\n";
	
	return 0;
}

void random_creater(int num[])
{
	int seed;
	seed = time(0);
	srand(seed);

	for (int i = 0; i<NUM; i++)
		num[i] = rand() % (N_MAX - N_MIN + 1) + N_MIN;
}

//linear search function
int linear_search(int num[], int value)
{
	int counter = 0;
	for(int i=0;i<NUM;i++)
	{
		if(num[i] == value)
		{
			counter++;
			return counter;
		}
		counter++;
	}
	
	//return 0 if no match found
	return 0;
}

//selection sort
void selection_sort(int num[])
{
	int start_scan = 0;
	do
	{
		int min = num[start_scan];
		int min_index = start_scan;
		for(int i=start_scan;i<NUM;i++)
			if(min > num[i])
			{
				min = num[i];
				min_index = i;
			}
		//exchange
		num[min_index] = num[start_scan];
		num[start_scan] = min;
		
		//update start_scan index
		start_scan++;
		
	} while (start_scan < NUM-1);
	
}

//binary search function
int binary_search(int num[], int value)
{
	int counter = 0;
	int first = 0, last = NUM-1;
	do
	{
		int middle = (first+last)/2;
		if(num[middle] == value)
		{
			counter++;
			return counter;
		}
		else if (num[middle] > value)
		{
			counter++;
			last = middle - 1;
			continue;
		}
		else
		{
			counter++;
			first = middle + 1;
			continue;
		}
	} while (first <= last);
	
	return 0;
}


}

9. Sorting Benchmarks
> Objective
	Perform bubble and selection sorting on a array. Record the number of exchanges each 
	algorithms uses, and compare the two benchmark

> Code
{

	
#include <iostream>
#include <ctime>
#include <cstdlib>

const int NUM=1000, N_MIN=1, N_MAX=10000;

//function prototype
void random_creater(int num[]);
int selection_sort(int num[]);
int bubble_sort(int num[]);

int main()
{
	//create a random integer array, and duplicate. So selection and bubble can use same array
	int num[NUM], num1[NUM];
	random_creater(num);
	for(int i=0;i<NUM;i++)
		num1[i] = num[i];	
	
	//sort the array using a selection sorting technique
	int selection_benchmark;
	selection_benchmark = selection_sort(num);
	
	//sort the array using a bubble sorting technique
	int bubble_benchmark;
	bubble_benchmark = bubble_sort(num1);
	
	//print and compare
	std::cout << "The selection sorting benchmark: " << selection_benchmark << "\n";
	std::cout << "The bubble sorting benchmark: " << bubble_benchmark << "\n";
	
	return 0;
}

void random_creater(int num[])
{
	int seed;
	seed = time(0);
	srand(seed);

	for (int i = 0; i<NUM; i++)
		num[i] = rand() % (N_MAX - N_MIN + 1) + N_MIN;
}


//selection sort
int selection_sort(int num[])
{
	int start_scan = 0;
	int counter = 0;
	do
	{
		int min = num[start_scan];
		int min_index = start_scan;
		for(int i=start_scan;i<NUM;i++)
			if(min > num[i])
			{
				min = num[i];
				min_index = i;
			}
		//exchange
		num[min_index] = num[start_scan];
		num[start_scan] = min;
		counter++;
		
		//update start_scan index
		start_scan++;
		
	} while (start_scan < NUM-1);
	
	return counter;
	
}

//bubble sort
int bubble_sort(int num[])
{
	int counter = 0;
	bool exchanged;
	do
	{
		exchanged = false; //don't forget to set exchange flag to false at the beginning of each iteration
		for(int i=0;i<NUM-1;i++)
		{
			if(num[i] > num[i+1])
			{
				int transfer;
				transfer = num[i];
				num[i] = num[i+1];
				num[i+1] = transfer;
				counter++; //update the counter
				exchanged = true; //set status of exchange to true
			}
		}
	} while (exchanged);
	
	return counter;
}

}

10. Sorting Orders
> Objective
	> begin with two identical integer array.
	> sort with selection and bubble algorithm, however, show the array after each sorting step

> Code

{
#include <iostream>

//function prototype
void selection_sort(int num[]);
void bubble_sort(int num[]);

int main()
{
	//create the array
	int num1[8] = { 2,9,4,5,6,7,1,3 };
	int num2[8] = { 2,9,4,5,6,7,1,3 };
	
	//sort by bubble algorithm
	bubble_sort(num1);
	
	//separate
	std::cout << "\n\n\n\n\n";
	
	//sort by selection algorithm
	selection_sort(num2);
	
	return 0;
}

void selection_sort(int num[])
{
	int start_scan = 0;
	do
	{
		int min = num[start_scan];
		int min_index = start_scan;
		
		for(int i=start_scan; i<8; i++)
		{
			if(min > num[i])
			{
				min = num[i];
				min_index = i;
			}
		}
		
		//exchange
		num[min_index] = num[start_scan];
		num[start_scan] = min;
		
		//print the array after one run
		for(int i=0;i<8;i++)
			std::cout << num[i] << " ";
		std::cout << "\n";
		
		//update start_scan
		start_scan++;
		
	} while (start_scan < 7);
}

void bubble_sort(int num[])
{
	bool exchanged;
	do
	{
		exchanged = false;
		for(int i=0;i<7;i++)
		{
			if(num[i] > num[i+1])
			{
				int transfer;
				transfer = num[i];
				num[i] = num[i+1];
				num[i+1] = transfer;
				exchanged = true; //set exchange flag if exchange is occured
			}
		}
		//print the array after one iteration
		for(int i=0;i<8;i++)
			std::cout << num[i] << " ";
		std::cout << "\n";
		
	} while (exchanged);
}

}

11. Using Files-String Selection Sort Modification
> Objective: 
	load string info from a file and then sort it, then store in the file
> Code

11-1. Code for creating a file containing names
{

#include <fstream>
#include <string>
#include <iostream>

int main()
{
	//create a string
	std::string names[20] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
		"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
		"Taylor, Terri", "Johnson, Jill",
		"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
		"James, Jean", "Weaver, Jim", "Pore, Bob",
		"Rutherford, Greg", "Javens, Renee",
		"Harrison, Rose", "Setzer, Cathy",
		"Pike, Gordon", "Holland, Beth" };
	
	//create a file streamer: write
	std::ofstream cout;
	cout.open("D:\\names.txt");
	
	//write to file
	for (int i=0;i<20;i++)
		cout << names[i] << std::endl;
	
	cout.close();
	std::cout << "Printing complete.\n";
	
}

}

11-2. Code for the problem
{
#include <iostream>
#include <string>
#include <fstream>

void get_data(std::string names[]);
void selection_sort(std::string names[]);
void write_data(std::string names[]);

int main()
{
	//define a container
	std::string names[20];
	
	//call function to fill names[20] with data
	get_data(names);
	
	//call function to sort the data, in alphabetical order
	selection_sort(names);
	
	//call function to write data to a new txt file
	write_data(names);
	
	return 0;
}

void get_data(std::string names[])
{
	std::ifstream cin;
	cin.open("D:\\names.txt");
	
	for(int i=0;i<20;i++)
	{
		getline(cin, names[i]);
	}
	
	cin.close();
}

void selection_sort(std::string names[])
{
	int start_scan = 0;
	do
	{
		std::string min = names[start_scan];
		int min_index = start_scan;
		for(int i=start_scan;i<20;i++)
			if(min > names[i])
			{
				min = names[i];
				min_index = i;
			}
		names[min_index] = names[start_scan];
		names[start_scan] = min;
		
		start_scan++;
	} while (start_scan < 19);
	
}

void write_data(std::string names[])
{
	std::ofstream cout;
	cout.open("D:\\names-sorted.txt");
	
	for(int i=0;i<20;i++)
		cout << names[i] << std::endl;
	cout.close();
	
	//notify the user
	std::cout << "The sorted data has already been written to names-sorted.txt\n";
}

}


11-01 Morning practice
1. Two searching technique
1) linear search
Code
{
#include <iostream>

int linear_search(int num[], int value);

int main()
{
	int num[5] = { 2,3,4,5,1 };
	int result, value;
	
	std::cout << "Input a value:\n";
	std::cin >> value;
	
	result = linear_search(num, value);
	
	if(result)
		std::cout << "Value is in the list.\n";
	else
		std::cout << "Value is not in the list.\n";
	
	return 0;
	
}

int linear_search(int num[], int value)
{
	for (int i=0; i<5; i++)
		if(num[i] == value)
			return i+1;
	return 0;
}


}

2) binary search
Code
{
#include <iostream>

int binary_search(int num[], int value);

int main()
{
	int num[5] = { 1,2,3,4,5 };
	int result, value;
	
	std::cout << "Input a value: ";
	std::cin >> value;
	
	result = binary_search(num, value);
	
	if(result)
		std::cout << "Value is in the list.\n";
	else
		std::cout << "Value is not in the list.\n";	
	
	return 0;
}

int binary_search(int num[], int value)
{
	int first = 0, last = 5-1;
	do
	{
		int middle = (first+last)/2;
		if(num[middle] == value)
			return middle+1;
		else if (num[middle] > value)
		{
			last = middle - 1;
			continue;
		}
		else
			first = middle + 1;
		
	} while (first <= last);
	
	return 0;
}


}

2. Two sorting technique
1) Bubble sorting 2) Selection Sorting
Code
{

#include <iostream>

void bubble_sort(int num[]);
void selection_sort(int num[]);

int main()
{
	int num[5] = { 2,1,4,5,3 };
	int num2[5] = { 4,5,2,1,3 };
	
	std::cout << "Bubble sorting:\n";
	std::cout << "Before sorting: ";
	for (int i=0;i<5;i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
	
	bubble_sort(num);

	std::cout << "After sorting: ";
	for (int i=0;i<5;i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;	
	
	std::cout << "Selection sorting:\n";
	std::cout << "Before sorting: ";
	for (int i=0;i<5;i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
	
	selection_sort(num);

	std::cout << "After sorting: ";
	for (int i=0;i<5;i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
	
}

void bubble_sort(int num[])
{
	bool exchange;
	do
	{
		exchange = false;
		for(int i=0; i<4; i++)
		{
			if(num[i] > num[i+1])
			{
				int transfer;
				transfer = num[i];
				num[i] = num[i+1];
				num[i+1] = transfer;
				exchange = true;
			}
		}
	} while (exchange);
}

void selection_sort(int num[])
{
	int start_scan = 0;
	do
	{
		int min = num[start_scan];
		int min_index = start_scan;
		for(int i=start_scan; i<5; i++)
			if(min > num[i])
			{
				min = num[i];
				min_index = i;
			}
		
		num[min_index] = num[start_scan];
		num[start_scan] = min;
		
		start_scan++;
	} while (start_scan < 4);
}


}

11-02. Morning Practice
1) two searching technique
a) linear search
key variable: counter

code:
int linear_search(int num[], int size, int value)
{
	for (int i=0; i<size; i++)
	{
		if (num[i] == value)
			return i+1;
	}
	
	return 0;
}

b) binary search
key variable: first, last, middle

code:
int binary_search(int num[], int size, int value)
{
	int first = 0, last = size - 1;
	do
	{
		int middle = (first+last)/2;
		if (num[middle] == value)
			return middle;
		else if (num[middle] > value)
			last = middle - 1; //the array is an ascending array
		else
			first = middle + 1;
	} while (first <= last);
	
	return 0;
}

2) two sorting technique

a) bubble sort
key variable: transfer, used to exchange two elements; exchanged: to record the status of being exchanged or not.
code:
void bubble_search(int *num, int size)
{
	do
	{
		bool exchange = false;
		for (int i=0; i<size-1; i++)
			if (num[i] > num[i+1])
			{
				int transfer;
				transfer = num[i];
				num[i] = num[i+1];
				num[i+1] = transfer;
				exchange = true;
			}		
	} while (exchange);

}

b) selection sort
key variable: start_scan, to show the starting scan location;
			   min/max, to store the min or max value, depends on descending or ascending order
			   min_index/max_index, store the subscript for min/max
code:
{
void selection_sort(int num[], int size)
{
	int start_scan = 0;
	do
	{
		int min = num[start_scan];
		int min_index = start_scan;
		
		for (int i=start_scan; i<size; i++)
		{
			if (min > num[i])
			{
				min = num[i];
				min_index = i;
			}
		}
		
		num[min_index] = num[start_scan];
		num[start_scan] = min;
		
		start_scan++;
	} while (start_scan < size-1);
}
	
	
}				  


11-03. Morning Practice (17 min)
{

1. two searching technique
1) linear search
Code:
{

int linear_search(int *num, int size, int value)
{
	for (int i=0; i<size; i++)
		if (num[i] == value)
			return i+1;
	return 0;
}

}

2) binary search (in a descending array)
Code
{

int binary_search(int num[], int size, int value)
{
	int first = 0, last = size-1;
	do
	{
		int middle = (first+last)/2;
		if (*(num+middle) == value)
			return middle+1;
		else if (*(num+middle) > value)
			first = middle+1;
		else
			last = middle-1;
	} while (first <= last);
	
	return 0;
}

}

2. two sorting technique 
1) bubble sorting (to descending order)
Code
{

void bubble_sort(int *num, int size)
{
	bool exchange;
	do
	{
		exchange = false;
		for (int i=0; i<size-1; i++)
			if (*(num+i) < *(num+i+1))
			{
				int transfer;
				transfer = *(num+i);
				*(num+i) = *(num+i+1);
				*(num+i+1) = transfer;
				exchange = true;
			}		
	} while (exchange);
	
}

}

2) selection sorting (to ascending order)
Code
{

void selection_sort(int *num, int size)
{
	int start_scan = 0;
	do
	{
		int min = *(num+start_scan);
		int min_index = start_scan;
		
		for(int i=start_scan; i<size; i++)
			if(min > *(num+i))
			{
				min = *(num+i);
				min_index = i;
			}
		
		*(num+min_index) = *(num+start_scan);
		*(num+start_scan) = min;
		
		start_scan++;
	} while (start_scan < size-1);
}

}

}







