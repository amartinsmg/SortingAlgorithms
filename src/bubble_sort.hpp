#include <iostream>

template <typename T>
T *bubble_sort(T *values, unsigned length)
{
  T num, *result = (T *)malloc(sizeof(*result) * length);
  unsigned i, j = 0;
  bool changes;
  for (i = 0; i < length; i++)
    result[i] = values[i];
  while (++j < length)
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
    if (!changes)
    {
      break;
    }
  }
  return result;
}
