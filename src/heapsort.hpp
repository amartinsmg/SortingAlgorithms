#include <cassert>

template <typename T>
T *heapsort(T *arr, int length)
{
  T *result = new T[length],
    tmp;
  int i, j, left, right,
      heapLength = length;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = arr[i];
  while (heapLength > 1)
  {
    for (i = heapLength / 2; i >= 0; i--)
    {
      for (j = i; j < heapLength / 2; j++)
      {
        left = 2 * j + 1;
        right = left + 1;
        if (left < heapLength && result[j] < result[left])
        {
          tmp = result[j];
          result[j] = result[left];
          result[left] = tmp;
        }
        if (right < heapLength && result[j] < result[right])
        {
          tmp = result[j];
          result[j] = result[right];
          result[right] = tmp;
        }
      }
    }
    tmp = result[--heapLength];
    result[heapLength] = result[0];
    result[0] = tmp;
  }
  return result;
}
