#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <cstddef>
#include <vector>

namespace Sort {
/**
 * @brief Helper function to perform the recursive steps of the quick sort
 * algorithm. This function partitions the array around a pivot and recursively
 * sorts the subarrays.
 * @tparam T The type of the array elements.
 * @param arr The array to be sorted.
 * @param left The starting index of the subarray to be sorted.
 * @param right The ending index of the subarray to be sorted.
 */
template <typename T>
static void quicksort_pipeline(T *arr, size_t left, size_t right) {
  if (left >= right)
    return;

  size_t j;
  size_t i = left;
  T tmp;
  T pivot = arr[right];

  for (j = i; j <= right; j++) {
    if (arr[j] < pivot) {
      tmp = arr[i];
      arr[i++] = arr[j];
      arr[j] = tmp;
    }
  }
  arr[right] = arr[i];
  arr[i] = pivot;
  if (i != left)
    quicksort_pipeline(arr, left, i - 1);
  if (i != right)
    quicksort_pipeline(arr, i + 1, right);
}

/**
 * @brief Sorts an array in ascending order using the quick sort algorithm.
 * @tparam T The type of the array elements.
 * @param arr The input array to be sorted.
 * @return A new array containing the sorted elements.
 * @note The input array remains unchanged.
 */

template <typename T>
static inline std::vector<T> quicksort(const std::vector<T> arr) {
  std::vector<T> result(arr);

  if (arr.size() <= 1) {
    return result;
  }

  quicksort_pipeline(result.data(), 0, arr.size() - 1);

  return result;
}

} // namespace Sort

#endif /* QUICK_SORT_HPP */
