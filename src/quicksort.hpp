#include <iostream>
#include <cassert>
#include <cstdlib>

template <typename T>
T *quicksort(T *values, unsigned length)
{
  T *result = new T[length],
    pivot, tmp;
  unsigned **indexes = (unsigned **)malloc(sizeof(*indexes)),
           indexesLength = 1,
           i, j, k, low, high;
  indexes[0] = (unsigned *)malloc(sizeof(**indexes) * 2);
  indexes[0][0] = 0;
  indexes[0][1] = length - 1;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = values[i];
  for (i = 0; i < indexesLength; i++)
  {
    k = low = indexes[i][0];
    high = indexes[i][1];
    free(indexes[i]);
    if (low == high)
      continue;
    pivot = result[high];
    for (j = k; j < high; j++)
    {
      if (result[j] < pivot)
      {
        tmp = result[k];
        result[k++] = result[j];
        result[j] = tmp;
      }
    }
    result[high] = result[k];
    result[k] = pivot;
    if (k != low)
    {
      j = indexesLength;
      indexes = (unsigned **)realloc(indexes, sizeof(*indexes) * ++indexesLength);
      indexes[j] = (unsigned *)malloc(sizeof(**indexes) * 2);
      indexes[j][0] = low;
      indexes[j][1] = k - 1;
    }
    if (k != high)
    {
      j = indexesLength;
      indexes = (unsigned **)realloc(indexes, sizeof(*indexes) * ++indexesLength);
      indexes[j] = (unsigned *)malloc(sizeof(**indexes) * 2);
      indexes[j][0] = k + 1;
      indexes[j][1] = high;
    }
  }

  return result;
}
