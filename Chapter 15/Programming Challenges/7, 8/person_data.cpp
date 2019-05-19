#include "person_data.h"
#include <string>

/* Constructor */
// default constructor
PersonData::PersonData()
{
  SetInfo("N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A");
}

// constructor
// accept info, call SetInfo() function to initialize each info
PersonData::PersonData(std::string l, std::string f, std::string a, std::string c, std::string s, std::string z, std::string p)
{
  SetInfo(l, f, a, c, s, z, p);
}

/* Mutator */
// set info for each slot 
void PersonData::SetInfo(std::string l, std::string f, std::string a, std::string c, std::string s, std::string z, std::string p)
{
  last_name_ = l;
  first_name_ = f;
  address_ = a;
  city_ = c;
  state_ = s;
  zip_ = z;
  phone_ = p;
}