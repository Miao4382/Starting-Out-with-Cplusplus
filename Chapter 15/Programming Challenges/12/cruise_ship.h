#ifndef CRUISE_SHIP_H
#define CRUISE_SHIP_H
#include "ship.h"
#include <string>
#include <iostream>

class CruiseShip : public Ship
{
protected:
  int max_passenger_;
public:
  /* Constructor */
  // accepts max_passenger_
  CruiseShip(std::string n, std::string y, int m_p) : Ship(n, y)
  { max_passenger_ = m_p; }
  
  /* Accessor */
  int max_passenger() const 
  { return max_passenger_; }
  
  /* Mutator */
  void set_max_passenger(int m_p)
  { max_passenger_ = m_p; }
  
  /* Virtual function */
  virtual void Print() const
  {
    std::cout << "***** Ship Name *****\n"
    << name_ << "\n\n"
    << "***** Maximum Passenger *****\n"
    << max_passenger_ << "\n\n";
  }
  
};


#endif