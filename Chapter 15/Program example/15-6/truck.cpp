#include "truck.h"
#include <string>

/* Constructor */
Truck::Truck(std::string make, std::string year, int mile, double price, std::string d_type) : Automobile(make, year, mile, price)
{
  drive_type_ = d_type;
}

