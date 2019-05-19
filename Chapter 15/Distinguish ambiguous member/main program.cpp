#include <iostream>
#include "base_1_2.h"

int main()
{
  Base12 obj;
  obj.set_base_value_2(54);
  std::cout << "The base_value: " << obj.Base2::base_value() << "\n";

  return 0;
}