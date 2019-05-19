#include "rectangle.h"

/* Constructor */
// initialize width and length
// call CalcArea() to set area
Rectangle::Rectangle(int w, int l)
{
  width_ = w;
  length_ = l;
  
  CalcArea();
}


/* Virtual Function */
void Rectangle::CalcArea()
{
  SetArea(width_ * length_);
}