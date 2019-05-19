#include "circle.h"

/* Constructor */
// initialize x, y and radius of the circle, will also call CalcArea() to set area_
Circle::Circle(int x, int y, int r)
{
  center_x_ = x;
  center_y_ = y;
  radius_ = r;
  
  CalcArea();
}

/* Function */
void Circle::CalcArea()
{
  SetArea(3.1415 * radius_ * radius_);
}