//3. Chips and Salsa
#include<iostream>
#include<string>
#include <fstream>
#include <iomanip>

void get_data(int num[], std::string name[], int size);
int calc_total_high_low(int num[], int size);

int main()
{
	//string definition
	std::string salsa_name[5] = { "mild salsa","medium salsa", "sweet salsa","hot salsa","zesty salsa" };
	int salsa_num[5];

	//get salsa sale information
	get_data(salsa_num, salsa_name, 5);

	//calculate total sale, high sale and low sale information from one function (code and decode)
	int total_sale, high_ID, low_ID, result;
	result=calc_total_high_low(salsa_num, 5);
		//decode
	total_sale = result / 100;
	high_ID = (result % 100) / 10;
	low_ID = result % 10;

	//write report
	std::ofstream cout;
	cout.open("D:\\3-report.txt");
		//	table head
	cout << "Sales Figure\n"
		<< " Item name           Item sold\n"
		<< "---------------------------------\n";
		//	use an iteration to print all sales figure
	for (int i = 0; i < 5; i++)
	{
		cout << std::setw(13) << salsa_name[i] << std::setw(18) << salsa_num[i] << std::endl;
	}
		//print out total, highest sold and lowest sold, also table tail
	cout << std::setw(13) << "Total" << std::setw(18) << total_sale << std::endl;
	cout << std::setw(13) << "Highest Sold" << std::setw(18) << salsa_name[high_ID] << std::endl;
	cout << std::setw(13) << "Lowest Sold" << std::setw(18) << salsa_name[low_ID] << std::endl;
	cout << "---------------------------------\n";
	cout.close();

	return 0;
}

//get data
void get_data(int num[], std::string name[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "How many " << name[i] << " salsa is sold during the last month: ";
		std::cin >> num[i];
		while (num[i] < 0)
		{
			std::cout << "Please input non-negative sales figure: ";
			std::cin >> num[i];
		}
	}
}

//calculate highest and lowest, as well as total sale
int calc_total_high_low(int num[], int size)
{
	int total = 0, high = num[0], low = num[0];
	int high_ID = 0, low_ID = 0;

	for (int i = 0; i < size; i++)
	{
		total += num[i];
		if (high < num[i])
		{
			high = num[i];
			high_ID = i;
		}
		if (low > num[i])
		{
			low = num[i];
			low_ID = i;
		}
	}

	return total * 100 + high_ID * 10 + low_ID;
}