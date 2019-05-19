#include "rectangle.h"

/* Mutator */
void Rectangle::set_length(double l)
{
  if (l < 0)
  {
    char error_code = 'L';
    throw error_code;
  }
  
  length_ = l;
}

void Rectangle::set_width(double w)
{
  if (w < 0)
  {
    char error_code = 'W';
    throw error_code;
  }
  
  width_ = w;
}