#ifndef PHONE_BOOK_ENTRY_H
#define PHONE_BOOK_ENTRY_H
#include <string>

class PhoneBookEntry
{
private:
  std::string name_;
  std::string phone_number_;
public:
  /* Constructor */
  PhoneBookEntry()
  {
    name_ = "N/A";
    phone_number_ = "N/A";
  }
  
  /* Accessor */
  std::string name() const 
  { return name_; }
  std::string phone() const 
  { return phone_number_; }
  
  /* Mutator */
  void set(std::string n, std::string tel)
  {
    name_ = n;
    phone_number_ = tel;
  }
  
};


#endif