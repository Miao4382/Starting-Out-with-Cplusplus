#include "rectangle.h"

/* Mutator */
void Rectangle::set_length(double l)
{
  if (l < 0)
  {
    throw NegativeSizeL();
  }
  
  length_ = l;
}

void Rectangle::set_width(double w)
{
  if (w < 0)
  {
    throw NegativeSizeW();
  }
  
  width_ = w;
}