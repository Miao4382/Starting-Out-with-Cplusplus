#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

// item class, inventory is the collection of objects of item class 
class Item
{
private:
  int serial_num_;
  std::string m_date_;
  int lot_num_;
public:
  /* Constructor */
  // default constructor 
  Item()
  {
    serial_num_ = 0;
    m_date_ = "N/A";
    lot_num_ = 0;
  }
  // constructor with parameters
  Item(int s_n, std::string m_d, int l_n)
  {
    serial_num_ = s_n;
    m_date_ = m_d;
    lot_num_ = l_n;
  }
  
  /* Accessor */
  int serial_num() const
  {
    return serial_num_;
  }
  
  std::string manufac_date() const 
  {
    return m_date_;
  }
  
  int lot_num() const 
  {
    return lot_num_;
  }
  
  /* Mutator */
  void set_serial_num(int s_n)
  {
    serial_num_ = s_n;
  }
  
  void set_manufac_date(std::string m_d)
  {
    m_date_ = m_d;
  }
  
  void set_lot_num(int l_n)
  {
    lot_num_ = l_n;
  }
};


#endif