template <class T>
T Minimum(T v1, T v2)
{
  if (v1 > v2)
    return v2;
  
  return v1;
}

template <class T>
T Maximum(T v1, T v2)
{
  if (v1 > v2)
    return v1;
  
  return v2;
}

