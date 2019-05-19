#ifndef BASE_2_h
#define BASE_2_h

class Base2
{
protected:
  int base_value_; // ambiguous variable
public:
  Base2()
  { base_value_ = 2; }
  
  // accessor
  int base_value() const 
  { return base_value_; }
};


#endif