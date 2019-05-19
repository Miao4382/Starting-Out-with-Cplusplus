#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
  double length_;
  double width_;
public:
  /* Exception class */
  class NegativeSizeL
  {
  private:
    double value_; // to hold the negative value 
  public:
    /* Constructor */
    // hold the negative value 
    NegativeSizeL(double v);
    
    /* Accessor */
    double value() const 
    { return value_; }
  };
  
  class NegativeSizeW
  {
  private:
    double value_;
  public:
    /* Constructor */
    // hold the negative value 
    NegativeSizeW(double v);
    
    /* Accessor */
    double value() const 
    { return value_; }
  };
  
  /* Constructor */
  Rectangle()
  {
    length_ = 0.0;
    width_ = 0.0;
  }
  
  /* Mutator */
  void set_length(double l);
  void set_width(double w);
  
  /* Accessor */
  double length() const
  { return length_; }
  double width() const 
  { return width_; }
  double area() const 
  { return length_ * width_; }
};


#endif