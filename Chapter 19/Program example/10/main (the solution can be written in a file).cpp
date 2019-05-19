#include <iostream>
#include <fstream>

void Move(int num, int from_peg, int to_peg, int temp_peg);

int main()
{
  int num;
  std::cout << "Input a number of discs: ";
  std::cin >> num;
  
  Move(num, 1, 3, 2);
  
  std::cout << "All discs are moved. Result stored in D:\Hanoi solution.txt\n";
  
  return 0;
}

void Move(int num, int from_peg, int to_peg, int temp_peg)
{
  // create a static object 
  static std::fstream out("D:\\Hanoi solution.txt", std::ios::out);  
  
  if (num > 0)
  {
    // prepare moving the last disc
    Move(num - 1, from_peg, temp_peg, to_peg);
    
    // move the last disc from peg a to peg c 
    out << "Move a disc from peg " << from_peg << " to peg " << to_peg << "\n";
    
    // move the rest discs
    Move(num - 1, temp_peg, to_peg, from_peg);
  }
  
  else // end of program
  {
    out.close();
  }
}