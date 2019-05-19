#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "basic_shape.h"

class Rectangle : public BasicShape
{
private:
  int width_;
  int length_;
public:
  /* Constructor */
  // initialize width and length
  // call CalcArea() to set area
  Rectangle(int w, int l);
  
  /* Accessor */
  int GetWidth() const 
  { return width_; }
  int GetLength() const 
  { return length_; }
  
  /* Virtual Function */
  virtual void CalcArea();
};


#endif