#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <cmath>
#include <cstddef>
#include <vector>

namespace Sort {
/**
 * @brief Sorts an array in ascending order using the merge sort algorithm.
 * @tparam T The type of the array elements.
 * @param arr The input array to be sorted.
 * @return A new array containing the sorted elements.
 * @note The input array remains unchanged.
 */

template <typename T>
static inline std::vector<T> mergesort(const std::vector<T> arr) {
  size_t i, j, k, half, targetIndex, leftIndex, rightIndex, pow2_i;
  size_t length = arr.size(), log2_length = (size_t)ceil(log2((double)length));
  std::vector<T> aux1 = arr, aux2 = arr, result(length);
  T *src, *target, *left, *right;
  T *buffer1 = aux1.data(), *buffer2 = aux2.data();

  if (length <= 1) {
    return result;
  }

  for (i = 1; i <= log2_length; i++) {
    src = i % 2 ? buffer1 : buffer2, target = !(i % 2) ? buffer1 : buffer2;
    targetIndex = 0;
    pow2_i = 1 << i;
    half = pow2_i / 2;

    for (j = 0; j < length; j += pow2_i) {
      left = (T *)(src + j);
      right = (T *)(left + half);
      leftIndex = rightIndex = 0;
      for (k = 0; k < pow2_i && targetIndex < length; k++)
        if (leftIndex >= half)
          target[targetIndex++] = right[rightIndex++];
        else if (rightIndex >= half || j + half + rightIndex >= length)
          target[targetIndex++] = left[leftIndex++];
        else
          target[targetIndex++] = left[leftIndex] < right[rightIndex]
                                      ? left[leftIndex++]
                                      : right[rightIndex++];
    }
  }

  if (log2_length % 2)
    std::copy(buffer2, buffer2 + length, result.begin());
  else
    std::copy(buffer1, buffer1 + length, result.begin());

  return result;
}

} // namespace Sort

#endif /* MERGE_SORT_HPP */
