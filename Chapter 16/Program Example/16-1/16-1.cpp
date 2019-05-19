#include "Mystring.h"
#include <iostream>
#include <string>

double Divide(double num1, double num2);

int main()
{
  double num1, num2;

  std::cout << "Please input two numbers: ";
  std::cin >> num1 >> num2;

  try
  {
    double quotient = Divide(num1, num2);
    std::cout << "num1 / num2 = " << quotient << "\n";
  }

  catch (Mystring exception_string)
  {
    std::cout << exception_string;
  }
  catch (int num)
  {
    switch (num)
    {
    case 1:
      std::cout << "We don't calculate x/1\n"; break;
    case 2:
      std::cout << "We don't calculate x/2\n"; break;
    }
  }

  return 0;
}

double Divide(double num1, double num2)
{
  if (num2 == 0.0)
  {
    Mystring a = "Error: can not divide by zero.\n";
    throw a;
  }

  else if (num2 == 1.0)
  {
    int n = 1;
    throw n;
  }

  else if (num2 == 2.0)
  {
    int n = 2;
    throw n;
  }
  else
    return num1 / num2;
}