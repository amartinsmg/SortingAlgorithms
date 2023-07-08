#include <cassert>
#include <cstdlib>

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

/**
  @brief Sorts an array in ascending order using the quick sort algorithm.
  @tparam T The type of the array elements.
  @param arr The input array to be sorted.
  @param length The length of the array.
  @return A new array containing the sorted elements.
  @note The input array remains unchanged.
  @note The caller is responsible for freeing the memory allocated for the returned array.
*/

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

#endif /* QUICK_SORT_HPP */
