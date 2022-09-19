#include <iostream>
#include <cassert>

template <typename T>
T *selection_sort(T *values, unsigned length)
{
  T num, *result = new T[length];
  unsigned i, j;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = values[i];
  for (i = 0; i < length; i++)
  {
    num = result[i];
    j = i;
    while (++j < length)
    {
      if (result[j] < num)
      {
        result[i] = result[j];
        result[j] = num;
        num = result[i];
      }
    }
  }
  return result;
}
