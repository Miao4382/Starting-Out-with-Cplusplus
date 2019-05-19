#include <iostream>

const int Coin[6] = { 100, 50, 25, 10, 5, 1 };

void Change(int value)
{  
  if (value == 1)
    std::cout << value << " ";
  
  else 
  {
    for (int i = 0; i < 6; i++)
    {
      if (value - Coin[i] > 0)
      {
        Change(value - Coin[i]);
        std::cout << Coin[i] << " ";
      }
      
      else if (value == Coin[i])
      {
        std::cout << Coin[i] << " ";
      }
    }
  }
}

int main()
{
  Change(7);
  
  return 0;
}