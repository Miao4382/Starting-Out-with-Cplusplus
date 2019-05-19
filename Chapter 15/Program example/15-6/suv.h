#ifndef SUV_H
#define SUV_H
#include <string>
#include "automobile.h"

class Suv : public Automobile
{
private:
  int passenger_capacity_;
public:
  /* Constructor */
  Suv(std::string make, std::string year, int mile, double price, int p_capacity);
  
  /* Accessor */
  int GetPassengerCapacity() const 
  { return passenger_capacity_; }
};

#endif