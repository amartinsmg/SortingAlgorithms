#include <iostream>
#include <cassert>
#include "../bubble_sort.hpp"
#include "../insertion_sort.hpp"
#include "../selection_sort.hpp"

#define NUM 64

template <typename T>
void compareArrays(T *arr1, T *arr2, unsigned length)
{
  unsigned i;
  for (i = 0; i < length; i++)
    assert(arr1[i] == arr2[i]);
}

int main()
{
  double arr1[NUM] = {71.57, 31.01, 92.51, 92.7, 43.56, 71.22, 16.32,
                      97.84, 83.77, 35.27, 74.38, 25.75, 27.79, 51.79,
                      47.78, 97.9, 70.14, 76.39, 26.35, 91.8, 19.94,
                      94.77, 20.75, 78.2, 12.62, 49.99, 2.14, 8.9,
                      89.65, 35.26, 71.68, 11.36, 17.36, 50.64, 34.21,
                      90.52, 35.71, 49.54, 16.73, 2.39, 66.92, 64.6,
                      17.52, 30.42, 16.84, 30.93, 8.3, 97, 10.48,
                      98.02, 62.19, 92.54, 78.67, 65.44, 26.66, 80.57,
                      47.16, 5.31, 61.53, 54.21, 22.94, 63.68, 14.15,
                      76.11},
         sortedArr1[NUM] = {2.14, 2.39, 5.31, 8.3, 8.9, 10.48, 11.36,
                            12.62, 14.15, 16.32, 16.73, 16.84, 17.36, 17.52,
                            19.94, 20.75, 22.94, 25.75, 26.35, 26.66, 27.79,
                            30.42, 30.93, 31.01, 34.21, 35.26, 35.27, 35.71,
                            43.56, 47.16, 47.78, 49.54, 49.99, 50.64, 51.79,
                            54.21, 61.53, 62.19, 63.68, 64.6, 65.44, 66.92,
                            70.14, 71.22, 71.57, 71.68, 74.38, 76.11, 76.39,
                            78.2, 78.67, 80.57, 83.77, 89.65, 90.52, 91.8,
                            92.51, 92.54, 92.7, 94.77, 97, 97.84, 97.9,
                            98.02};

  int arr2[NUM] = {59, 34, 90, 99, 10, 84, 62, 38, 92, 8, 79, 84,
                   46, 44, 95, 72, 32, 94, 2, 92, 7, 93, 35, 59,
                   77, 80, 48, 87, 11, 68, 2, 38, 80, 43, 50, 97,
                   54, 87, 56, 85, 90, 74, 97, 9, 81, 99, 51, 54,
                   74, 57, 99, 8, 83, 24, 55, 20, 36, 66, 24, 38,
                   96, 57, 52, 6},
      sortedArr2[NUM] = {2, 2, 6, 7, 8, 8, 9, 10, 11, 20, 24, 24,
                         32, 34, 35, 36, 38, 38, 38, 43, 44, 46, 48, 50,
                         51, 52, 54, 54, 55, 56, 57, 57, 59, 59, 62, 66,
                         68, 72, 74, 74, 77, 79, 80, 80, 81, 83, 84, 84,
                         85, 87, 87, 90, 90, 92, 92, 93, 94, 95, 96, 97,
                         97, 99, 99, 99},
      arr3[NUM] = {5476, 5476, 9216, 1600, 6889, 1024, 289, 324, 5041,
                   1936, 100, 144, 3969, 3600, 441, 6724, 3481, 16, 16, 729,
                   2025, 7921, 5041, 1296, 8836, 1936, 1, 6084, 5476, 729, 361,
                   1936, 441, 1296, 2116, 3364, 676, 1024, 400, 16, 64, 1156, 3025,
                   8836, 3249, 1681, 6241, 2025, 8281, 9604, 2209, 144, 10000,
                   2401, 81, 5476, 9025, 3249, 5184, 1296, 7396, 1764, 361, 1296},
      sortedArr3[NUM] = {1, 16, 16, 16, 64, 81, 100, 144,
                         144, 289, 324, 361, 361, 400, 441, 441,
                         676, 729, 729, 1024, 1024, 1156, 1296, 1296,
                         1296, 1296, 1600, 1681, 1764, 1936, 1936, 1936,
                         2025, 2025, 2116, 2209, 2401, 3025, 3249, 3249,
                         3364, 3481, 3600, 3969, 5041, 5041, 5184, 5476,
                         5476, 5476, 5476, 6084, 6241, 6724, 6889, 7396,
                         7921, 8281, 8836, 8836, 9025, 9216, 9604, 10000};

  compareArrays<double>(sortedArr1, bubble_sort<double>(arr1, NUM), NUM);
  compareArrays<double>(sortedArr1, insertion_sort<double>(arr1, NUM), NUM);
  compareArrays<double>(sortedArr1, selection_sort<double>(arr1, NUM), NUM);

  compareArrays<int>(sortedArr2, bubble_sort<int>(arr2, NUM), NUM);
  compareArrays<int>(sortedArr2, insertion_sort<int>(arr2, NUM), NUM);
  compareArrays<int>(sortedArr2, selection_sort<int>(arr2, NUM), NUM);

  compareArrays<int>(sortedArr3, bubble_sort<int>(arr3, NUM), NUM);
  compareArrays<int>(sortedArr3, insertion_sort<int>(arr3, NUM), NUM);
  compareArrays<int>(sortedArr3, selection_sort<int>(arr3, NUM), NUM);

  puts("Passed all tests successfully!");

  return 0;
}