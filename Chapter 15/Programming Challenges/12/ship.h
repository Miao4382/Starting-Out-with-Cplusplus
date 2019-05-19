#ifndef SHIP_H
#define SHIP_H
#include <string>

class Ship
{
protected:
  std::string name_;
  std::string year_;
public:
  /* Constructor */
  // default constructor
  // assign "N/A" to name_ and year_
  Ship();
  // constructor 
  Ship(std::string n, std::string y);
  
  /* Accessor */
  std::string name() const 
  { return name_; }
  std::string year() const 
  { return year_; }
  
  /* Mutator */
  void set_name(std::string n)
  { name_ = n; }
  void set_year(std::string y)
  { year_ = y; }
  
  /* Virtual Function */
  // in Ship class, Print() will do following:
  // print name and year of the ship
  virtual void Print() const;
};


#endif