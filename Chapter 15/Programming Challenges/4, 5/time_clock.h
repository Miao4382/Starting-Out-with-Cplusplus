#ifndef TIME_CLOCK_H
#define TIME_CLOCK_H
#include "mil_time.h"

class TimeClock : public MilTime
{
private:
  int end_hours_; // hold the end point time, in 24-h format
  
  /* Function */
  // time calculator
  // accepts a mil time (for example, 17:55 is 1755)
  // return the number of minutes from 00:00 to the input time
  int CalculateMin(int t) const;

  
public:
  /* Constructor */
  // accepts two time, starting time and end time (in mil time), doesn't contain sec
  // call default constructor of MilTime()
  // call SetTime(), pass start_time and end_time to the function
  TimeClock(int start_time, int end_time);
  
  /* Function */      
  // set time
  // accepts two time, starting time and end time (in mil time), doesn't contain sec
  // check if start_time and end_time is valid (call MilTime::CheckTime())
  // if not valid, set start_time to 0:00, end_time to 12:00, and notify user
  // check if start_time is bigger than end_time, if so, notify user mistake, and set start_time to 0:00
  // call MilTime::SetTime() to save start time, second = 0
  // assign end time to end_hours_
  virtual void SetTime(int start_time, int end_time);  
  
  // report elapsed time (unit: minute)
  // calculate number of min since 0:00 for start and end time
  // return the difference 
  int Elapsed() const;
  
  
};


#endif