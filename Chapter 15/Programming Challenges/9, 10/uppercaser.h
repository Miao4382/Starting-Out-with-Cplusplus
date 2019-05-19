// transform all character to uppercase 
#ifndef UPPERCASER_H
#define UPPERCASER_H
#include <cctype>
#include "file_filter.h"

class Uppercaser : public FileFilter
{
protected:
  virtual char Transform(char ch)
  {
    return toupper(ch);
  }
};


#endif