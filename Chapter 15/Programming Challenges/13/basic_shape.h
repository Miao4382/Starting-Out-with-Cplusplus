#ifndef BASIC_SHAPE_H
#define BASIC_SHAPE_H

class BasicShape
{
private:
  double area_;
  
protected:
  /* Mutator */
  void SetArea(double area)
  { area_ = area; }
  
public:
  /* Accessor */
  double GetArea() const 
  { return area_; }
  
  /* Pure virtual function */
  virtual void CalcArea() = 0;
};


#endif