#include <iostream>
#include <ctime>

int Ackermann(int m, int n)
{
  // base case 1
  if (m == 0)
    return n + 1;
  // recursively calculating
  if (n == 0)
    return Ackermann(m - 1, 1);
  
  return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main()
{
  int m, n;
  std::cout << "Input two integers: ";
  std::cin >> m >> n;
  
  time_t time0, time1;
  time0 = time(0);
  
  std::cout << "Ackermann(" << m << ", " << n << ") = " << Ackermann(m,n) << "\n";
  time1 = time(0);
  std::cout << "Time cost: " << time1 - time0 << "\n";
  
  return 0;
}