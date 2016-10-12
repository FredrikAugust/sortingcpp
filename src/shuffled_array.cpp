#include <iostream>
#include <vector>
#include <algorithm>
#include "sorthelpers.h"

std::vector<int> shuffled_array(int size)
{
  std::vector<int> tmp_arr;

  for (int i = 1; i <= size; i++)
  {
    tmp_arr.push_back(i);
  }

  random_shuffle(std::begin(tmp_arr), std::end(tmp_arr));

  return tmp_arr;
}
