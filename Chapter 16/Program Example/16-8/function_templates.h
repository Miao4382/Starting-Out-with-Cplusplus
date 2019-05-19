#ifndef SWAPVARS
#define SWAPVARS

template <class T>

// to swap two variables
void SwapVars(T& v1, T& v2)
{
  T temp = v1;
  v1 = v2;
  v2 = temp;
}

#endif