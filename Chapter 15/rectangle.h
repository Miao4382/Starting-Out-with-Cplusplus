#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
  double width_;
  double length_;
public:
  /* Constructor */
  // default, assign 0 to width and length 
  Rectangle();
  // constructor with parameter
  Rectangle(double w, double l);
  
  /* Accessor */
  double GetWidth() const 
  { return width_; }
  double GetLength() const 
  { return length_; }
  double GetArea() const 
  { return width_ * length_; }
  
  /* Mutator */
  void SetWidth(double w)
  { width_ = w; }
  void SetLength(double l)
  { length_ = l; }
};


#endif