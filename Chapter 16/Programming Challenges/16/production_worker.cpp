#include "production_worker.h"

/* Constructor */
// default constructor 
ProductionWorker::ProductionWorker() : Employee()
{
  shift_ = 0;
  hour_pay_rate_ = 0.0;
}
// constructor 
ProductionWorker::ProductionWorker(std::string n, int id, std::string date, int shift, double rate) : Employee(n, id, date)
{
  if (shift != 1 && shift != 2)
    throw InvalidShift();
  
  if (rate < 0)
    throw InvalidPayRate();
  
  shift_ = shift;
  hour_pay_rate_ = rate;
}