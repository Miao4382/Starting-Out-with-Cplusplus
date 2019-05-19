#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
  int month_; // hold month value 
  int day_; // hold the day value 
  int year_; // hold the year value 
public:
  /* Constructor */
  // default constructor
  // date is set to 05/05/1990
  Date();
  // constructor accepts integers
  Date(int m, int d, int y);
  
  /* Member function */
  // display date 
  void Display() const;
  
  /* Exception class */
  class InvalidDay
  {
  private:
    int invalid_day_;
  public:
    /* Constructor */
    InvalidDay(int d)
    { invalid_day_ = d; }
    
    /* Accessor */
    int invalid_day() const;
  };
  
  class InvalidMonth
  {
  private:
    int invalid_month_;
  public:
    /* Constructor */
    InvalidMonth(int m)
    { invalid_month_ = m; }
    
    /* Accessor */
    int invalid_month() const;
  };
  
  
};


#endif