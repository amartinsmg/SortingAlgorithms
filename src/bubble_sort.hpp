#include <iostream>
#include <cassert>

template <typename T>
T *bubble_sort(T *values, unsigned length)
{
  T num, *result = new T[length];
  unsigned i, j;
  bool changes;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = values[i];
  for (i = 0; i < length; i++)
  {
    changes = false;
    for (j = 1; j < length; j++)
    {
      num = result[j];
      if (num < result[j - 1])
      {
        result[j] = result[j - 1];
        result[j - 1] = num;
        changes = true;
      }
    }
    if (!changes)
      break;
  }
  return result;
}
