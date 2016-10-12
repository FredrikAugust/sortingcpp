cmake_minimum_required (VERSION 3.5)
project (SortingAlgorithms)
find_package(ImageMagick COMPONENTS Magick++)

include_directories(src/)
set(BUBBLE_S src/bubble.cpp src/sorthelpers.h src/imagery.cpp
  src/shuffled_array.cpp)
set(LSD_S src/radix_lsd.cpp src/sorthelpers.h src/imagery.cpp
  src/shuffled_array.cpp)

add_executable(SortBubble ${BUBBLE_S})
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(SortBubble ${ImageMagick_LIBRARIES})

add_executable(SortLSD ${LSD_S})
include_directories(${ImageMagick_INCLUDE_DIRSj})
target_link_libraries(SortLSD ${ImageMagick_LIBRARIES})
