#include <iostream>

template <typename T>
T *insertion_sort(double *values, unsigned length)
{
  T num, *result = malloc(sizeof(*result) * length);
  unsigned i, j;
  result[0] = values[0];
  for (i = 1; i < length; i++)
  {
    result[i] = num = values[i];
    for (j = i - 1; j >= 0; j--)
    {
      if (num < result[j])
      {
        result[j + 1] = result[j];
        result[j] = num;
      }
      else
        break;
    }
  }
  return result;
}
