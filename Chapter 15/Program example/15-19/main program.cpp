#include <iostream>
#include <string>
#include "cs_student.h"

int main()
{
  CsStudent student_1("Yu Miao", "GO-11230", 2017, 19, 35, 55);
  
  student_1.GetRemainingHours();
  
  return 0;
}