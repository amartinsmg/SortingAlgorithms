#ifndef ARRAY_CMP_HPP
#define ARRAY_CMP_HPP

/**
  @brief Compare two arrays element by element.
  This function compares two arrays of type T element by element, up to the specified length.
  If all elements in the arrays are equal, the function returns true. Otherwise, it returns false.
  @tparam T The type of the array elements.
  @param arr1 The first array to compare.
  @param arr2 The second array to compare.
  @param length The length of the arrays.
  @return True if the arrays are equal, false otherwise.
*/

template <typename T>
bool arrayCmp(T *arr1, T *arr2, int length)
{
  int i;
  for (i = 0; arr1[i] == arr2[i]; i++)
    if (i == length - 1)
      return true;
  return false;
}

#endif /* ARRAY_CMP_HPP */
