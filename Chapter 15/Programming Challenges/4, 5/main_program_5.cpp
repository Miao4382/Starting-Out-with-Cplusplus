#include <iostream>
#include "time_clock.h"

int main()
{
  TimeClock block(1100, 1200);
  
  std::cout << "Elapsed time: " << block.Elapsed() / 60 << " hour " << block.Elapsed() % 60 << " minute.\n";
  
  return 0;
}