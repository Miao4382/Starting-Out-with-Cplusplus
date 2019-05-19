#include "circle.h"
#include "rectangle.h"
#include <iostream>

int main()
{
  Circle c1(0, 0, 1);
  Rectangle r1(5, 7);
  
  std::cout << "The circle center is: (" << c1.GetCenterX() << ","
  << c1.GetCenterY() << "), area is: " << c1.GetArea() << "\n\n";
  
  std::cout << "The rectangle's width is: " << r1.GetWidth() << "\n"
  << "The rectangle's length is: " << r1.GetLength() << "\n"
  << "The rectangle's area is: " << r1.GetArea() << "\n";

  return 0;
}