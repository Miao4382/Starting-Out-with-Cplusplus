#include "Date.h"

/* Constructor */
// default constructor
// date is set to 05/05/1990
Date::Date()
{
  month_ = 5;
  day_ = 5;
  year_ = 5;
}


// constructor accepts integers
Date::Date(int m, int d, int y)
{
  if (m > 12 || m < 1)
    throw InvalidMonth(m);
  
  if (d > 31 || d < 1)
    throw InvalidDay(d);
  
  day_ = d;
  month_ = m;
  year_ = y;
}

/* Member function */
// display date 
void Date::Display() const
{
  std::cout << month_ << "/" << day_ << "/" << year_;
}

/* Exception class member function */
int Date::InvalidDay::invalid_day() const 
{ return invalid_day_; }

int Date::InvalidMonth::invalid_month() const 
{ return invalid_month_; }