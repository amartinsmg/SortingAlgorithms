#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <cstddef>
#include <vector>

namespace Sort {
/**
 * @brief Sorts an array in ascending order using the selection sort algorithm.
 * @tparam T The type of the array elements.
 * @param arr The input array to be sorted.
 * @return A new array containing the sorted elements.
 * @note The input array remains unchanged.
 */

template <typename T>
static inline std::vector<T> selectionsort(const std::vector<T> arr) {
  T tmp;
  size_t i, j;
  size_t length = arr.size();
  std::vector<T> result(arr);

  if (length <= 1) {
    return result;
  }

  for (i = 0; i < length; i++) {
    tmp = result[i];

    for (j = i + 1; j < length; j++) {
      if (result[j] < tmp) {
        result[i] = result[j];
        result[j] = tmp;
        tmp = result[i];
      }
    }
  }

  return result;
}

} // namespace Sort

#endif /* SELECTION_SORT_HPP */
