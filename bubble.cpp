/**
 * @file bubblesort.cpp
 * @brief Trying to implement some simple sorting algorithms in C++
 * @author Fredrik August Madsen-Malmo
 * @version 0.1
 * @date 2016-10-08
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Generate array with x pseudo-random numbers; this is what we will sort later
vector<int> pseudo_random_array(int size)
{
  vector<int> output;

  for (int i = 0; i < size; i++)
  {
    // from 1 -> x
    output.push_back(rand() % size + 1);
  }

  return output;
}

vector<int> bubble_sort(vector<int> arr, int size, int iteration=1)
{
  int prev, curr;

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

  if (iteration != size)
  {
    return bubble_sort(arr, size, iteration + 1);
  }
  else
  {
    return arr;
  }
}

int main(int argc, char *argv[])
{
  srand(time(NULL));
  int nums_to_sort = argc > 1 ? stoi(argv[1]) : 50;
  printf("Nums to sort: %i\n", nums_to_sort);

  vector<int> random_ints = pseudo_random_array(nums_to_sort);

  // Display random nums for debugging purposes
  for (int i = 0; i < nums_to_sort; i++)
  {
    printf("%i ", random_ints[i]);
  }
  printf("\nEnd of random nums.\n");

  vector<int> sorted_nums = bubble_sort(random_ints, nums_to_sort);

  // Display sorted numbers
  for (int i = 0; i < nums_to_sort; i++)
  {
    printf("%i ", sorted_nums[i]);
  }
  printf("End of sorted nums.\n");

  return 0;
}
