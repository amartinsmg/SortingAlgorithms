#include <iostream>
#include <cassert>

template <typename T>
T *insertionsort(T *values, unsigned length)
{
  T *result = new T[length],
    tmp;
  int i, j;
  assert(length > 0);
  result[0] = values[0];
  for (i = 1; i < length; i++)
  {
    result[i] = tmp = values[i];
    j = i;
    while (--j >= 0 && tmp < result[j])
    {
      result[j + 1] = result[j];
      result[j] = tmp;
    }
  }
  return result;
}
