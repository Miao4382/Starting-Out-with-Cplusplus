#include "number_list_template_2.h"
#include <iostream>

void InputData(NumberList<double>& rain, int month);

int main()
{
  // ask user for the number of month
  int month;
  std::cout << "How many months data will be inputed: ";
  std::cin >> month;
  while (month <= 0)
  {
    std::cout << "At lease one month data should be inputed: ";
    std::cin >> month;
  }
  
  // input data 
  NumberList<double> rain; // linked list container to hold rainfall data 
  InputData(rain, month);
  
  // calculate statistical result
  // total rain fall 
  double total_rain_fall = 0;
  ListNode<double>* ptr = rain.Begin();
  while (ptr != nullptr)
  {
    total_rain_fall += ptr->value;
    ptr = ptr->next;
  }
  std::cout << "Total rain fall for " << month << " months is: " << total_rain_fall << "\n";
  
  // average 
  std::cout << "The average monthly rainfall is: " << total_rain_fall / month << "\n";
  
  // find highest and lowest
  ptr = rain.Begin();
  double high = ptr->value;
  double low = ptr->value;
  int high_index = 1;
  int low_index = 1;
  int index = 1;
  ptr = ptr->next;
  index++;
  
  while (ptr != nullptr)
  {
    if (high < ptr->value)
    {
      high = ptr->value;
      high_index = index;
    }
    
    if (low > ptr->value)
    {
      low = ptr->value;
      low_index = index;
    }
    
    ptr = ptr->next;
    index++;
      
  }
  
  std::cout << "The highest rain fall is in month " << high_index << ", with a rain fall of " << high << "\n";
  std::cout << "The lowest rainfall is in month " << low_index << ", with a rain fall of " << low << "\n";
  
  return 0;
  
  
}

void InputData(NumberList<double>& rain, int month)
{
  double rain_fall;
  
  for (int i = 0; i < month; i++)
  {
    std::cout << "Please input rain fall data for month " << i + 1 << ": ";
    std::cin >> rain_fall;
    while (rain_fall < 0)
    {
      std::cout << "Invalid rain fall data inputed, please input again: ";
      std::cin >> rain_fall;
    }
    
    rain.AppendNode(rain_fall);
  }
}

