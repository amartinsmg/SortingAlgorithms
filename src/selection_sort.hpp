#include <iostream>

template <typename T>
T *selection_sort(double *values, unsigned length)
{
  T num, *result = malloc(sizeof(*result) * length);
  unsigned i, j;
  for (i = 0; i < length; i++)
    result[i] = values[i];
  for (i = 0; i < length; i++)
  {
    num = result[i];
    for (j = i + 1; j < length; j++)
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
