#include "searchable_vector.h"
#include <iostream>

int main()
{
  SearchableVector<char*> line(15, 'A');
  std::cout << line << "\n";

  line.push_back('B');

  std::cout << line << "\n";

  line.push_back('C');
  line.push_back('D');

  if (line.Find('E') != -1)
    std::cout << "Found!\n";
  else
    std::cout << "Not found!\n";

  return 0;

}
