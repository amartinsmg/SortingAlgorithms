#include <cassert>
#include <cmath>

#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

/**
  @brief Sorts an array in ascending order using the merge sort algorithm.
  @tparam T The type of the array elements.
  @param arr The input array to be sorted.
  @param length The length of the array.
  @return A new array containing the sorted elements.
  @note The input array remains unchanged.
  @note The caller is responsible for freeing the memory allocated for the returned array.
*/

template <typename T>
T *mergesort(T *arr, int length)
{
  T *buffer1 = new T[length],
    *buffer2 = new T[length],
    *src, *target, *left, *right, *result;
  int i, j, k, half, targetIndex, leftIndex, rightIndex, log2_length, pow2_i;
  assert(length > 0);
  log2_length = (int)ceil(log2((double)length));
  for (i = 0; i < length; i++)
    buffer1[i] = arr[i];
  for (i = 1; i <= log2_length; i++)
  {
    src = i % 2 ? buffer1 : buffer2,
    target = !(i % 2) ? buffer1 : buffer2;
    targetIndex = 0;
    pow2_i = (int)pow(2, (double)i);
    half = pow2_i / 2;
    for (j = 0; j < length; j += pow2_i)
    {
      left = (T *)(src + j);
      right = (T *)(left + half);
      leftIndex = rightIndex = 0;
      k = -1;
      while (++k < pow2_i && targetIndex < length)
      {
        if (leftIndex >= half)
          target[targetIndex++] = right[rightIndex++];
        else if (rightIndex >= half || j + half + rightIndex >= length)
          target[targetIndex++] = left[leftIndex++];
        else
          target[targetIndex++] = left[leftIndex] < right[rightIndex] ? left[leftIndex++] : right[rightIndex++];
      }
    }
  }
  result = log2_length % 2 ? buffer2 : buffer1;
  return result;
}

#endif /* MERGE_SORT_HPP */
