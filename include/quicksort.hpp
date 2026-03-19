#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

namespace Sort
{
  /**
   * @brief Helper function to perform the recursive steps of the quick sort algorithm.
   * This function partitions the array around a pivot and recursively sorts the subarrays.
   * @tparam T The type of the array elements.
   * @param arr The array to be sorted.
   * @param left The starting index of the subarray to be sorted.
   * @param right The ending index of the subarray to be sorted.
   */
  template <typename T>
  static void quicksort_pipeline(T *arr, int left, int right)
  {
    if (left >= right)
      return;
    int i, j;
    i = left;
    T tmp,
        pivot = arr[right];

    for (j = i; j <= right; j++)
    {
      if (arr[j] < pivot)
      {
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
   * @param length The length of the array.
   * @return A new array containing the sorted elements.
   * @note The input array remains unchanged.
   * @note The caller is responsible for freeing the memory allocated for the returned array.
   */

  template <typename T>
  static T *quicksort(T *arr, int length)
  {
    if (length <= 0 || arr == nullptr)
      return nullptr;

    T *result = new T[length];
    int i;

    for (i = 0; i < length; i++)
      result[i] = arr[i];

    quicksort_pipeline(result, 0, length - 1);

    return result;
  }

} // Sort

#endif /* QUICK_SORT_HPP */
