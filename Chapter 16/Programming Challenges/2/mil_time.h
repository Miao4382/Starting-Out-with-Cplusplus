#ifndef MIL_TIME_H
#define MIL_TIME_H
#include "time.h"

class MilTime : public Time
{

protected:
  int mil_hours_;
  int mil_seconds_;
  
  /* Function */
  // time format convert function
  // accept a mil_time hour, will change the hour_, min_ to the time indicated by it
  void ConvertTime(int h);
  
  // time format check function 
  // return true if the time format is valid , otherwise return false 
  // hour number should be in the range of 0 ~ 23
  // min number should be in the range of 0 ~ 59
  // sec number should be in the range of 0 ~ 59
  bool CheckTime(int h, int s);
  
public:
  /* Constructor */
  // default constructor 
  // assign 00:00:00
  // call default constructor of Time()
  MilTime() : Time()
  {
    mil_hours_ = 0;
    mil_seconds_ = 0;
  }
  
  // constructor, accept mil_time in hour and second
  // call Time() (default) constructor to initialize hour_, min_, sec_ to 0
  // call ConvertTime() to re-initialize hour_, min_ 
  // initialize sec_
  // store h and s to mil_hours_ and mil_seconds_
  MilTime(int h, int s);
  
  /* Function */
  // time setting function 
  // check h, s, see if its valid, if its not, set h = 0, s = 0
  // save h and s to mil_hours_ and mil_seconds_
  // call ConvertTime() to re-set hour_, min_
  virtual void SetTime(int h, int s);
  
  /* Accessor */
  int GetHour() const 
  { return mil_hours_; }
  int GetStandHr() const 
  { return hour_; }
  
  /* Exception class */
  class BadHour
  {};
  
  class BadSecond
  {};
  
};


#endif