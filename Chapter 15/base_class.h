#ifndef BASECLASS_H
#define BASECLASS_H
#include <iostream>

class BaseClass
{
public:
  /* Constructor */
  BaseClass()
  { std::cout << "Constructor of base class has been called.\n"; }
  
  /* Destructor */
  ~BaseClass()
  { std::cout << "Destructor of base class has been called.\n"; }
};


#endif