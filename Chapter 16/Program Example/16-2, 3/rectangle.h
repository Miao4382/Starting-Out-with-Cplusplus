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
  { }; // empty class declaration
  
  class NegativeSizeW
  { }; // for width exception
  
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