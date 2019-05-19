#ifndef CAR_H
#define CAR_H
#include "automobile.h"

class Car : public Automobile
{
private:
  int door_num_;
public:
  /* Constructor */
  Car(std::string make, std::string year, int mile, double price, int d_num);
  
  /* Accessor */
  int GetDoorNum() const 
  { return door_num_; }
};

#endif