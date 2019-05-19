// 2. Rainfall Statistics (modification with vector)
#include <iostream>
#include <vector>
#include <algorithm>

const int MONTH = 12;

void TotalAverage(std::vector<double> v);
void FindHighLow(std::vector<double> v);
void GetData(std::vector<double>& v);

int main()
{
  std::vector<double> rain_fall(MONTH);
  
  // get data 
  GetData(rain_fall);
  
  // calculate total rainfall and average
  TotalAverage(rain_fall);
  
  // find highest and lowest rainfall 
  FindHighLow(rain_fall);
  
  return 0;
}

void TotalAverage(std::vector<double> v)
{
  double total = 0;
  
  std::vector<double>::iterator iter = v.begin();
  
  for (iter; iter < v.end(); iter++)
    total += *iter;
  
  // display result 
	std::cout << "The total rainfall is: " << total << "\n";
	std::cout << "The average rainfall is: " << total / v.size() << "\n";
  
}

void FindHighLow(std::vector<double> v)
{
  std::vector<double>::iterator high, low;
  high = std::max_element(v.begin(), v.end());
  low = std::min_element(v.begin(), v.end());
  
	//display result
	std::cout << "The highest rainfall is in month " << high - v.begin() + 1 << ", with a rainfall of " << *high << "\n";
	std::cout << "The lowest rainfall is in month " << low - v.begin() + 1 << ", with a rainfall of " << *low << "\n";
  
}


void GetData(std::vector<double>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "What is the rainfall for month " << i + 1 << ": ";
		std::cin >> v[i];
		while (v[i] < 0)
		{
			std::cout << "Please input rainfall data greater than zero: ";
			std::cin >> v[i];
		}
	}  
}