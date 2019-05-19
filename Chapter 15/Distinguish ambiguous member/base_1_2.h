#ifndef BASE_1_2_H
#define BASE_1_2_H
#include "base_1.h"
#include "base_2.h"
#include <iostream>

class Base12 : public Base1, public Base2
{
public:
  Base12() : Base1(), Base2()
  {}
  
  // Mutator
  void set_base_value_1(int value)
  { Base1::base_value_ = value; }
  void set_base_value_2(int value)
  { Base2::base_value_ = value; }
  
  // Accessor (redefine)
  int base_value() const 
  {
    std::cout << "base_value_1: " << Base1::base_value() << "\n"
    << "base_value_2: " << Base2::base_value() << "\n";
    return 0;
  }
};


#endif