#include "time_clock.h"
#include <iostream>

/* Function */
// time calculator
// accepts a mil time (for example, 17:55 is 1755)
// return the number of minutes from 00:00 to the input time
int TimeClock::CalculateMin(int t) const
{
  int hour = t / 100;
  int min = t % 100;
  
  return hour * 60 + min;
}

/* Constructor */
// accepts two time, starting time and end time (in mil time), doesn't contain sec
// call default constructor of MilTime()
// call SetTime(), pass start_time and end_time to the function
TimeClock::TimeClock(int start_time, int end_time) : MilTime()
{
  SetTime(start_time, end_time);
}

/* Function */      
// set time
// accepts two time, starting time and end time (in mil time), doesn't contain sec
// check if start_time and end_time is valid (call MilTime::CheckTime())
// if not valid, set start_time to 0:00, end_time to 12:00, and notify user
// check if start_time is bigger than end_time, if so, notify user mistake, and set start_time to 0:00
// call MilTime::SetTime() to save start time, second = 0
// assign end time to end_hours_
void TimeClock::SetTime(int start_time, int end_time)
{
  if (!(CheckTime(start_time, 0) && CheckTime(end_time, 0)))
  {
    std::cout << "Invalid time format, start time has been set to 00:00, end time has been set to 12:00\n";
    start_time = 0;
    end_time = 1200;
  }
  
  if (start_time > end_time)
  {
    std::cout << "start time should be less than end time, start time has been set to 00:00\n";
    start_time = 0;
  }
  
  MilTime::SetTime(start_time, 0); // 0 is second = 0
  
  end_hours_ = end_time;
}

// report elapsed time (unit: minute)
// calculate number of min since 0:00 for start and end time
// return the difference 
int TimeClock::Elapsed() const
{
  int start_min = CalculateMin(mil_hours_);
  int end_min = CalculateMin(end_hours_);
  
  return end_min - start_min;
}