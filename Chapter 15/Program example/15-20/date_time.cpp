#include "date_time.h"
#include <iostream>

/* Constructor */
// default constructor, automatically call default constructor of DateTime
DateTime::DateTime() : Date(), Time()
{}

// Constructor
// require initialize info for Date and Time, pass to Date() and Time() in .cpp file
DateTime::DateTime(int m, int d, int y, int h, int min, int s) : Date(m, d, y), Time(h, min, s)
{}

/* Function */
// display date and time 
void DateTime::ShowDateTime() const
{
  std::cout << "Date: " << getMonth() << "/" << getDay() << "/" << getYear() << "  "
  << getHour() << ":" << getMin() << ":" << getSec() << "\n";
}