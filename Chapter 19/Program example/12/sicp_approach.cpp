#include <iostream>

const int Coin[] = { 100, 50, 25, 10, 5, 1 };

int Ways(int value, int starting_index)
{
  if (starting_index == 6)
    return 0;
  
  if (value == 0)
    return 1;
  
  if (value < 0)
    return 0;
  
  return Ways(value, starting_index + 1) + Ways(value - Coin[starting_index], starting_index);
}

int main()
{
  int value;
  std::cout << "Please input the amount of money to be changed: ";
  std::cin >> value;
  
  std::cout << "There are " << Ways(value, 0) << " ways of change\n";
  
  return 0;
}