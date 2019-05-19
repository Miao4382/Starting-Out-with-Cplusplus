#include "rectangle.h"
#include <iostream>

int main()
{
  Rectangle r1;
  double length, width;
  bool try_again = true;
  
  /* Input length */
  while (try_again)
  {
    try 
    {
      std::cout << "Please input the length of the rectangle: ";
      std::cin >> length;
      
      r1.set_length(length);
      
      try_again = false;
    }
    
    catch (Rectangle::NegativeSizeL)
    {
      std::cout << "The length should be greater than zero.\n";
    }
  }
  
  /* Input width */
  try_again = true;
  while (try_again)
  {
    try 
    {
      std::cout << "Please input the width of the rectangle: ";
      std::cin >> width;
      
      r1.set_width(width);
      
      try_again = false;
    }
    
    catch (Rectangle::NegativeSizeW)
    {
      std::cout << "The width should be greater than zero.\n";
    }
  }
  
  /* Display area */
  std::cout << "The area of the rectangle is: " << r1.area() << "\n";
  
  return 0;
}