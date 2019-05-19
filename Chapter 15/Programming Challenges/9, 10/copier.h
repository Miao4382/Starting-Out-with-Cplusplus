// copy all character
#ifndef COPIER_H
#define COPIER_H
#include "file_filter.h"

class Copier : public FileFilter
{
protected:
  virtual char Transform(char ch)
  { return ch; }
};


#endif