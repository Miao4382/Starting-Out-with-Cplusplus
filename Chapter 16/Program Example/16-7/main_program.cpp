#include <iostream>

template <class T>
T square(T num)
{
  return num * num;
}

int main()
{
  double result, input = 2.5;
  result = square(input);
  
  std::cout << "The square of " << input << " is: " << result << "\n";
  
  int result_int, input_int = 5;
  result_int = square(input_int);
  
  std::cout << "The square of " << input_int << " is " << result_int << "\n";
  
  return 0;
}