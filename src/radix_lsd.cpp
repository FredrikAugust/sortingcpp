/**
 * @file radix_lsd.cpp
 * @brief Trying to implement some simple sorting algorithms in C++
 * @author Fredrik August Madsen-Malmo
 * @version 0.1
 * @date 2016-10-12
 */

#include <iostream>
#include <vector>
#include <Magick++.h>
#include "sorthelpers.h"

using namespace std;

vector<int> radix_lsd_sort(vector<int> arr)
{
  // get length of longest number
  // do magic
  // profit

  return arr;
}

int main(int argc, char *argv[])
{
  srand(time(NULL));
  int nums_to_sort = argc > 1 ? stoi(argv[1]) : 50;
  printf("Nums to sort: %i\n", nums_to_sort);

  vector<int> random_ints = shuffled_array(nums_to_sort);

  // Display random nums for debugging purposes
  for (int i = 0; i < nums_to_sort; i++)
  {
    printf("%i ", random_ints[i]);
  }
  printf("\nEnd of random nums.\n");

  vector<int> sorted_nums = radix_lsd_sort(random_ints);

  // Display sorted numbers
  for (int i = 0; i < nums_to_sort; i++)
  {
    printf("%i ", sorted_nums[i]);
  }
  printf("\nEnd of sorted nums.\n");

  Magick::InitializeMagick(*argv);

  return 0;
}
