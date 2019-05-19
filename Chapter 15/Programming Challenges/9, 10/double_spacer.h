// double spacer, insert a blank line between any two lines of the file
// if you meet one '\n', add another '\n'

#ifndef DOUBLE_SPACER_H
#define DOUBLE_SPACER_H
#include "file_filter.h"
#include <iostream>

class DoubleSpacer : public FileFilter
{
protected:
  // no need to call Transform() in this class, leave it empty
  virtual char Transform(char ch)
  { return 0; }
  
public:
  /* Function */
  // redefine DoFilter 
  void DoFilter()
  {
    if (!(CheckInput(input_file_path_) && CheckOutput(output_file_path_)))
    {
      std::cout << "Invalid file path, please check your file path and reset.\n";
      std::cout << "File convert unsuccessful.\n";
      return;
    }
    
    char ch;
    in.open(input_file_path_);
    out.open(output_file_path_);
    
    while (in.get(ch))
    {
      if (ch == '\n')
        out << "\n\n";
      else
        out << ch;
    }
    
    std::cout << "File convert completed. Please check the file at " << output_file_path_ << "\n";
    
    in.close();
    out.close();    
  }
};


#endif