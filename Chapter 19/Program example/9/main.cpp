#include <iostream>

int BinarySearch(int* num, int first, int last, int value);

int main()
{
  int num[10] = { 1,2,3,4,5,6,7,8,9,10 };
  
  int index;
  int value;
  
  std::cout << "Input a number to search: ";
  std::cin >> value;
  
  index = BinarySearch(num, 0, 9, value);
  
  if (index == -1)
    std::cout << "Not found!\n";
  else 
    std::cout << "Element found! The subscript is " << index << "\n";
  
  return 0;
}

int BinarySearch(int* num, int first, int last, int value)
{
  if (first > last)
    return -1;
  
  int middle = (first + last) / 2;
  
  if (num[middle] == value)
    return middle;
  else if (num[middle] > value)
    return BinarySearch(num, first, middle - 1, value);
  else 
    return BinarySearch(num, middle + 1, last, value);
}