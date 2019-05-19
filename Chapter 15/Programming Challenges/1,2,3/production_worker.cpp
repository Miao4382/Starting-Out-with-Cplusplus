#include "production_worker.h"

/* Constructor */
// default constructor 
ProductionWorker::ProductionWorker() : Employee()
{
  shift_ = 0;
  hour_pay_rate_ = 0.0;
}
// constructor 
ProductionWorker::ProductionWorker(std::string n, std::string id, std::string date, int shift, double rate) : Employee(n, id, date)
{
  shift_ = shift;
  hour_pay_rate_ = rate;
}