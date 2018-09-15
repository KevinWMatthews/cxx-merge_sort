add_library(merge_sort
    merge_sort.cpp
)
target_include_directories(merge_sort
    PUBLIC "${CMAKE_HOME_DIRECTORY}/include"
)
add_library(MergeSort::MergeSort ALIAS merge_sort)
