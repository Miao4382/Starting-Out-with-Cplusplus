#include "mil_time.h"
#include <iostream>

int main()
{
  MilTime time1(1730, 55);
  
  std::cout << "The military hour is: " << time1.GetHour() << "\n"
  << "The military second is: " << time1.getSec() << "\n"
  << "The normal time is: " << time1.getHour() << ":" << time1.getMin() << ":"
  << time1.getSec() << "\n";
  
  return 0;
}