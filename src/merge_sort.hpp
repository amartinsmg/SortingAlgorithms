#include <iostream>
#include <cmath>

template <typename T>
T *merge_sort(T *values, unsigned length)
{
  T *intermediate1 = (T *)malloc(sizeof(T) * length),
    *intermediate2 = (T *)malloc(sizeof(T) * length),
    *from = NULL,
    *to = NULL,
    *left = NULL,
    *right = NULL,
    *result = NULL;
  unsigned const LOG2 = ceil(log2(length));
  unsigned i, j, k, toIndex, leftIndex, rightIndex, power2_i, half;
  for (i = 0; i < length; i++)
    intermediate1[i] = intermediate2[i] = values[i];
  for (i = 1; i <= LOG2; i++)
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
      for (k = 0; k < power2_i; k++)
      {
        if (toIndex >= length)
          break;
        if (leftIndex >= half)
          to[toIndex++] = right[rightIndex++];
        else if (rightIndex >= half || j + half + rightIndex >= length)
          to[toIndex++] = left[leftIndex++];
        else
          to[toIndex++] = left[leftIndex] < right[rightIndex] ? left[leftIndex++] : right[rightIndex++];
      }
    }
  }
  result = LOG2 % 2 ? intermediate2 : intermediate1;
  return result;
}
