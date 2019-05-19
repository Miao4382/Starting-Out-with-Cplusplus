//8-6. Case Study: Sales Ranking Report
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

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
