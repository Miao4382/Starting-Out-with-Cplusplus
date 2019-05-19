#ifndef CIRCLE_H
#define CIRCLE_H
#include "basic_shape.h"

class Circle : public BasicShape
{
private:
  int center_x_;
  int center_y_;
  double radius_;
public:
  /* Constructor */
  // initialize x, y and radius of the circle, will also call CalcArea() to set area_
  Circle(int x, int y, int r);
  
  /* Accessor */
  int GetCenterX() const 
  { return center_x_; }
  int GetCenterY() const 
  { return center_y_; }
  
  /* Function */
  virtual void CalcArea();
  
};


#endif