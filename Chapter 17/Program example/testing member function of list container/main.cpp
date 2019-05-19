#include <iostream>
#include <list>

int main()
{
  std::list<int> num;
  
  // add five elements to the list 
  for (int i = 0; i < 5; i++)
    num.push_back(i);
  
  // test list.back()
  std::cout << "The last element should be 4: " << num.back() << "\n";
  num.back()++;
  std::cout << "Now the last element should be 5: " << num.back() << "\n";
  
  // test list.empty() function and list.size() function
  if (num.empty())
    std::cout << "The list is empty" << "\n";
  else 
    std::cout << "The list is not empty, the size is: " << num.size() << "\n";
  
  // test list.end() and list.begin()
  std::list<int>::iterator iter;
  iter = num.end() - 1;
  std::cout << "Testing list.end() and list.begin(), the entire list will be printed in reverse order: ";
  for (iter; iter != num.begin(); iter--)
    std::cout << *iter << " ";
  std::cout << *iter << "\n";
  
  // test list.erase()
  num.erase(iter+2);
  std::cout << "Testing list.erase() function, the third element has been deleted:\n";
  iter = num.begin();
  for (iter; iter != num.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";
  
  // test list.insert()
  std::cout << "Now testing list.insert() function. 10 will be inserted to the third element:\n";
  num.insert(num.begin() + 3, 10);
  for (iter = num.begin(); iter != iter.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";
  
  // test list.pop_front()
  std::cout << "Testing list.pop_front(), 10 will be deleted: ";
  num.pop_front();
  for (iter = num.begin(); iter != iter.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";

  // test list.pop_back()
  std::cout << "Testing list.pop_back(), 5 will be deleted: ";
  num.pop_back();
  for (iter = num.begin(); iter != iter.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";

  // test list.push_front()
  std::cout << "Testing list.push_front(), 2 will be added to front: ";
  num.push_front(2);
  for (iter = num.begin(); iter != iter.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";  
  
  // test list.reverse()
  std::cout << "Testing list.reverse(), the order of the list will be reversed.\n";
  num.reverse();
  for (iter = num.begin(); iter != num.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";
  
  // test list.unique
  std::cout << "Now testing list.unique(). Adding some redundant element: ";
  num.insert(num.end() - 3, 3);
  num.insert(num.begin(), 3);
  for (iter = num.begin(); iter != num.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";
  
  num.unique();
  
  std::cout << "After calling list.unique(): ";
  for (iter = num.begin(); iter != num.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";
  
  // create two other list 
  std::list<int> list_1, list_2;
  for (int i = 1; i <= 12; i++)
  {
    if (i % 2)
      list_1.push_back(i);
    else 
      list_2.push_front(i);
  }
  
  std::cout << "Testing list.swap. Following lists are used:\n1: ";
  for (iter = list_1.begin(); iter != list_1.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n2: ";
  for (iter = list_2.begin(); iter != list_2.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";
  
  list_1.swap(list_2);
  std::cout << "After calling list_1.swap(list_2):\n1: ";
  for (iter = list_1.begin(); iter != list_1.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n2: ";
  for (iter = list_2.begin(); iter != list_2.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";  
  
  // test list.merge()
  std::cout << "After calling list_1.merge(list_2):\n";
  for (iter = list_1.begin(); iter != list_1.end(); iter++)
    std::cout << *iter << " ";
  std::cout << "\n";
  
  std::cout << "Test completed.\n";
  
  return 0;
  
}