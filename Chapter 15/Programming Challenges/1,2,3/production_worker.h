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
  ProductionWorker(std::string n, std::string id, std::string date, int shift, double rate);
  
  /* Accessor */
  int shift() const 
  { return shift_; }
  double hour_pay_rate() const 
  { return hour_pay_rate_; }
  
  /* Mutator */
  void set_shift(int s)
  { shift_ = s; }
  void set_hour_pay_rate(double rate)
  { hour_pay_rate_ = rate; }
};


#endif