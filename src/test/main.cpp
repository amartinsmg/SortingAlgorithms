#include <iostream>
#include <cassert>
#include <bubblesort.hpp>
#include <heapsort.hpp>
#include <insertionsort.hpp>
#include <mergesort.hpp>
#include <quicksort.hpp>
#include <selectionsort.hpp>
#include <shellsort.hpp>
#include "include/array_cmp.hpp"
#include "include/test.hpp"

#define SIZE 127

/**
  @brief Main function to test sorting algorithms.
  This function tests different sorting algorithms by sorting three distinct arrays: one containing
  doubles,another containing integers, and a third containing long longs. It compares the results
  with pre-sorted arrays.
  @return An integer representing the exit status of the program.
*/

int main()
{
  double arr1[SIZE] = {71.57, 31.01, 92.51, 92.7, 43.56, 71.22, 16.32, 97.84,
                       83.77, 35.27, 74.38, 25.75, 27.79, 51.79, 47.78, 97.9,
                       70.14, 76.39, 26.35, 91.8, 19.94, 94.77, 20.75, 78.2,
                       12.62, 49.99, 2.14, 8.9, 89.65, 35.26, 71.68, 11.36, 17.36,
                       50.64, 34.21, 90.52, 35.71, 49.54, 16.73, 2.39, 66.92,
                       64.6, 17.52, 30.42, 16.84, 30.93, 8.3, 97, 10.48, 98.02,
                       62.19, 92.54, 78.67, 65.44, 26.66, 80.57, 47.16, 5.31,
                       61.53, 54.21, 22.94, 63.68, 14.15, 76.11, 70.19, 56.26,
                       66.96, 75.24, 14.48, 71.92, 96.99, 32.56, 19.98, 44.11,
                       53.79, 25.36, 81.09, 28.33, 19.73, 10, 32.63, 83.35,
                       70.94, 53.49, 30.14, 57.56, 9.47, 16.54, 57.3, 74.32,
                       86.32, 9.85, 16.03, 17.93, 31.14, 35, 71.68, 12.78,
                       80.01, 72.22, 71.47, 45.05, 99.35, 68.33, 57.98, 39.45,
                       95.92, 58.23, 89.49, 53.23, 50.63, 71.14, 12.74, 7.09,
                       23.72, 14.79, 66.95, 99.47, 9.87, 40.6, 34.67, 43.86,
                       33.73, 22.64, 52.23, 48.3, 97.49},
         sortedArr1[SIZE] = {2.14, 2.39, 5.31, 7.09, 8.3, 8.9, 9.47, 9.85, 9.87,
                             10, 10.48, 11.36, 12.62, 12.74, 12.78, 14.15, 14.48,
                             14.79, 16.03, 16.32, 16.54, 16.73, 16.84, 17.36,
                             17.52, 17.93, 19.73, 19.94, 19.98, 20.75, 22.64,
                             22.94, 23.72, 25.36, 25.75, 26.35, 26.66, 27.79,
                             28.33, 30.14, 30.42, 30.93, 31.01, 31.14, 32.56,
                             32.63, 33.73, 34.21, 34.67, 35, 35.26, 35.27, 35.71,
                             39.45, 40.6, 43.56, 43.86, 44.11, 45.05, 47.16,
                             47.78, 48.3, 49.54, 49.99, 50.63, 50.64, 51.79,
                             52.23, 53.23, 53.49, 53.79, 54.21, 56.26, 57.3,
                             57.56, 57.98, 58.23, 61.53, 62.19, 63.68, 64.6,
                             65.44, 66.92, 66.95, 66.96, 68.33, 70.14, 70.19,
                             70.94, 71.14, 71.22, 71.47, 71.57, 71.68, 71.68,
                             71.92, 72.22, 74.32, 74.38, 75.24, 76.11, 76.39,
                             78.2, 78.67, 80.01, 80.57, 81.09, 83.35, 83.77,
                             86.32, 89.49, 89.65, 90.52, 91.8, 92.51, 92.54,
                             92.7, 94.77, 95.92, 96.99, 97, 97.49, 97.84, 97.9,
                             98.02, 99.35, 99.47};

  int arr2[SIZE] = {59, 34, 90, 99, 10, 84, 62, 38, 92, 8, 79, 84,
                    46, 44, 95, 72, 32, 94, 2, 92, 7, 93, 35, 59,
                    77, 80, 48, 87, 11, 68, 2, 38, 80, 43, 50, 97,
                    54, 87, 56, 85, 90, 74, 97, 9, 81, 99, 51, 54,
                    74, 57, 99, 8, 83, 24, 55, 20, 36, 66, 24, 38,
                    96, 57, 52, 6, 65, 30, 72, 49, 42, 95, 10, 55,
                    4, 78, 46, 75, 45, 5, 28, 22, 86, 36, 33, 8, 71,
                    35, 34, 49, 98, 31, 2, 75, 50, 87, 73, 93, 26,
                    32, 15, 68, 93, 25, 25, 12, 89, 52, 6, 62, 37,
                    41, 100, 2, 13, 75, 85, 42, 80, 56, 95, 78, 18,
                    7, 28, 6, 75, 74, 27},
      sortedArr2[SIZE] = {2, 2, 2, 2, 4, 5, 6, 6, 6, 7, 7, 8, 8, 8, 9,
                          10, 10, 11, 12, 13, 15, 18, 20, 22, 24, 24,
                          25, 25, 26, 27, 28, 28, 30, 31, 32, 32, 33,
                          34, 34, 35, 35, 36, 36, 37, 38, 38, 38, 41,
                          42, 42, 43, 44, 45, 46, 46, 48, 49, 49, 50,
                          50, 51, 52, 52, 54, 54, 55, 55, 56, 56, 57,
                          57, 59, 59, 62, 62, 65, 66, 68, 68, 71, 72,
                          72, 73, 74, 74, 74, 75, 75, 75, 75, 77, 78,
                          78, 79, 80, 80, 80, 81, 83, 84, 84, 85, 85,
                          86, 87, 87, 87, 89, 90, 90, 92, 92, 93, 93,
                          93, 94, 95, 95, 95, 96, 97, 97, 98, 99, 99,
                          99, 100};

  long long arr3[SIZE] = {5476, 5476, 9216, 1600, 6889, 1024, 289, 324, 5041,
                          1936, 100, 144, 3969, 3600, 441, 6724, 3481, 16, 16,
                          729, 2025, 7921, 5041, 1296, 8836, 1936, 1, 6084, 5476,
                          729, 361, 1936, 441, 1296, 2116, 3364, 676, 1024, 400,
                          16, 64, 1156, 3025, 8836, 3249, 1681, 6241, 2025, 8281,
                          9604, 2209, 144, 10000, 2401, 81, 5476, 9025, 3249, 5184,
                          1296, 7396, 1764, 361, 1296, 25, 10000, 169, 4761, 121,
                          5776, 7569, 4900, 625, 6724, 5329, 8649, 2401, 841, 6241,
                          9216, 441, 7569, 25, 2601, 9216, 6561, 4096, 225, 3969,
                          2304, 16, 2304, 441, 7569, 6400, 2025, 2809, 5041, 1681,
                          81, 2025, 16, 5929, 81, 1, 2025, 169, 5625, 5329, 169,
                          3481, 900, 576, 1369, 1600, 2401, 3481, 3969, 9025, 2500,
                          1936, 6889, 8100, 144, 900, 841, 169},
            sortedArr3[SIZE] = {1, 1, 16, 16, 16, 16, 16, 25, 25, 64, 81, 81, 81,
                                100, 121, 144, 144, 144, 169, 169, 169, 169, 225,
                                289, 324, 361, 361, 400, 441, 441, 441, 441, 576,
                                625, 676, 729, 729, 841, 841, 900, 900, 1024, 1024,
                                1156, 1296, 1296, 1296, 1296, 1369, 1600, 1600,
                                1681, 1681, 1764, 1936, 1936, 1936, 1936, 2025,
                                2025, 2025, 2025, 2025, 2116, 2209, 2304, 2304,
                                2401, 2401, 2401, 2500, 2601, 2809, 3025, 3249,
                                3249, 3364, 3481, 3481, 3481, 3600, 3969, 3969,
                                3969, 4096, 4761, 4900, 5041, 5041, 5041, 5184,
                                5329, 5329, 5476, 5476, 5476, 5476, 5625, 5776,
                                5929, 6084, 6241, 6241, 6400, 6561, 6724, 6724,
                                6889, 6889, 7396, 7569, 7569, 7569, 7921, 8100,
                                8281, 8649, 8836, 8836, 9025, 9025, 9216, 9216,
                                9216, 9604, 10000, 10000};

  test(1, arrayCmp<double>(sortedArr1, bubblesort<double>(arr1, SIZE), SIZE));
  test(2, arrayCmp<int>(sortedArr2, bubblesort<int>(arr2, SIZE), SIZE));
  test(3, arrayCmp<long long>(sortedArr3, bubblesort<long long>(arr3, SIZE), SIZE));

  test(4, arrayCmp<double>(sortedArr1, insertionsort<double>(arr1, SIZE), SIZE));
  test(5, arrayCmp<int>(sortedArr2, insertionsort<int>(arr2, SIZE), SIZE));
  test(6, arrayCmp<long long>(sortedArr3, insertionsort<long long>(arr3, SIZE), SIZE));

  test(7, arrayCmp<double>(sortedArr1, selectionsort<double>(arr1, SIZE), SIZE));
  test(8, arrayCmp<int>(sortedArr2, selectionsort<int>(arr2, SIZE), SIZE));
  test(9, arrayCmp<long long>(sortedArr3, selectionsort<long long>(arr3, SIZE), SIZE));

  test(10, arrayCmp<double>(sortedArr1, mergesort<double>(arr1, SIZE), SIZE));
  test(11, arrayCmp<int>(sortedArr2, mergesort<int>(arr2, SIZE), SIZE));
  test(12, arrayCmp<long long>(sortedArr3, mergesort<long long>(arr3, SIZE), SIZE));

  test(13, arrayCmp<double>(sortedArr1, quicksort<double>(arr1, SIZE), SIZE));
  test(14, arrayCmp<int>(sortedArr2, quicksort<int>(arr2, SIZE), SIZE));
  test(15, arrayCmp<long long>(sortedArr3, quicksort<long long>(arr3, SIZE), SIZE));

  test(16, arrayCmp<double>(sortedArr1, heapsort<double>(arr1, SIZE), SIZE));
  test(17, arrayCmp<int>(sortedArr2, heapsort<int>(arr2, SIZE), SIZE));
  test(18, arrayCmp<long long>(sortedArr3, heapsort<long long>(arr3, SIZE), SIZE));

  test(19, arrayCmp<double>(sortedArr1, shellsort<double>(arr1, SIZE), SIZE));
  test(20, arrayCmp<int>(sortedArr2, shellsort<int>(arr2, SIZE), SIZE));
  test(21, arrayCmp<long long>(sortedArr3, shellsort<long long>(arr3, SIZE), SIZE));

  std::cout << "Passed all tests successfully!\n";

  return 0;
}