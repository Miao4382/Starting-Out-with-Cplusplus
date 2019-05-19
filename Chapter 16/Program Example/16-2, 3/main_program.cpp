#include "rectangle.h"
#include <iostream>

int main()
{
  Rectangle r1;
  double length, width;
  
  try 
  {
    std::cout << "Input the length and width of the rectangle: ";
    std::cin >> length >> width;
    
    r1.set_length(length);
    r1.set_width(width);
    
    std::cout << "The area of the rectangle is: " << r1.area() << "\n";
  }
  
  catch (Rectangle::NegativeSizeL)
  {
    std::cout << "Error: length value should be positive.\n";
  }
  
  catch (Rectangle::NegativeSizeW)
  {
    std::cout << "Error: width value should be positive.\n";
  }
  
  return 0;
}