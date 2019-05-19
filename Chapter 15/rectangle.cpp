#include "rectangle.h"
/* Constructor */
// default, assign 0 to width and length 
Rectangle::Rectangle()
{
  width_ = 0;
  length_ = 0;
}

// constructor with parameter
Rectangle::Rectangle(double w, double l)
{
  width_ = w;
  length_ = l;
}