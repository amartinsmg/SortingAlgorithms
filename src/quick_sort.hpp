#include <iostream>
#include <cassert>
#include <cstdlib>

template <typename T>
T *quick_sort(T *values, unsigned length)
{
  T num, pivot, *result = new T[length];
  unsigned indexesLength = 0,
           **indexes = (unsigned **)malloc(sizeof(*indexes) * ++indexesLength),
           i, j, k, firstI, lastI;
  indexes[0] = (unsigned *)malloc(sizeof(**indexes) * 2);
  indexes[0][0] = 0;
  indexes[0][1] = length - 1;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = values[i];
  for (i = 0; i < indexesLength; i++)
  {
    k = firstI = indexes[i][0];
    lastI = indexes[i][1];
    if (firstI == lastI)
    {
      free(indexes[i]);
      continue;
    }
    pivot = result[lastI];
    for (j = k; j < lastI; j++)
    {
      if (result[j] < pivot)
      {
        num = result[k];
        result[k++] = result[j];
        result[j] = num;
      }
    }
    result[lastI] = result[k];
    result[k] = pivot;
    if (k != firstI)
    {
      j = indexesLength;
      indexes = (unsigned **)realloc(indexes, sizeof(*indexes) * ++indexesLength);
      indexes[j] = (unsigned *)malloc(sizeof(**indexes) * 2);
      indexes[j][0] = firstI;
      indexes[j][1] = k - 1;
    }
    if (k != lastI)
    {
      j = indexesLength;
      indexes = (unsigned **)realloc(indexes, sizeof(*indexes) * ++indexesLength);
      indexes[j] = (unsigned *)malloc(sizeof(**indexes) * 2);
      indexes[j][0] = k + 1;
      indexes[j][1] = lastI;
    }
    free(indexes[i]);
  }

  return result;
}
