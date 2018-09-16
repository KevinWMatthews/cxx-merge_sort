#include "merge_sort.h"
#include "gtest/gtest.h"

#include <algorithm>

using namespace std;

class MergeSortZeroElementTest : public ::testing::Test
{
protected:
    using data_type = array<int, 0>;
};

TEST_F(MergeSortZeroElementTest, DoNotFailWithEmptyArray)
{
    data_type expected = {};
    data_type actual   = {};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}


class MergeSortOneElementTest : public ::testing::Test
{
protected:
    using data_type = array<int, 1>;
};

TEST_F(MergeSortOneElementTest, ArrayWithOneElementIsAlreadySorted)
{
    data_type expected = {0};
    data_type actual   = {0};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}


class MergeSortTwoElementTest : public ::testing::Test
{
protected:
    using data_type = array<int, 2>;
};

TEST_F(MergeSortTwoElementTest, ArrayWithTwoIdenticalElementsIsAlreadySorted)
{
    data_type expected = {0, 0};
    data_type actual   = {0, 0};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortTwoElementTest, ArrayWithTwoSortedElementsIsStillSorted)
{
    data_type expected = {0, 1};
    data_type actual   = {0, 1};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortTwoElementTest, ArrayWithTwoUnsortedElementsGetsSorted)
{
    data_type expected = {0, 1};
    data_type actual   = {1, 0};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

class MergeSortThreeElementTest : public ::testing::Test
{
protected:
    using data_type = array<int, 3>;
};


TEST_F(MergeSortThreeElementTest, ArrayWithThreeSortedElementsStaysSorted)
{
    data_type expected = {0, 1, 2};
    data_type actual   = {0, 1, 2};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortThreeElementTest, ArrayWithThreeSortedElementsStaysSorted2)
{
    data_type expected = {10, 10, 12};
    data_type actual   = {10, 10, 12};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortThreeElementTest, ArrayWithThreeSortedElementsStaysSorted3)
{
    data_type expected = {10, 12, 12};
    data_type actual   = {10, 12, 12};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortThreeElementTest, ArrayWithThreeUnSortedElementsSwapsLastElements)
{
    data_type expected = {10, 11, 12};
    data_type actual   = {10, 12, 11};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortThreeElementTest, ArrayWithThreeUnSortedElementsSwapsFirstElements)
{
    data_type expected = {10, 11, 12};
    data_type actual   = {11, 10, 12};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortThreeElementTest, ArrayWithThreeUnSortedElementsSwapsAllElements)
{
    data_type expected = {10, 11, 12};
    data_type actual   = {12, 11, 10};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

class MergeSortFourElementTest : public ::testing::Test
{
protected:
    using data_type = array<int, 4>;
};

TEST_F(MergeSortFourElementTest, SortedElementsRemainSorted)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {10, 11, 12, 13};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, SwapSortedFirstAndLastPair)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {12, 13, 10, 11};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, SwapUnsortedFirstAndLastPair)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {11, 10, 13, 12};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, SwapIdenticalFirstAndLastPair)
{
    data_type expected = {10, 10, 12, 12};
    data_type actual   = {12, 12, 10, 10};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, SwapMiddlePair)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {10, 12, 11, 13};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}

TEST_F(MergeSortFourElementTest, WorstCase)
{
    data_type expected = {10, 11, 12, 13};
    data_type actual   = {13, 12, 11, 10};
    MergeSort<data_type> merge_sort = {actual};
    merge_sort.sort();
    ASSERT_EQ(expected, actual);
}
