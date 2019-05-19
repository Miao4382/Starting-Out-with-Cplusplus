#ifndef CUBE_H
#define CUBE_H
#include "rectangle.h"

class Cube : public Rectangle
{
private:
  double height_;
public:
  /* Constructor */
  // default constructor
  Cube() : Rectangle()
  { height_ = 0; }
  // constructor with parameter, should include parameter for constructor of Rectangle()
  // don't write : Rectangle() in prototype, write in header of the function definition
  Cube(double h, double len, double w); 
  
  /* Accessor */
  double GetHeight() const
  { return height_; }
  double GetVolume() const 
  { return GetArea() * GetHeight(); }
  
  /* Mutator */
  void SetHeight(double h)
  { height_ = h; }
};


#endif