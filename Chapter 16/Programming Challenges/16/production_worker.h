#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H
#include "employee.h"

class ProductionWorker : public Employee
{
protected:
  int shift_;
  double hour_pay_rate_;
public:
  /* Constructor */
  // default constructor 
  ProductionWorker();
  // constructor 
  ProductionWorker(std::string n, int id, std::string date, int shift, double rate);
  
  /* Accessor */
  int shift() const 
  { return shift_; }
  double hour_pay_rate() const 
  { return hour_pay_rate_; }
  
  /* Mutator */
  void set_shift(int s)
  { 
    if (s != 1 && s != 2)
      throw InvalidShift();
    
    shift_ = s; 
  }
  
  void set_hour_pay_rate(double rate)
  {
    if (rate < 0)
      throw InvalidPayRate();
    
    hour_pay_rate_ = rate; 
  }
  
  /* Exception class */
  class InvalidShift
  {};
  class InvalidPayRate
  {};
  
};


#endif