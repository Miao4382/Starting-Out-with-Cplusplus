#include <iostream>

void Sign(int n)
{
  if (n > 0)
  {
    Sign(n - 1);
    std::cout << "No Parking\n";
  }
}

void sign(int n)
{
  while (n > 0)
  {
    std::cout << "No Parking\n";
    n--;    
  }
}

int main()
{
  std::cout << "Test original function:\n";
  sign(5);
  std::cout << "\nTest recursive version:\n";
  Sign(5);
  
  return 0;
}
