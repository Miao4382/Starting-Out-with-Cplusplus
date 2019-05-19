#ifndef CUSTOMER_DATA_H
#define CUSTOMER_DATA_H
#include "person_data.h"

class CustomerData : public PersonData
{
protected:
  int customer_number_;
  bool mailing_list_;
public:
  /* Constructor */
  // default constructor
  CustomerData();
  // constructor
  CustomerData(std::string l, std::string f, std::string a, std::string c, std::string s, std::string z, std::string p, int c_n, bool m_l);
  
  /* Accessor */
  int customer_number() const 
  { return customer_number_; }
  bool mailing_list() const 
  { return mailing_list_; }
  
  /* Mutator */
  void set_customer_number(int c_n)
  { customer_number_ = c_n; }
  void set_mailing_list(bool m_l)
  { mailing_list_ = m_l; }
};


#endif