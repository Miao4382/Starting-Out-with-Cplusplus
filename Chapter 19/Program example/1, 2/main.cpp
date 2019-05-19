#include <iostream>
const int NUM = 10;

void Show(int times)
{
  if (times > 0)
  {
    std::cout << "This is a recursive function, recursive depth: " << times << "\n";
    Show(times - 1);
    std::cout << "Now leaving the recursion instances: " << times << "/" << NUM << "\n";
  }

}

int main()
{
  Show(NUM);
  return 0;
}