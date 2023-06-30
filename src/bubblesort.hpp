#include <cassert>

template <typename T>
T *bubblesort(T *arr, int length)
{
  T *result = new T[length],
    tmp;
  int i, j;
  bool hasSwap;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = arr[i];
  for (i = 0; i < length; i++)
  {
    hasSwap = false;
    for (j = 1; j < length; j++)
    {
      tmp = result[j];
      if (tmp < result[j - 1])
      {
        result[j] = result[j - 1];
        result[j - 1] = tmp;
        hasSwap = true;
      }
    }
    if (!hasSwap)
      break;
  }
  return result;
}
