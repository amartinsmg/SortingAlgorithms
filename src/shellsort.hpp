#include <cassert>
#include <cmath>

template <typename T>
T *shellsort(T *arr, int length)
{
  T *result = new T[length],
    tmp;
  int i, j, k, l, log2_length, pow2_i;
  assert(length > 0);
  log2_length = ceil(log2(length));
  for (i = 0; i < length; i++)
    result[i] = arr[i];
  for (i = 1; i <= log2_length; i++)
  {
    pow2_i = pow(2, i);
    for (j = 0; j < length; j += pow2_i)
    {
      k = 0;
      while (++k < pow2_i && j + k < length)
      {
        l = j + k;
        tmp = result[l];
        while (--l >= j && tmp < result[l])
        {
          result[l + 1] = result[l];
          result[l] = tmp;
        }
      }
    }
  }
  return result;
}
