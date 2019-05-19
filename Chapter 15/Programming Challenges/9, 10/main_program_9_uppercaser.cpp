#include <iostream>
#include "uppercaser.h"

int main()
{
  Uppercaser file_filter;
  
  file_filter.set_input_file_path();
  file_filter.set_output_file_path();
  
  file_filter.DoFilter();
  
  return 0;
}