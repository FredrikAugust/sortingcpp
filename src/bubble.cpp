/**
 * @file bubble.cpp
 * @brief Trying to implement some simple sorting algorithms in C++
 * @author Fredrik August Madsen-Malmo
 * @version 0.1
 * @date 2016-10-08
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <Magick++.h>
#include "sorthelpers.h"

using namespace std;

// Main function that does all the heavy lifting
vector<int> bubble_sort(vector<int> arr, int iteration = 1)
{
  int prev, curr;
  int size = arr.size();

  for (int i = 1; i <= size - iteration; i++)
  {
    prev = arr[i - 1];
    curr = arr[i];

    if (prev > curr)
    {
      arr[i] = prev;
      arr[i - 1] = curr;
    }
  }

  stringstream ss;
  ss << iteration;
  string iteration_s = ss.str();

  if (iteration != size)
  {
    draw_vector(arr, string((4 - iteration_s.length()), '0') + iteration_s);
    return bubble_sort(arr, iteration + 1);
  }
  else
  {
    draw_vector(arr, string((4 - iteration_s.length()), '0') + iteration_s);
    return arr;
  }
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

  vector<int> sorted_nums = bubble_sort(random_ints);

  // Display sorted numbers
  for (int i = 0; i < nums_to_sort; i++)
  {
    printf("%i ", sorted_nums[i]);
  }
  printf("\nEnd of sorted nums.\n");

  Magick::InitializeMagick(*argv);

  return 0;
}
