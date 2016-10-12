cmake_minimum_required (VERSION 3.5)
project (SortingAlgorithms)
find_package(ImageMagick COMPONENTS Magick++)

include_directories(src/)
set(SOURCES src/bubble.cpp src/sorthelpers.h src/imagery.cpp)

add_executable(SortBubble ${SOURCES})
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(SortBubble ${ImageMagick_LIBRARIES})
