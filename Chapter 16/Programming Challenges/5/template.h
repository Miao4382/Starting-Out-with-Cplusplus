template <class T>
T Total(int num, T& sum)
{
  T temp;
  sum = 0;
  
  for (int i = 1; i <= num; i++)
  {
    std::cout << "Please input value " << i << ": ";
    std::cin >> temp;
    sum += temp;
  }
  
  return sum;
}