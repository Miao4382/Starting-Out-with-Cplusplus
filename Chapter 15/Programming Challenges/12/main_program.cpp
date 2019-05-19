#include "ship.h"
#include "cruise_ship.h"
#include "cargo_ship.h"
#include <string>
#include <iostream>

int main()
{
  // initialize the array
  Ship* base[3] = { new Ship("Small wooden ship", "1943"), new CruiseShip("Dream Goddess", "1990", 2000), new CargoShip("Titan's Arm", "2015", 20000000) };
  
  // call Print() in each element (in a loop)
  for (int i=0; i<3; i++)
  {
    base[i]->Print();
    std::cout << "\n";
  }
  
  return 0;
}