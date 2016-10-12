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

vector<int> bucket(vector<int> vec, int pos, int longest_num)
{
  vector<int> new_vec;
  for (int i = 0; i < 10; i++) {
    for (int vec_pos = 0; vec_pos < vec.size(); vec_pos++) {
      stringstream ss;
      ss << vec[vec_pos];
      string num_s = ss.str();
      num_s = string(longest_num - num_s.length(), '0') + num_s;
      if ((int)num_s[pos-1] - '0' == i)
      {
        new_vec.push_back(vec[vec_pos]);
      }
    }
  }

  return new_vec;
}

vector<int> radix_lsd_sort(vector<int> arr)
{
  int longest_num = 1;

  for (int i = 0; i < arr.size(); i++)
  {
    int val = arr[i];
    int len = 0;

    while (val != 0)
    {
      val /= 10;
      len += 1;
    }

    if (len > longest_num)
    {
      longest_num = len;
    }
  }

  for (int i = longest_num; i > 0; i--) {
    arr = bucket(arr, i, longest_num);

    stringstream ss;
    ss << longest_num - i;
    string i_s = ss.str();

    draw_vector(arr, "lsd" + string(4 - i_s.length(), '0') + i_s);
  }

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
