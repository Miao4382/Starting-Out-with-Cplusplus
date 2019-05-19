#include <deque>
#include <iostream>

int main()
{
  std::deque<int> my_deque;
  
  std::cout << "Current usage: " << my_deque.size() << "/" << my_deque.max_size() << "\n";
  
  my_deque.push_back(2);
  my_deque.push_back(5);
  my_deque.push_front(1);
  
  // display all content
  std::cout << "After assigning, elements are: ";
  for (unsigned i = 0; i < my_deque.size(); i++)
    std::cout << my_deque[i] << " ";
  std::cout << "\n";
  
  // test pop 
  std::cout << "After calling my_deque.pop_front(), my_deque is: ";
  my_deque.pop_front();
  for (unsigned i = 0; i < my_deque.size(); i++)
    std::cout << my_deque[i] << " ";
  std::cout << "\n";
  
  return 0;
}