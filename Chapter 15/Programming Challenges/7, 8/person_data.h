#ifndef PERSON_DATA_H
#define PERSON_DATA_H
#include <string>

class PersonData
{
protected:
  std::string last_name_;
  std::string first_name_;
  std::string address_;
  std::string city_;
  std::string state_;
  std::string zip_;
  std::string phone_;
public:
  /* Constructor */
  // default constructor
  PersonData();
  // constructor
  // accept info, call SetInfo() function to initialize each info
  PersonData(std::string l, std::string f, std::string a, std::string c, std::string s, std::string z, std::string p);
  
  /* Mutator */
  // set info for each slot 
  void SetInfo(std::string l, std::string f, std::string a, std::string c, std::string s, std::string z, std::string p);
  
  /* Accessor */
  std::string last_name() const 
  { return last_name_; }
  std::string first_name() const 
  { return first_name_; }
  std::string address() const 
  { return address_; }
  std::string city() const 
  { return city_; }
  std::string state() const 
  { return state_; }
  std::string zip() const 
  { return zip_; }
  std::string phone() const 
  { return phone_; }  
};


#endif