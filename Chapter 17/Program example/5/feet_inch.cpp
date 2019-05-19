#include "feet_inch.h"

void FeetInch::Simplify()
{
	if (inch < 0) //when inch is less than zero, subtract from feet or inch
	{
		feet -= (-inch) / 12 + 1;
		inch += ((-inch) / 12 + 1) * 12;
	}

	else if (inch >= 12) //when inch is greater than 12, add to feet
	{
		feet += inch / 12;
		inch = inch % 12;
	}
}

FeetInch FeetInch::operator+ (int i)
{
	FeetInch temp;
	temp.feet = feet;
	temp.inch = inch + i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

FeetInch FeetInch::operator+ (const FeetInch &d)
{
	FeetInch temp;
	temp.feet = feet + d.feet;
	temp.inch = inch + d.inch;
	temp.Simplify();
	return temp;
}

FeetInch FeetInch::operator- (int i)
{
	FeetInch temp;
	temp.feet = feet;
	temp.inch = inch - i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

FeetInch FeetInch::operator- (const FeetInch &d)
{
	FeetInch temp;
	temp.feet = feet - d.feet;
	temp.inch = inch - d.inch;
	temp.Simplify();
	return temp;
}

FeetInch FeetInch::operator++ ()
{
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

FeetInch FeetInch::operator++ (int)
{
	FeetInch temp = *this; //temp object to hold current value
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

FeetInch FeetInch::operator-- ()
{
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

FeetInch FeetInch::operator-- (int)
{
	FeetInch temp = *this;
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

bool FeetInch::operator> (const FeetInch &right)
{
	if (feet > right.feet)
		return true;
	else if (feet == right.feet)
	{
		if (inch > right.inch)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool FeetInch::operator< (const FeetInch &right)
{
	if (feet < right.feet)
		return true;
	else if (feet == right.feet)
	{
		if (inch < right.inch)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool FeetInch::operator== (const FeetInch &right)
{
	if (feet == right.feet && inch == right.inch)
		return true;
	else
		return false;
}


bool FeetInch::operator!= (const FeetInch& right)
{
  if (*this == right)
    return false;
  
  return true;
}

bool FeetInch::operator>=(const FeetInch& right)
{
  if (*this < right)
    return false;
  
  return true;
}

bool FeetInch::operator<=(const FeetInch& right)
{
  if (*this > right)
    return false;
  
  return true;
}