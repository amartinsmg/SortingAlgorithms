#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <cstddef>
#include <vector>

namespace Sort {
/**
 * @brief Sorts an array in ascending order using the bubble sort algorithm.
 * @tparam T The type of the array elements.
 * @param arr The input array to be sorted.
 * @return A new array containing the sorted elements.
 * @note The input array remains unchanged.
 */

template <typename T>
static inline std::vector<T> bubblesort(const std::vector<T> arr) {

  T tmp;
  size_t i, j;
  size_t length = arr.size();
  bool hasSwap = true;
  std::vector<T> result(arr);

  if (length <= 1) {
    return result;
  }

  for (i = 0; i < length && hasSwap; i++) {
    hasSwap = false;
    for (j = 1; j < length; j++) {
      tmp = result[j];
      if (tmp < result[j - 1]) {
        result[j] = result[j - 1];
        result[j - 1] = tmp;
        hasSwap = true;
      }
    }
  }
  return result;
}

} // namespace Sort

#endif /* BUBBLE_SORT_HPP */
