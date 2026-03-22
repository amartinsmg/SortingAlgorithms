#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <cstddef>
#include <cstdint>
#include <vector>

namespace Sort {
/**
 * @brief Sorts an array in ascending order using the insertion sort algorithm.
 * @tparam T The type of the array elements.
 * @param arr The input array to be sorted.
 * @return A new array containing the sorted elements.
 * @note The input array remains unchanged.
 */

template <typename T>
static inline std::vector<T> insertionsort(const std::vector<T> arr) {
  if (arr.size() == 0) {
    std::vector<T> v(0);
    return v;
  }

  std::vector<T> result(arr);
  T tmp;
  size_t i;
  int64_t j;

  for (i = 1; i < arr.size(); i++) {
    tmp = result[i];
    j = i - 1;
    while (j >= 0 && tmp < result[j]) {
      result[j + 1] = result[j];
      result[j--] = tmp;
    }
  }
  return result;
}

} // namespace Sort

#endif /* INSERTION_SORT_HPP */
