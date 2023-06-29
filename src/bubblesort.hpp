#include <cassert>

template <typename T>
T *bubblesort(T *values, unsigned length)
{
  T *result = new T[length],
    tmp;
  unsigned i, j;
  bool changes;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result[i] = values[i];
  for (i = 0; i < length; i++)
  {
    changes = false;
    for (j = 1; j < length; j++)
    {
      tmp = result[j];
      if (tmp < result[j - 1])
      {
        result[j] = result[j - 1];
        result[j - 1] = tmp;
        changes = true;
      }
    }
    if (!changes)
      break;
  }
  return result;
}
