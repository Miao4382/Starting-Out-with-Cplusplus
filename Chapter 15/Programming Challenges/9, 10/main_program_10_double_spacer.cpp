#include <iostream>
#include "double_spacer.h"

int main()
{
  DoubleSpacer dbspacer;
  
  dbspacer.set_input_file_path();
  dbspacer.set_output_file_path();
  
  dbspacer.DoFilter();
  
  return 0;
}