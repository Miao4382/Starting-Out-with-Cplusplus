#include "car.h"

/* Constructor */
Car::Car(std::string make, std::string year, int mile, double price, int d_num) : Automobile(make, year, mile, price)
{
  door_num_ = d_num;
}

