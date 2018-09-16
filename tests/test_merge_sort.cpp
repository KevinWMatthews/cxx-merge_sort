#include "merge_sort.h"
#include "gtest/gtest.h"

#include <algorithm>

using namespace std;

TEST(TestMergeSort, DoNotFailWithEmptyArray)
{
    array<int, 0> data = {};
    MergeSort<array<int, 0>> merge_sort = {data};
    merge_sort.sort();
    ASSERT_TRUE( is_sorted(data.cbegin(), data.cend()) );
}

TEST(TestMergeSort, ArrayWithOneElementIsAlreadySorted)
{
    array<int, 1> data = {0};
    MergeSort<array<int, 1>> merge_sort = {data};
    merge_sort.sort();
    ASSERT_TRUE( is_sorted(data.cbegin(), data.cend()) );
}

TEST(TestMergeSort, ArrayWithTwoIdenticalElementsIsAlreadySorted)
{
    array<int, 2> data = {0, 0};
    MergeSort<array<int, 2>> merge_sort = {data};
    merge_sort.sort();
    ASSERT_TRUE( is_sorted(data.cbegin(), data.cend()) );
}

TEST(TestMergeSort, ArrayWithTwoSortedElementsIsStillSorted)
{
    array<int, 2> expected = {0, 1};
    array<int, 2> actual = {0, 1};
    MergeSort<array<int, 2>> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST(TestMergeSort, ArrayWithTwoUnsortedElementsGetsSorted)
{
    array<int, 2> expected = {0, 1};
    array<int, 2> actual = {1, 0};
    MergeSort<array<int, 2>> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}
