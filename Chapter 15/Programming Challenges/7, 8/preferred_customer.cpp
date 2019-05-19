#include "preferred_customer.h"
#include <iostream>

/* Constructor */
// default constructor, will call CustomerData();
PreferredCustomer::PreferredCustomer() : CustomerData()
{
  purchase_amount_ = 0.0;
  discount_level_ = 1.0;
}

// constructor 
// accepts data for CustomerData() and purchase_amount_, discount_level_
PreferredCustomer::PreferredCustomer(std::string l, std::string f, std::string a, std::string c, std::string s, std::string z, std::string p, int c_n, bool m_l, double p_a) : CustomerData(l, f, a, c, s, z, p, c_n, m_l)
{
  if (p_a < 0)
  {
    std::cout << "Invalid purchase amount, set to zero.\n";
    purchase_amount_ = 0.0;
  }
  
  else 
    purchase_amount_ = p_a;
  
  SetDiscountLevel();
}

/* Mutator */
void PreferredCustomer::SetPreferredCustomerInfo(double p_a)
{
  if (p_a < 0)
  {
    std::cout << "Invalid purchase amount, set to zero.\n";
    purchase_amount_ = 0.0;
  }
  
  else 
    purchase_amount_ = p_a;
  
  SetDiscountLevel();
}

void PreferredCustomer::SetDiscountLevel()
{
  if (purchase_amount_ >= 2000.0)
    discount_level_ = 0.9;
  else if (purchase_amount_ >= 1500)
    discount_level_ = 0.93;
  else if (purchase_amount_ >= 1000)
    discount_level_ = 0.94;
  else if (purchase_amount_ >= 500)
    discount_level_ = 0.95;
  else 
    discount_level_ = 1.0;
}