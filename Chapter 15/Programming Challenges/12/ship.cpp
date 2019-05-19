#include "ship.h"
#include <string>
#include <iostream>

/* Constructor */
// default constructor
// assign "N/A" to name_ and year_
Ship::Ship()
{
  set_name("N/A");
  set_year("N/A");
}
// constructor 
Ship::Ship(std::string n, std::string y)
{
  set_name(n);
  set_year(y);
}

/* Virtual Function */
// in Ship class, Print() will do following:
// print name and year of the ship
void Ship::Print() const
{
  std::cout << "***** Ship Name *****\n"
  << name_ << "\n\n"
  << "***** Built Year *****\n"
  << year_ << "\n\n";
}