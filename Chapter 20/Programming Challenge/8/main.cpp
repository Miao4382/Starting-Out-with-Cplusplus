#include "binary_search_tree_template.h"
#include "employee_info.h"
#include <string>
#include <iostream>

int main()
{
  // create a tree and initialize data base 
  BinarySearchTree<EmployeeInfo> database;
  
  EmployeeInfo employee[8] = { EmployeeInfo(1021, "John Williams"), EmployeeInfo(1057, "Bill Witherspoon"), EmployeeInfo(2487, "Jennifer Twain"), EmployeeInfo(3769, "Sophia Lancaster"), EmployeeInfo(1017, "Debbie Reece"), EmployeeInfo(1275, "George McMullen"), EmployeeInfo(1899, "Ashley Smith"), EmployeeInfo(4218, "Josh Plemmons") };
  
  for (int i = 0; i < 8; i++) {
    database.Add(employee[i]);
  }
  
  // ask user to input a number to search 
  int temp_id;
  std::cout << "Please input an id to search: ";
  std::cin >> temp_id;
  
  EmployeeInfo temp_search(temp_id); // create an object to search 
  EmployeeInfo* match = nullptr; // create a pointer to hold the search result 
  
  // search the tree
  match = database.Search(temp_search);
  if (match == nullptr)
    std::cout << "No match found.\n";
  else 
    std::cout << "Match found, name: " << match->name() << "\n";
  
  return 0;
}