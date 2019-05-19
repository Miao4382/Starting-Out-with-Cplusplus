#ifndef CARGO_SHIP_H
#define CARGO_SHIP_H
#include "ship.h"
#include <string>
#include <iostream>

class CargoShip : public Ship
{
protected:
  int max_capacity_;
public:
  /* Constructor */
  // accepts max_capacity_
  CargoShip(std::string n, std::string y, int m_c) : Ship(n, y)
  { max_capacity_ = m_c; }
  
  /* Accessor */
  int max_capacity() const 
  { return max_capacity_; }
  
  /* Mutator */
  void set_max_capacity(int m_c)
  { max_capacity_ = m_c; }
  
  /* Virtual function */
  virtual void Print() const
  {
    std::cout << "***** Ship Name *****\n"
    << name_ << "\n\n"
    << "***** Maximum Capacity *****\n"
    << max_capacity_ << " ton\n\n";
  }
  
};


#endif