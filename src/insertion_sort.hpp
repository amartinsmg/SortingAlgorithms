#include <iostream>
#include <cassert>

template <typename T>
T *insertion_sort(T *values, unsigned length)
{
  T num, *result = new T[length];
  unsigned i;
  int j;
  assert(length > 0);
  result[0] = values[0];
  for (i = 1; i < length; i++)
  {
    result[i] = num = values[i];
    j = i;
    while (--j >= 0 && num < result[j])
    {
      result[j + 1] = result[j];
      result[j] = num;
    }
  }
  return result;
}
