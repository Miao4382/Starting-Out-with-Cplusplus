#include <queue>
#include <fstream>
#include <cctype>

int main()
{
  // create a file 
  std::fstream out("D:\\18-10.txt", std::ios::out);
  out << "stacks are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are pushed/popped from the \"back\" of the specific container, which is known as the top of the stack.";
  out.close();
  
  // define a queue, copy content in the file to the queue 
  std::queue<char> letter;
  char temp; // temporary variable for holding character read from file 
  std::fstream in("D:\\18-10.txt", std::ios::in);
  while (in.get(temp))
    letter.push(temp);
  in.close();
  
  // dequeue each character, apply filtering rule, store into a new file 
  out.open("D:\\18-10_UPPER.txt", std::ios::out);
  while (!letter.empty())
  {
    temp = toupper(letter.front());
    out << temp;
    letter.pop();
  }
  
  out.close();
  
  return 0;
  
}