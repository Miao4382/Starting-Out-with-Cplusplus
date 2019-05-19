#include "mil_time.h"
#include <iostream>

// time format convert function
// accept a mil_time hour, will change the hour_, min_ to the time indicated by it
void MilTime::ConvertTime(int h)
{
  min_ = h % 100;
  hour_ = h / 100;
}

// time format check function 
// return true if the time format is valid , otherwise return false 
// hour number should be in the range of 0 ~ 23
// min number should be in the range of 0 ~ 59
// sec number should be in the range of 0 ~ 59
bool MilTime::CheckTime(int h, int s)
{
  int hour = h / 100;
  int min = h % 100;
  
  if (hour < 0 || hour > 23)
    return false;
  
  if (min < 0 || min > 59)
    return false;
  
  if (s < 0 || s > 59)
    return false;
  
  return true;
}

/* Constructor */
// constructor, accept mil_time in hour and second
// call Time() (default) constructor to initialize hour_, min_, sec_ to 0
// check time validity 
// call ConvertTime() to re-initialize hour_, min_ 
// initialize sec_
// store h and s to mil_hours_ and mil_seconds_
MilTime::MilTime(int h, int s) : Time()
{
  if (CheckTime(h, s))
  {
    ConvertTime(h);
    sec_ = s;
    
    mil_hours_ = h;
    mil_seconds_ = s;    
  }
  
  else 
  {
    int hour = h / 100;
    int min = h % 100;
    
    if (hour < 0 || hour > 23)
      throw BadHour();
    
    if (min < 0 || min > 59)
      throw BadHour();
    
    if (s < 0 || s > 59)
      throw BadSecond();
  }

}

/* Function */
// time setting function 
// check h, s, see if its valid, if its not, set h = 0, s = 0
// save h and s to mil_hours_ and mil_seconds_
// call ConvertTime() to re-set hour_, min_
void MilTime::SetTime(int h, int s)
{
  if (CheckTime(h, s))
  {
    ConvertTime(h);
    sec_ = s;
    
    mil_hours_ = h;
    mil_seconds_ = s;    
  }
  
  else 
  {
    std::cout << "Invalid time format, time has been set to 00:00:00\n";
    ConvertTime(0);
    sec_ = 0;
    
    mil_hours_ = 0;
    mil_seconds_ = 0;
  }
  
}