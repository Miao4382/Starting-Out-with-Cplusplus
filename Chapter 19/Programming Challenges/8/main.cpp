#include <iostream>

bool IsMember(int array[], int value, int size)
{
  // base case
  if (size == 1)
  {
    if (array[size - 1] == value)
      return true;
    else 
      return false;
  }
  
  if (array[size - 1] == value)
    return true;
  else if (IsMember(array, value, size - 1))
    return true;
  else 
    return false;
}

int main()
{
  int array[] = { 1,2,3,4,5,6,7,8,9,10,0,-2,99 };
  
  int value;
  
  std::cout << "Please input a number to check: ";
  std::cin >> value;
  
  if (IsMember(array, value, 13))
    std::cout << value << " is in the array.\n";
  else 
    std::cout << value << " is not in the array.\n";
  
  return 0;
}