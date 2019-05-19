#include "automobile.h"
#include <string>

/* Constructor */
// constructor with initialization, info should be initialized, no modification required
Automobile::Automobile(std::string make, std::string year, int mile, double price)
{
  make_ = make;
  year_model_ = year;
  mileage_ = mile;
  price_ = price;
}