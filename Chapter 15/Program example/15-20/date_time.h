#ifndef DATE_TIME_H
#define DATE_TIME_H
#include "date.h"
#include "time.h"

class DateTime : public Date, public Time
{
public:
  /* Constructor */
  // default constructor, automatically call default constructor of DateTime
  DateTime();
  
  // Constructor
  // require initialize info for Date and Time, pass to Date() and Time() in .cpp file
  DateTime(int m, int d, int y, int h, int min, int s);
  
  /* Function */
  // display date and time 
  void ShowDateTime() const;
};


#endif