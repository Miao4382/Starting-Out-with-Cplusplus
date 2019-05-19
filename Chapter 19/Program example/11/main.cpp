#include <iostream>
#include "quick_sort.h"
template <class T>
void DisplayArray(T* array, int size);

int main()
{
  int array[] = { 5, 4, 2, 7, 8, 3, 1, 6, 9 };
  
  std::cout << "Before sorting: ";
  DisplayArray(array, 9);
  
  // sort 
  QuickSort(array, 0, 8);
  
  std::cout << "After sorting: ";
  DisplayArray(array, 9); 
}

template <class T>
void DisplayArray(T* array, int size)
{
  for (int i = 0; i < size; i++)
    std::cout << array[i] << " ";
  std::cout << "\n";
}
