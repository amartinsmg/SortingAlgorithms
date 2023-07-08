#include <cassert>

#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

/**
  @brief Sorts an array in ascending order using the bubble sort algorithm.
  @tparam T The type of the array elements.
  @param arr The input array to be sorted.
  @param length The length of the array.
  @return A new array containing the sorted elements.
  @note The input array remains unchanged.
  @note The caller is responsible for freeing the memory allocated for the returned array.
*/

template <typename T>
T *bubblesort(T *arr, int length)
{
  T *result = new T[length],
    tmp;
  int i, j;
  bool hasSwap;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = arr[i];
  for (i = 0; i < length; i++)
  {
    hasSwap = false;
    for (j = 1; j < length; j++)
    {
      tmp = result[j];
      if (tmp < result[j - 1])
      {
        result[j] = result[j - 1];
        result[j - 1] = tmp;
        hasSwap = true;
      }
    }
    if (!hasSwap)
      break;
  }
  return result;
}

#endif /* BUBBLE_SORT_HPP */
