#include <cassert>

template <typename T>
T *insertionsort(T *arr, int length)
{
  T *result = new T[length],
    tmp;
  int i, j;
  assert(length > 0);
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
