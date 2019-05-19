#ifndef BASE_1_h
#define BASE_1_h

class Base1
{
protected:
  int base_value_; // ambiguous variable
public:
  Base1()
  { base_value_ = 1; }
  
  // accessor
  int base_value() const 
  { return base_value_; }
};


#endif