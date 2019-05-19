#ifndef FEETINCHE_H
#define FEETINCHE_H
#include <iostream>

class FeetInch
{
private:
	int feet; //hold value of feet 
	int inch; //hold value of inch 
	void Simplify(); //to simplify feet and inch value. It will check if inch >= 12 or < 0. If inch >= 12, transfer to corresponding value of feet; if inch < 0, subtract from feet and get the final value 
public:
	//constructor 
  // accepts two integer
	FeetInch(int f = 0, int i = 0) //constructor, initialize values for feet and inch 
	{
		feet = f; inch = i; Simplify();
	}
  
  // accepts a double number, which is the value of feet, will convert to feet inch
  FeetInch(double f)
  {
    feet = f;
    inch = (f - feet) * 12;
  }

	/* Mutator */
	void SetFeet(int f)
	{
		feet = f;
	}
	void SetInch(int i)
	{
		inch = i; Simplify(); //after each setting, has to be simplified
	}

	/* Accessor */
	int GetFeet() const
	{
		return feet;
	}
	int GetInch() const
	{
		return inch;
	}

	/* Operator function */
	//+, - operator, add or subtract an int value to inches, then call simplify function to simplify. Return the simplified 
	FeetInch operator+ (int i);
	FeetInch operator+ (const FeetInch &d);
	FeetInch operator- (int i);
	FeetInch operator- (const FeetInch &d);
	//++ operator
	FeetInch operator++ ();
	FeetInch operator++ (int);
	FeetInch operator-- ();
	FeetInch operator-- (int);
	//relational operator
	bool operator> (const FeetInch &right);
	bool operator< (const FeetInch &right);
	bool operator== (const FeetInch &right);
  bool operator!= (const FeetInch& right);
  bool operator>=(const FeetInch& right);
  bool operator<=(const FeetInch& right);
  
	//stream insertion operator
	friend std::ostream& operator<< (std::ostream &strm, const FeetInch &obj)
	{
		strm << obj.feet << " feet, " << obj.inch << " inches";
		return strm;
	}
	//stream extraction operator
	friend std::istream& operator>> (std::istream &strm, FeetInch &obj)
	{
		std::cout << "Please input the feet: ";
		strm >> obj.feet;
		std::cout << "Please input the inch: ";
		strm >> obj.inch;
		obj.Simplify(); //to simplify
		return strm;
	}
	
};

#endif
