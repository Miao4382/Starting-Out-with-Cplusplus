#include "suv.h"

/* Constructor */
Suv::Suv(std::string make, std::string year, int mile, double price, int p_capacity) : Automobile(make, year, mile, price)
{
  passenger_capacity_ = p_capacity;
}