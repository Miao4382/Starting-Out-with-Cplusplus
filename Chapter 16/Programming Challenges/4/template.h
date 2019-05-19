template <class T>
T Abs(T value)
{
  if (value < 0)
    return -value;
  
  return value;
}