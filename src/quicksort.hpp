#include <cassert>
#include <cstdlib>

template <typename T>
T *quicksort(T *arr, int length)
{
  T *result = new T[length],
    pivot, tmp;
  int i, j, k, low, high,
      **rangeIndexes = (int **)malloc(sizeof(*rangeIndexes)),
      rangeIndexesLength = 1;
  rangeIndexes[0] = (int *)malloc(sizeof(**rangeIndexes) * 2);
  rangeIndexes[0][0] = 0;
  rangeIndexes[0][1] = length - 1;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = arr[i];
  for (i = 0; i < rangeIndexesLength; i++)
  {
    k = low = rangeIndexes[i][0];
    high = rangeIndexes[i][1];
    free(rangeIndexes[i]);
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
      j = rangeIndexesLength;
      rangeIndexes = (int **)realloc(rangeIndexes, sizeof(*rangeIndexes) * ++rangeIndexesLength);
      rangeIndexes[j] = (int *)malloc(sizeof(**rangeIndexes) * 2);
      rangeIndexes[j][0] = low;
      rangeIndexes[j][1] = k - 1;
    }
    if (k != high)
    {
      j = rangeIndexesLength;
      rangeIndexes = (int **)realloc(rangeIndexes, sizeof(*rangeIndexes) * ++rangeIndexesLength);
      rangeIndexes[j] = (int *)malloc(sizeof(**rangeIndexes) * 2);
      rangeIndexes[j][0] = k + 1;
      rangeIndexes[j][1] = high;
    }
  }

  return result;
}
