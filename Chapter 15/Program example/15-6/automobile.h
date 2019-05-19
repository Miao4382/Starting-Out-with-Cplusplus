#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>

class Automobile
{
private:
  std::string make_;
  std::string year_model_;
  int mileage_;
  double price_;
public:
  /* Constructor */
  // constructor with initialization, info should be initialized, no modification required
  Automobile(std::string make, std::string year, int mile, double price);
  
  /* Accessor */
  std::string GetMake() const 
  { return make_; }
  std::string GetYearModel() const 
  { return year_model_; }
  int GetMile() const 
  { return mileage_; }
  double GetPrice() const 
  { return price_; }
  
};

#endif