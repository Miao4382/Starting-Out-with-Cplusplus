#include "customer_data.h"

/* Constructor */
// default constructor
CustomerData::CustomerData() : PersonData()
{
  customer_number_ = 0;
  mailing_list_ = false;
}

// constructor
CustomerData::CustomerData(std::string l, std::string f, std::string a, std::string c, std::string s, std::string z, std::string p, int c_n, bool m_l) : PersonData(l, f, a, c, s, z, p)
{
  customer_number_ = c_n;
  mailing_list_ = m_l;  
}