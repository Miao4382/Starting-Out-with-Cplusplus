#ifndef LARGER
#define LARGER

template <class T1, class T2>
int Larger(T1 var1, T2 var2)
{
  if (sizeof(var1) >= sizeof(var2))
    return sizeof(var1);
  
  return sizeof(var2);
}

#endif