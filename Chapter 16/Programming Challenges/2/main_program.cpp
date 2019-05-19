#include "mil_time.h"
#include <iostream>
#include <cstdlib>

int main()
{
  try 
  {
    MilTime t(2329, 43);
    std::cout << "The inputed time is: " << t.getHour() << ":" << t.getMin() << ":" << t.getSec() << "\n";
  }
  
  catch (MilTime::BadHour)
  {
    std::cout << "Invalid hour inputed, program exiting...\n";
    exit(0);
  }
  catch (MilTime::BadSecond)
  {
    std::cout << "Invalid second inputed, program exiting...\n";
    exit(0);
  }
  
  return 0;
}