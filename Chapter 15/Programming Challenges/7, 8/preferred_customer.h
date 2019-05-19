#ifndef PREFERRED_CUSTOMER_H
#define PREFERRED_CUSTOMER_H
#include "customer_data.h"


class PreferredCustomer : public CustomerData
{
protected:
  double purchase_amount_;
  double discount_level_;
  
public:
  /* Constructor */
  // default constructor, will call CustomerData();
  PreferredCustomer();
  // constructor 
  // accepts data for CustomerData() and purchase_amount_, discount_level_
  PreferredCustomer(std::string l, std::string f, std::string a, std::string c, std::string s, std::string z, std::string p, int c_n, bool m_l, double p_a);
  
  /* Accessor */
  double purchase_amount() const 
  { return purchase_amount_; }
  double discount_level() const 
  { return discount_level_; }
  
  /* Mutator */
  void SetPreferredCustomerInfo(double p_a);
  void SetDiscountLevel();
  
};


#endif