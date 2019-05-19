#ifndef TRUCK_H
#define TRUCK_H
#include "automobile.h"
#include <string>

class Truck : public Automobile
{
private:
  std::string drive_type_;
public:
  /* Constructor */
  Truck(std::string make, std::string year, int mile, double price, std::string d_type);
  
  /* Accessor */
  std::string GetDriveType() const 
  { return drive_type_; }
};

#endif