#include <iostream>

void Move(int num, int from_peg, int to_peg, int temp_peg);

int main()
{
  int num;
  std::cout << "Input a number of discs: ";
  std::cin >> num;
  
  Move(num, 1, 3, 2);
  
  std::cout << "All discs are moved.\n";
  
  return 0;
}

void Move(int num, int from_peg, int to_peg, int temp_peg)
{
  if (num > 0)
  {
    // prepare moving the last disc
    Move(num - 1, from_peg, temp_peg, to_peg);
    
    // move the last disc from peg a to peg c 
    std::cout << "Move a disc from peg " << from_peg << " to peg " << to_peg << "\n";
    
    // move the rest discs
    Move(num - 1, temp_peg, to_peg, from_peg);
  }
}