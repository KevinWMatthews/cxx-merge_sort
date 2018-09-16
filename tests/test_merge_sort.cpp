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

TEST(TestMergeSort, ArrayWithThreeSortedElementsStaysSorted)
{
    array<int, 3> expected = {0, 1, 2};
    array<int, 3> actual = {0, 1, 2};
    MergeSort<array<int, 3>> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST(TestMergeSort, ArrayWithThreeSortedElementsStaysSorted2)
{
    array<int, 3> expected = {10, 10, 12};
    array<int, 3> actual = {10, 10, 12};
    MergeSort<array<int, 3>> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST(TestMergeSort, ArrayWithThreeSortedElementsStaysSorted3)
{
    array<int, 3> expected = {10, 12, 12};
    array<int, 3> actual = {10, 12, 12};
    MergeSort<array<int, 3>> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST(TestMergeSort, ArrayWithThreeUnSortedElementsSwapsLastElements)
{
    array<int, 3> expected = {10, 11, 12};
    array<int, 3> actual = {10, 12, 11};
    MergeSort<array<int, 3>> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

// This needs a recursive sort?
TEST(DISABLED_TestMergeSort, ArrayWithThreeUnSortedElementsSwapsFirstElements)
{
    array<int, 3> expected = {10, 11, 12};
    array<int, 3> actual = {11, 10, 12};
    MergeSort<array<int, 3>> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

// This needs a recursive sort?
TEST(DISABLED_TestMergeSort, ArrayWithThreeUnSortedElementsSwapsAllElements)
{
    array<int, 3> expected = {10, 11, 12};
    array<int, 3> actual = {12, 11, 10};
    MergeSort<array<int, 3>> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

class MergeSortFourElementTest : public ::testing::Test
{
protected:
    typedef array<int, 4> type;
};

TEST_F(MergeSortFourElementTest, SortedElementsRemainSorted)
{
    type expected = {10, 11, 12, 13};
    type actual =   {10, 11, 12, 13};
    MergeSort<type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, SwapSortedFirstAndLastPair)
{
    type expected = {10, 11, 12, 13};
    type actual =   {12, 13, 10, 11};
    MergeSort<type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, DISABLED_SwapUnsortedFirstAndLastPair)
{
    type expected = {10, 11, 12, 13};
    type actual =   {11, 10, 13, 12};
    MergeSort<type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, SwapIdenticalFirstAndLastPair)
{
    type expected = {10, 10, 12, 12};
    type actual =   {12, 12, 10, 10};
    MergeSort<type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, SwapMiddlePair)
{
    type expected = {10, 11, 12, 13};
    type actual =   {10, 12, 11, 13};
    MergeSort<type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}
