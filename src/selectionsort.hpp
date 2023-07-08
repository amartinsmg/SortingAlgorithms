#include <cassert>

#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

/**
  @brief Sorts an array in ascending order using the selection sort algorithm.
  @tparam T The type of the array elements.
  @param arr The input array to be sorted.
  @param length The length of the array.
  @return A new array containing the sorted elements.
  @note The input array remains unchanged.
  @note The caller is responsible for freeing the memory allocated for the returned array.
*/

template <typename T>
T *selectionsort(T *arr, int length)
{
  T *result = new T[length],
    tmp;
  int i, j;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = arr[i];
  for (i = 0; i < length; i++)
  {
    tmp = result[i];
    j = i;
    while (++j < length)
    {
      if (result[j] < tmp)
      {
        result[i] = result[j];
        result[j] = tmp;
        tmp = result[i];
      }
    }
  }
  return result;
}

#endif /* SELECTION_SORT_HPP */
