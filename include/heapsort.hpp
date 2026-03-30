#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <cstdint>
#include <vector>

namespace Sort {
/**
 * @brief Sorts an array in ascending order using the heap sort algorithm.
 * @tparam T The type of the array elements.
 * @param arr The input array to be sorted.
 * @return A new array containing the sorted elements.
 * @note The input array remains unchanged.
 */

template <typename T>
static inline std::vector<T> heapsort(const std::vector<T> arr) {
  if (arr.size() <= 1) {
    std::vector<T> v(arr);
    return v;
  }

  std::vector<T> result = arr;
  T tmp;
  int64_t i, j, left, right, heapLength = arr.size();

  while (heapLength > 1) {
    for (i = heapLength / 2; i >= 0; i--) {
      for (j = i; j < heapLength / 2; j++) {
        left = 2 * j + 1;
        right = left + 1;
        if (left < heapLength && result[j] < result[left]) {
          tmp = result[j];
          result[j] = result[left];
          result[left] = tmp;
        }
        if (right < heapLength && result[j] < result[right]) {
          tmp = result[j];
          result[j] = result[right];
          result[right] = tmp;
        }
      }
    }

    tmp = result[--heapLength];
    result[heapLength] = result[0];
    result[0] = tmp;
  }

  return result;
}

} // namespace Sort

#endif /* HEAP_SORT_HPP */
