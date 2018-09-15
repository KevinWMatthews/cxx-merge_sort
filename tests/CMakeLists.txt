add_executable(test_merge_sort
    test_merge_sort.cpp
)
target_link_libraries(test_merge_sort
    PRIVATE MergeSort::MergeSort
    PRIVATE GTest::GTest GTest::Main
)
add_test(
    NAME test_merge_sort
    COMMAND test_merge_sort
)
