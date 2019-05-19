#include "number_list_template_2.h"
#include <iostream>
#include <fstream>

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
  
  // after displaying average, low and high month, save the content in a file
  // open file in binary mode 
  std::fstream out;
  out.open("C:\\rain_data.dat", std::ios::out | std::ios::binary);
  
  // write data into file in binary mode (use write member function)
  // data in node should be written into the file one node by one node 
  ptr = rain.Begin();
  while (ptr != nullptr)
  {
    // write the current node into file 
    out.write(reinterpret_cast<char*>(ptr), sizeof(ListNode<double>));
    // move the navigation pointer to the next node 
    ptr = ptr->next;
  }

  out.close();
  
  // define another file stream object to read in binary mode 
  std::fstream in;
  in.open("C:\\rain_data.dat", std::ios::in | std::ios::binary);
  // create a temporary container to hold data read from the file 
  ListNode<double> temp_node(0);
  // create another linked list to hold the data 
  NumberList<double> read;
  // use a loop to read all record in file
  while (in.read(reinterpret_cast<char*>(&temp_node), sizeof(ListNode<double>)))
  {
    read.AppendNode(temp_node.value);
  }
  
  // display the read-record 
  std::cout << "Displaying data read:\n";
  read.DisplayList();
  
  // close file 
  in.close();
  
  
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

