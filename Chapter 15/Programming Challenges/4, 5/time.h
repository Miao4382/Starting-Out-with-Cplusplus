// Specification file for the Time class
#ifndef TIME_H
#define TIME_H

class Time
{
protected:
   int hour_;
   int min_;
   int sec_;
public:
   // Default constructor
   Time() 
      { hour_ = 0; min_ = 0; sec_ = 0; }
   
   // Constructor
   Time(int h, int m, int s) 
      { hour_ = h; min_ = m; sec_ = s; }

   // Accessor functions
   int getHour() const
      { return hour_; }

   int getMin() const
      { return min_; }

   int getSec() const
      { return sec_; }
};

#endif