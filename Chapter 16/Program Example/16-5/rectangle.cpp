#include "rectangle.h"

/* Constructor of NegativeSizeL class */
Rectangle::NegativeSizeL::NegativeSizeL(double v)
{
  value_ = v;
}

/* Constructor of NegativeSizeW class */
Rectangle::NegativeSizeW::NegativeSizeW(double v)
{
  value_ = v;
}

/* Mutator */
void Rectangle::set_length(double l)
{
  if (l < 0)
  {
    throw NegativeSizeL(l);
  }
  
  length_ = l;
}

void Rectangle::set_width(double w)
{
  if (w < 0)
  {
    throw NegativeSizeW(w);
  }
  
  width_ = w;
}