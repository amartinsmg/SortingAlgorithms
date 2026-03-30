#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <cmath>
#include <cstdint>
#include <vector>

namespace Sort {
/**
 *  @brief Sorts an array in ascending order using the shell sort algorithm.
 *  @tparam T The type of the array elements.
 *  @param arr The input array to be sorted.
 *  @return A new array containing the sorted elements.
 *  @note The input array remains unchanged.
 */

template <typename T>
static inline std::vector<T> shellsort(const std::vector<T> arr) {
  T tmp;
  int64_t i, j, k, l, pow2_i;
  int64_t length = arr.size(), log2_length = ceil(log2(length));
  std::vector<T> result = arr;

  if (length <= 1) {
    return result;
  }

  for (i = 1; i <= log2_length; i++) {
    pow2_i = pow(2, i);
    for (j = k = 0; j < length; j += pow2_i) {
      while (++k < pow2_i && j + k < length) {
        l = j + k;
        tmp = result[l];
        while (--l >= j && tmp < result[l]) {
          result[l + 1] = result[l];
          result[l] = tmp;
        }
      }
    }
  }

  return result;
}

} // namespace Sort

#endif /* SHELL_SORT_HPP */
