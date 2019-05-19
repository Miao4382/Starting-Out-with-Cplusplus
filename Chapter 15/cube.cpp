#include "cube.h"

// constructor with parameter, should include parameter for constructor of Rectangle()
// don't write : Rectangle() in prototype, write in header of the function definition
Cube::Cube(double h, double len, double w) : Rectangle(w, len)
{
  height_ = h;
}

