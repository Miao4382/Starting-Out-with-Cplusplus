#ifndef DERIVEDCLASS_H
#define DERIVEDCLASS_H
#include <iostream>
class DerivedClass : public BaseClass
{
public:
  /* Constructor */
  DerivedClass()
  { std::cout << "Constructor of derived class has been called.\n"; }
  
  /* Destructor */
  ~DerivedClass()
  { std::cout << "Destructor of derived class has been called.\n"; }
};

#endif