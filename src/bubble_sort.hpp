#include <iostream>
#include <cassert>

template <typename T>
T *bubble_sort(T *values, unsigned length)
{
  T num, *result = new T[length];
  unsigned i, j = 0;
  bool changes = true;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = values[i];
  while (++j < length && changes)
  {
    changes = false;
    for (i = 1; i < length; i++)
    {
      num = result[i];
      if (num < result[i - 1])
      {
        result[i] = result[i - 1];
        result[i - 1] = num;
        changes = true;
      }
    }
  }
  return result;
}
