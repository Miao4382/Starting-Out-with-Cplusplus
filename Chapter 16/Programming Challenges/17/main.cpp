#include "phone_book_entry.h"
#include <iostream>
#include <vector>

int main()
{
  std::vector<PhoneBookEntry> list;
  PhoneBookEntry temp;
  
  temp.set("name_1", "1223");
  list.push_back(temp);
  
  temp.set("name_2", "2321");
  list.push_back(temp);
  
  temp.set("name_3", "5334");
  list.push_back(temp);
  
  temp.set("name_4", "9875");
  list.push_back(temp);
  
  temp.set("name_5", "5763");
  list.push_back(temp);
  
  // print 
  std::vector<PhoneBookEntry>::iterator iter = list.begin();
  
  for (iter; iter != list.end(); iter++)
  {
    std::cout << "Name: " << iter->name() << "\n"
    << "Phone number: " << iter->phone() << "\n\n";
  }
  
  return 0;
}