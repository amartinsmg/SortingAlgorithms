#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

/**
 * @brief Sorts an array in ascending order using the inserion sort algorithm.
 * @tparam T The type of the array elements.
 * @param arr The input array to be sorted.
 * @param length The length of the array.
 * @return A new array containing the sorted elements.
 * @note The input array remains unchanged.
 * @note The caller is responsible for freeing the memory allocated for the returned array.
 */

template <typename T>
T *insertionsort(T *arr, int length)
{
  if (length <= 0)
    return nullptr;

  T tmp,
      *result = new T[length];
  int i, j;

  result[0] = arr[0];

  for (i = 1; i < length; i++)
  {
    result[i] = tmp = arr[i];
    j = i;
    while (--j >= 0 && tmp < result[j])
    {
      result[j + 1] = result[j];
      result[j] = tmp;
    }
  }
  return result;
}

#endif /* INSERTION_SORT_HPP */
