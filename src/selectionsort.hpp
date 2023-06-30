#include <cassert>

template <typename T>
T *selectionsort(T *arr, int length)
{
  T *result = new T[length],
    tmp;
  int i, j;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = arr[i];
  for (i = 0; i < length; i++)
  {
    tmp = result[i];
    j = i;
    while (++j < length)
    {
      if (result[j] < tmp)
      {
        result[i] = result[j];
        result[j] = tmp;
        tmp = result[i];
      }
    }
  }
  return result;
}
