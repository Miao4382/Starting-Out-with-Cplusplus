#include <queue>
#include <iostream>

int main()
{
  std::queue<int> my_queue;
  
  if (my_queue.empty())
    std::cout << "The queue is now empty.\n";
  else 
    std::cout << "The queue is not empty\n";
  
  for (int i = 1; i <= 5; i++)
    my_queue.push(i);
  
  std::cout << "After adding value, the size of the queue is: " << my_queue.size() << "\n";
  
  std::cout << "Now displaying each element in queue:\n";
  while (!my_queue.empty())
  {
    std::cout << my_queue.front() << " ";
    my_queue.pop();
  }
  
  std::cout << "\n";
  
  if (my_queue.empty())
    std::cout << "The queue is now empty.\n";
  else 
    std::cout << "The queue is not empty\n";

  return 0;
  
}