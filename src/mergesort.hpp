#include <cassert>
#include <cmath>

template <typename T>
T *mergesort(T *values, unsigned length)
{
  T *intermediate1 = new T[length],
    *intermediate2 = new T[length],
    *from, *to, *left, *right, *result;
  unsigned i, j, k, toIndex, leftIndex, rightIndex,
      log2_length, power2_i, half;
  assert(length > 0);
  log2_length = ceil(log2(length));
  for (i = 0; i < length; i++)
    intermediate1[i] = values[i];
  for (i = 1; i <= log2_length; i++)
  {
    from = i % 2 ? intermediate1 : intermediate2,
    to = !(i % 2) ? intermediate1 : intermediate2;
    toIndex = 0;
    power2_i = pow(2, i);
    half = power2_i / 2;
    for (j = 0; j < length; j += power2_i)
    {
      left = (T *)(from + j);
      right = (T *)(left + half);
      leftIndex = rightIndex = 0;
      k = -1;
      while (++k < power2_i && toIndex < length)
      {
        if (leftIndex >= half)
          to[toIndex++] = right[rightIndex++];
        else if (rightIndex >= half || j + half + rightIndex >= length)
          to[toIndex++] = left[leftIndex++];
        else
          to[toIndex++] = left[leftIndex] < right[rightIndex] ? left[leftIndex++] : right[rightIndex++];
      }
    }
  }
  result = log2_length % 2 ? intermediate2 : intermediate1;
  return result;
}
