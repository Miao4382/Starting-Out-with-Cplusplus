#include <queue>
#include <iostream>
#include <fstream>

int main()
{
  // define two queues 
  std::queue<char> f1;
  std::queue<char> f2;
  
  // define a file stream object to read content 
  std::fstream in("D:\\1.txt", std::ios::in);
  
  // read file 1 
  char temp;
  while (in.get(temp))
    f1.push(temp);
  in.close();
  
  // read file 2
  in.open("D:\\2.txt", std::ios::in);
  while (in.get(temp))
    f2.push(temp);
  in.close();
  
  // compare 
  // when f1 and f2 has different sizes, they are not the same 
  if (f1.size() != f2.size())
  {
    std::cout << "The two files are not the same.\n";
    return 0;
  }
  
  // when f1 and f2 has the same size 
  bool same = true;
  
  while (!f1.empty() && !f2.empty())
  {
    if (f1.front() == f2.front())
    {
      f1.pop();
      f2.pop();
      continue;
    }
    
    same = false;
    break;
  }
  
  if (same)
    std::cout << "The two files are the same.\n";
  else 
    std::cout << "The two files are not the same.\n";
  
  return 0;
  
  
}