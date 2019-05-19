#include "rectangle.h"
#include <iostream>

int main()
{
  Rectangle r1;
  double length, width;
  bool try_again = true;
  
  /* Input length */
  std::cout << "Input the length of the rectangle: ";
  std::cin >> length;
  
  while (try_again)
  {
    try 
    {
      r1.set_length(length);
      try_again = false;
    }
    
    catch (Rectangle::NegativeSizeL obj)
    {
      std::cout << "Error: length value should be positive, while the inputed length is: " << obj.value() << "\n";
      std::cout << "Please input the length again: ";
      std::cin >> length;
    }
  }

  /* Input width */
  try_again = true;
  std::cout << "Input the width of the rectangle: ";
  std::cin >> width;
  
  while(try_again)
  {
    try 
    {
      r1.set_width(width);
      try_again = false;
    }
    
    catch (Rectangle::NegativeSizeW obj)
    {
      std::cout << "Error: width value should be positive, while the inputed width is: " << obj.value() << "\n";
      std::cout << "Please input the width again: ";
      std::cin >> width;
    }
  }
  
  /* Print area */
  std::cout << "The area of the rectangle is: " << r1.area() << "\n";
  
  return 0;
}