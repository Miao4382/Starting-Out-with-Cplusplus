#include <iostream>
#include <fstream>
#include <stack>

int main()
{
  // create a file 
  std::fstream out("D:\\18-9.txt", std::ios::out);
  for (char ch = 'a'; ch <= 'z'; ch++)
    out << ch;
  out << "\nabc\n";
  out.close();
  
  // create a stack to hold the characters
  std::stack<char> letter;
  
  // create a file streamer to read the content
  std::fstream in("D:\\18-9.txt", std::ios::in);
  char temp; // temporary variable to hold content read from file 
  while (in.get(temp))
    letter.push(temp);
  in.close();
  
  // write the content in the stack to another file 
  out.open("D:\\18-9_reverse.txt", std::ios::out);
  while (!letter.empty())
  {
    out << letter.top();
    letter.pop();
  }
  
  out.close();
  
  return 0;
}